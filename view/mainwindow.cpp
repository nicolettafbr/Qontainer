#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent): QWidget(parent) {
    QString filename=aperturaFile();
    while(filename.isEmpty()||(database::controllo(filename.toStdString())==0)) {
        QMessageBox messaggioErrore;
        messaggioErrore.setText("File non valido!");
        QPushButton* bottoneSi=messaggioErrore.addButton(tr("Riprova"), QMessageBox::YesRole);
        messaggioErrore.setDefaultButton(bottoneSi);
        messaggioErrore.exec();
        filename=aperturaFile();
    }
    db = new database(filename.toStdString(),',');
    db->load(contenuto);

    setFixedSize(600,600);
    setFocusPolicy(Qt::StrongFocus);
    setGeometry(0,0,600,600);
    this->setWindowTitle("Qontainer di Nicoletta Fabro");

    layout = new QVBoxLayout();
    layout->setObjectName("layout");

    titoloFinestra = new QLabel();
    titoloFinestra->setScaledContents(true);
    QPixmap logo(":/view/images/qontainer.png");
    titoloFinestra->setPixmap(logo);
    titoloFinestra->setMaximumSize(600,126);
    titoloFinestra->setAlignment(Qt::AlignCenter);

    layout->addWidget(titoloFinestra);

    boxBottoni=new QHBoxLayout();
    bottoneAggiungi=new QPushButton(this);
    bottoneAggiungi->setText("Aggiungi");
    boxBottoni->addWidget(bottoneAggiungi);
    bottoneVisualizza=new QPushButton(this);
    bottoneVisualizza->setText("Visualizza");
    boxBottoni->addWidget(bottoneVisualizza);
    bottoneRicerca=new QPushButton(this);
    bottoneRicerca->setText("Cerca");
    boxBottoni->addWidget(bottoneRicerca);
    bottoneGestisci=new QPushButton(this);
    bottoneGestisci->setText("Gestisci");
    boxBottoni->addWidget(bottoneGestisci);
    layout->addLayout(boxBottoni);

    pagineDaVisualizzare=new QStackedWidget();
    inizializzaPagine(pagineDaVisualizzare);
    layout->addWidget(pagineDaVisualizzare);

    connect (bottoneAggiungi, SIGNAL(clicked()), this, SLOT(bottoneAggiungiCliccato()));
    connect (bottoneVisualizza, SIGNAL(clicked()), this, SLOT(bottoneVisualizzaCliccato()));
    connect (bottoneRicerca, SIGNAL(clicked()), this, SLOT(bottoneRicercaCliccato()));
    connect (bottoneGestisci, SIGNAL(clicked()), this, SLOT(bottoneGestisciCliccato()));

    this->setLayout(layout);

}

QString mainwindow::aperturaFile() {
    return QFileDialog::getOpenFileName(this,"Carica file dati",QDir::homePath(),"text (*.txt)");
}

void mainwindow::bottoneAggiungiCliccato() {
    eliminaWidget();
    pagineDaVisualizzare->setCurrentIndex(0);
}

void mainwindow::bottoneRicercaCliccato() {
    eliminaWidget();
    pagineDaVisualizzare->setCurrentIndex(1);
}

void mainwindow::bottoneVisualizzaCliccato() {
    eliminaWidget();
    visualizza* paginaVisualizzazione=new visualizza(&contenuto,this);
    pagineDaVisualizzare->addWidget(paginaVisualizzazione);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(paginaVisualizzazione));
}

void mainwindow::bottoneGestisciCliccato() {
    eliminaWidget();
    gestisci* paginaGestione=new gestisci(&contenuto,this);
    pagineDaVisualizzare->addWidget(paginaGestione);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(paginaGestione));
}

void mainwindow::inizializzaPagine(QStackedWidget* pagineDaVisualizzare) {
    paginaAggiunta=new aggiungihome(&contenuto,this);
    paginaRicerca=new cerca(&contenuto,this);

    pagineDaVisualizzare->addWidget(paginaAggiunta);            //->0
    pagineDaVisualizzare->addWidget(paginaRicerca);             //->1
}

void mainwindow::aggiuntaAvanzata(int i) {
    eliminaWidget();
    aggiungi* aggiuntaAvanzata=new aggiungi(&contenuto,i,this);
    pagineDaVisualizzare->addWidget(aggiuntaAvanzata);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(aggiuntaAvanzata));
}

void mainwindow::risultatoAggiunta() {
    eliminaWidget();
    risultatoaggiunta* elementoAggiunto= new risultatoaggiunta(this);
    pagineDaVisualizzare->addWidget(elementoAggiunto);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(elementoAggiunto));
}

void mainwindow::modificaEsercizio(esercizio* e) {
    eliminaWidget();
    modifica* modificaElemento=new modifica(e,this);
    pagineDaVisualizzare->addWidget(modificaElemento);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(modificaElemento));
}

void mainwindow::risultatoEliminazione() {
    eliminaWidget();
    risultatoeliminazione* elementoEliminato=new risultatoeliminazione(this);
    pagineDaVisualizzare->addWidget(elementoEliminato);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(elementoEliminato));
}

void mainwindow::risultatoModifica() {
    eliminaWidget();
    risultatomodifica* elementoModificato=new risultatomodifica(this);
    pagineDaVisualizzare->addWidget(elementoModificato);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(elementoModificato));
}

void mainwindow::risultatoRicerca(std::string nome, QDate data) {
    eliminaWidget();
    esercizio* daCercare=new esercizio(nome,data.day(),data.month(),data.year());
    vector<esercizio*> risultatoRicerca=contenuto.search(daCercare);
    risultatoricerca* elementoCercato=new risultatoricerca(&contenuto,risultatoRicerca,this);
    pagineDaVisualizzare->addWidget(elementoCercato);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(elementoCercato));
}

void mainwindow::visualizzaEsercizio(esercizio* e) {
    eliminaWidget();
    visualizzaesercizio* esercizioDaVisualizzare= new visualizzaesercizio(e,this);
    pagineDaVisualizzare->addWidget(esercizioDaVisualizzare);
    pagineDaVisualizzare->setCurrentIndex(pagineDaVisualizzare->indexOf(esercizioDaVisualizzare));
}

void mainwindow::eliminaWidget() {
    if(pagineDaVisualizzare->currentIndex() !=0 && pagineDaVisualizzare->currentIndex() !=1){
            QWidget* current=pagineDaVisualizzare->currentWidget();
            pagineDaVisualizzare->removeWidget(current);
            delete current;
    }
}

void mainwindow::eliminaSingoloEsercizio(esercizio* es) {
    contenuto.remove(es);
    risultatoEliminazione();
}

void mainwindow::closeEvent(QCloseEvent* event) {
    db->save(contenuto);
    event->accept();
}

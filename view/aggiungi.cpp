#include "aggiungi.h"

aggiungi::aggiungi(Container<esercizio*>* cont, int i, QWidget* parent):
    QWidget(parent), contenuto(cont) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();
    grigliaAggiunta = new QGridLayout();

    QLabel* didascalia = new QLabel();
    didascalia->setText("Categoria esercizio:");
    grigliaAggiunta->addWidget(didascalia,0,0,Qt::AlignLeft);
    sceltaCategoria = new QComboBox();
    sceltaCategoria->setMinimumWidth(350);
    sceltaCategoria->insertItem(0,tr("Forza"));
    sceltaCategoria->setItemIcon(0,QIcon(":/view/images/icons/dumbbell.png"));
    sceltaCategoria->insertItem(1,tr("Ipertrofia"));
    sceltaCategoria->setItemIcon(1,QIcon(":/view/images/icons/bicep.png"));
    sceltaCategoria->insertItem(2,tr("HIIT"));
    sceltaCategoria->setItemIcon(2,QIcon(":/view/images/icons/cronometro.png"));
    sceltaCategoria->insertItem(3,tr("LISS"));
    sceltaCategoria->setItemIcon(3,QIcon(":/view/images/icons/heartrate.png"));
    sceltaCategoria->setCurrentIndex(i);
    grigliaAggiunta->addWidget(sceltaCategoria,0,1,Qt::AlignLeft);

    inserisciElemento("Nome esercizio:", "Inserisci il nome", 350, grigliaAggiunta, 1);
    inserisciElemento("Data:", "D/M/YYYY", 350, grigliaAggiunta, 2);

    setTabOrder(vettoreInput[0], vettoreInput[1]);

    layout->addLayout(grigliaAggiunta);

    aggiuntaAvanzata = new QGridLayout();
    aggiungiInput(sceltaCategoria->currentIndex());
    layout->addLayout(aggiuntaAvanzata);

    grigliaBottoni=new QGridLayout();
    bottoneAggiunta = new QPushButton();
    bottoneAggiunta->setText("Aggiungi");
    bottoneAggiunta->setMaximumSize(QSize(150,40));
    bottoneAnnulla=new QPushButton();
    bottoneAnnulla->setText("Annulla");
    bottoneAnnulla->setMaximumSize(QSize(150,40));
    grigliaBottoni->addWidget(bottoneAggiunta,0,0,Qt::AlignCenter);
    grigliaBottoni->addWidget(bottoneAnnulla,0,1,Qt::AlignCenter);

    layout->addLayout(grigliaBottoni);

    this->setLayout(layout);

    connect(sceltaCategoria, SIGNAL(activated(int)), this, SLOT(aggiungiInput(int)));
    connect(bottoneAggiunta, SIGNAL(clicked()), this, SLOT(schiacciaAggiungi()));
    connect(this, SIGNAL(invioAggiunta()), parent, SLOT(risultatoAggiunta()));
    connect(bottoneAnnulla, SIGNAL(clicked()), parent, SLOT(bottoneAggiungiCliccato()));

}

void aggiungi::aggiungiInput(int type) {
     QLayoutItem* item;
     while((item=aggiuntaAvanzata->takeAt(0))) {
         if(dynamic_cast<QWidgetItem*>(item)) {
             QWidget* currentWidget=static_cast<QWidget*>(item->widget());
             currentWidget->hide();
             aggiuntaAvanzata->removeWidget(currentWidget);
             if(dynamic_cast<QLineEdit*>(item->widget())) {
                 QLineEdit* currentLineEdit=static_cast<QLineEdit*>(item->widget());
                 for(auto it=vettoreInput.begin(); it!=vettoreInput.end(); ++it) {
                     if(*it==currentLineEdit) {
                         vettoreInput.erase(it);
                         --it;
                     }
                 }
             } else delete currentWidget;
        }
     }if (type==0) { //forza
          inserisciElemento("Serie:", "Inserisci le serie", 350, aggiuntaAvanzata, 0);
          inserisciElemento("Ripetizioni:", "Inserisci il numero di ripetizioni", 350, aggiuntaAvanzata, 1);
          inserisciElemento("Peso:", "Inserisci il peso in kg", 350, aggiuntaAvanzata, 2);
     }if (type==1) { //ipertrofia
         inserisciElemento("Serie:", "Inserisci il numero di serie", 350, aggiuntaAvanzata, 0);
         inserisciElemento("Ripetizioni:", "Inserisci il numero di ripetizioni", 350, aggiuntaAvanzata, 1);
         inserisciElemento("Recupero:", "H:M:S", 350, aggiuntaAvanzata, 2);
     }if (type==2) { //hiit
         inserisciElemento("Bpm:", "Inserisci la tua frequenza cardiaca (in media)", 350, aggiuntaAvanzata, 0);
         inserisciElemento("Età:", "Inserisci la tua età", 350, aggiuntaAvanzata, 1);
         inserisciElemento("Numero intervalli:", "Inserisci il numero di intervalli di lavoro", 350, aggiuntaAvanzata, 2);
         inserisciElemento("Durata intervalli:", "H:M:S", 350, aggiuntaAvanzata, 3);
         inserisciElemento("Riposo:", "H:M:S", 350, aggiuntaAvanzata, 4);
     }if (type==3) { //liss
         inserisciElemento("Bpm:", "Inserisci la tua frequenza cardiaca (in media)", 350, aggiuntaAvanzata, 0);
         inserisciElemento("Età:", "Inserisci la tua età", 350, aggiuntaAvanzata, 1);
         inserisciElemento("Durata:", "H:M:S", 350, aggiuntaAvanzata, 2);
     }
    setTabOrder(vettoreInput[1], vettoreInput[2]);
    setTabOrder(vettoreInput[2], vettoreInput[3]);
    setTabOrder(vettoreInput[3], vettoreInput[4]);
}

void aggiungi::inserisciElemento(QString nome, QString placeholder, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label=new QLabel(this);
    label->setText(nome);

    QLineEdit* box=new QLineEdit(this);
    box->setFixedWidth(lunghezza);
    box->setPlaceholderText(placeholder);
    vettoreInput.push_back(box);

    griglia->addWidget(label,riga,0,Qt::AlignLeft);
    griglia->addWidget(box,riga,1,Qt::AlignLeft);

}

void aggiungi::schiacciaAggiungi() {
        aggiungiEsercizio();
        emit invioAggiunta();
}

void aggiungi::aggiungiEsercizio() {
    std::string nome=vettoreInput[0]->text().toStdString();
    QDate data=QDate::fromString(vettoreInput[1]->text(),"d/M/yyyy");

    if (sceltaCategoria->currentIndex()==0) { //forza
        int serie = vettoreInput[2]->text().toInt();
        int ripetizioni = vettoreInput[3]->text().toInt();
        int peso = vettoreInput[4]->text().toInt();

        esercizio* f=new forza(nome,data.day(),data.month(),data.year(),serie,ripetizioni,peso);
        contenuto->insert(f);
    }if (sceltaCategoria->currentIndex()==1) { //ipertrofia
        int serie=vettoreInput[2]->text().toInt();
        int ripetizioni=vettoreInput[3]->text().toInt();
        QTime rec;
        rec=QTime::fromString(vettoreInput[4]->text(),"h:m:s");
        esercizio* i=new ipertrofia(nome,data.day(),data.month(),data.year(),
                                    serie,ripetizioni,rec.hour(),rec.minute(),rec.second());
        contenuto->insert(i);
    }if (sceltaCategoria->currentIndex()==2) { //hiit
        int bpm=vettoreInput[2]->text().toInt();
        int eta=vettoreInput[3]->text().toInt();
        int numInt=vettoreInput[4]->text().toInt();
        QTime interv;
        interv=QTime::fromString(vettoreInput[5]->text(),"h:m:s");
        QTime rec;
        rec=QTime::fromString(vettoreInput[6]->text(),"h:m:s");
        esercizio* h=new hiit(nome,data.day(),data.month(),data.year(),
                              bpm,eta,numInt,interv.hour(),interv.minute(),
                              interv.second(),rec.hour(),rec.minute(),rec.second());
        contenuto->insert(h);
    }if (sceltaCategoria->currentIndex()==3){ //liss
        int bpm=vettoreInput[2]->text().toInt();
        int eta=vettoreInput[3]->text().toInt();
        QTime durata;
        durata=QTime::fromString(vettoreInput[4]->text(),"h:m:s");
        esercizio* l=new liss(nome,data.day(),data.month(),data.year(),
                              bpm,eta,durata.hour(),durata.minute(),durata.second());
        contenuto->insert(l);
    }
}


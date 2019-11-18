#include "visualizzaesercizio.h"

visualizzaesercizio::visualizzaesercizio(esercizio* es, QWidget* parent):
    QWidget(parent), elementoDaVisualizzare(es) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();

    griglia = new QGridLayout;
    campiDaVisualizzare();

    layout->addLayout(griglia);

    grigliaBottoni=new QGridLayout();
    modifica=new QPushButton();
    modifica->setText("Modifica");
    elimina=new QPushButton();
    elimina->setText("Elimina");
    annulla=new QPushButton();
    annulla->setText("Annulla");
    grigliaBottoni->addWidget(modifica,0,0,Qt::AlignCenter);
    grigliaBottoni->addWidget(elimina,0,1,Qt::AlignCenter);
    grigliaBottoni->addWidget(annulla,0,2,Qt::AlignCenter);
    layout->addLayout(grigliaBottoni);

    this->setLayout(layout);

    connect(modifica, SIGNAL(clicked()), this, SLOT(schiacciaModifica()));
    connect(this, SIGNAL(inviaModifica(esercizio*)), parent, SLOT(modificaEsercizio(esercizio*)));
    connect(elimina, SIGNAL(clicked()), this, SLOT(schiacciaElimina()));
    connect(this, SIGNAL(inviaEliminazione(esercizio*)), parent, SLOT(eliminaSingoloEsercizio(esercizio*)));
    connect(annulla, SIGNAL(clicked()), parent, SLOT(bottoneAggiungiCliccato()));

}

void visualizzaesercizio::creaEntry(QString etichetta, QString valore, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label = new QLabel(this);
    label->setFixedWidth(lunghezza);
    label->setText(etichetta);

    QLabel* box = new QLabel(this);
    box->setFixedWidth(lunghezza);
    box->setText(valore);

    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);
}

void visualizzaesercizio::campiDaVisualizzare() {
    creaEntry("Nome:", QString::fromStdString(elementoDaVisualizzare->getNome()), 300, griglia, 1);
    creaEntry("Data esecuzione:", QString::fromStdString(elementoDaVisualizzare->getDataEsecuzione().dataToString()), 300, griglia, 2);
    forza* f=dynamic_cast<forza*>(elementoDaVisualizzare);
    if(f){
        creaEntry("Serie:", QString::fromStdString(std::to_string(f->getSerie())), 300, griglia, 3);
        creaEntry("Ripetizioni:", QString::fromStdString(std::to_string(f->getRipetizioni())), 300, griglia, 4);
        creaEntry("Peso:", QString::fromStdString(std::to_string(f->getPeso()))+" kg", 300, griglia, 5);
        if(f->getPeso()!=0){
            creaEntry("Il tuo massimale stimato:", QString::fromStdString(std::to_string(f->massimale()))+" kg", 300, griglia, 6);
            creaEntry("% di carico rispetto alla tua 1RM:", QString::fromStdString(std::to_string(f->percentualeCarico()))+"%", 300, griglia, 7);
        }
    }ipertrofia* i=dynamic_cast<ipertrofia*>(elementoDaVisualizzare);
    if(i){
        creaEntry("Serie:", QString::fromStdString(std::to_string(i->getSerie())), 300, griglia, 3);
        creaEntry("Ripetizioni:", QString::fromStdString(std::to_string(i->getRipetizioni())), 300, griglia, 4);
        creaEntry("Recupero:", QString::fromStdString(i->getRecupero().orarioToString()), 300, griglia, 5);
        if(i->getSerie()!=0 && i->getRipetizioni()!=0){
            creaEntry("Volume allenamento:", QString::fromStdString(std::to_string(i->volume())), 300, griglia, 6);
        }
    }hiit* h=dynamic_cast<hiit*>(elementoDaVisualizzare);
    if(h){
        creaEntry("Frequenza cardiaca di lavoro:", QString::fromStdString(std::to_string(h->getBPM()))+" bpm", 300, griglia, 3);
        creaEntry("Numero intervalli:", QString::fromStdString(std::to_string(h->getNumeroIntervalli())), 300, griglia, 4);
        creaEntry("Durata intervalli:", QString::fromStdString(h->getDurataIntervalli().orarioToString()), 300, griglia, 5);
        creaEntry("Durata riposo:", QString::fromStdString(h->getRiposo().orarioToString()), 300, griglia, 6);
        if(h->getDurataIntervalli()!=0 && h->getNumeroIntervalli()!=0){
            creaEntry("Durata complessiva allenamento:", QString::fromStdString(h->durataAllenamento().orarioToString()), 300, griglia, 7);
        }
        creaEntry("FC massima stimata:", QString::fromStdString(std::to_string(h->FCmassima()))+" bpm", 300, griglia, 8);
    }liss* l=dynamic_cast<liss*>(elementoDaVisualizzare);
    if(l){
        creaEntry("Frequenza cardiaca di lavoro:", QString::fromStdString(std::to_string(l->getBPM())), 300, griglia, 3);
        creaEntry("Durata:", QString::fromStdString(l->getDurata().orarioToString()), 300, griglia, 4);
        if(l->getDurata()!=0) creaEntry("Durata complessiva allenamento:", QString::fromStdString(l->durataAllenamento().orarioToString()), 300, griglia, 5);
        creaEntry("FC massima stimata:", QString::fromStdString(std::to_string(l->FCmassima()))+" bpm", 300, griglia, 6);

    }
}

void visualizzaesercizio::schiacciaModifica() {
    emit inviaModifica(elementoDaVisualizzare);
}

void visualizzaesercizio::schiacciaElimina() {
    QMessageBox messaggioEliminazione;
    messaggioEliminazione.setText("Sei sicuro di voler eliminare l'esercizio?");
    QPushButton* bottoneSi= messaggioEliminazione.addButton(tr("Sì"), QMessageBox::YesRole);
    QPushButton* bottoneNo = messaggioEliminazione.addButton(tr("No"), QMessageBox::NoRole);
    messaggioEliminazione.setDefaultButton(bottoneNo);
    messaggioEliminazione.exec();
    if(messaggioEliminazione.clickedButton() == bottoneSi){
        eliminaEsercizio();
    }
}

void visualizzaesercizio::eliminaEsercizio() {
   emit inviaEliminazione(elementoDaVisualizzare);
}

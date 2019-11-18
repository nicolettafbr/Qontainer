#include "modifica.h"

modifica::modifica(esercizio* e, QWidget* parent):
    QWidget(parent), es(e) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();
    layout->setObjectName("layout");

    grigliaModifica=new QGridLayout();
    campiDaModificare();
    layout->addLayout(grigliaModifica);

    grigliaBottoni=new QGridLayout();
    bottoneAnnulla=new QPushButton();
    bottoneAnnulla->setText("Annulla");
    bottoneModifica=new QPushButton();
    bottoneModifica->setText("Modifica");
    grigliaBottoni->addWidget(bottoneModifica,0,0,Qt::AlignCenter);
    grigliaBottoni->addWidget(bottoneAnnulla,0,1,Qt::AlignCenter);
    layout->addLayout(grigliaBottoni);

    this->setLayout(layout);

    connect(bottoneModifica, SIGNAL(clicked()), this, SLOT(schiacciaModifica()));
    connect(this, SIGNAL(inviaModifica()), parent, SLOT(risultatoModifica()));
    connect(bottoneAnnulla, SIGNAL(clicked()), parent, SLOT(bottoneAggiungiCliccato()));
}

void modifica::creaEntry(QString etichetta, QString valoreCorrente, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label = new QLabel(this);
    label->setText(etichetta);

    QLineEdit* box = new QLineEdit(this);
    box->setFixedWidth(lunghezza);
    box->setText(valoreCorrente);
    vettoreModifiche.push_back(box);

    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);

}

void modifica::campiDaModificare() {
    creaEntry("Nome:", QString::fromStdString(es->getNome()), 300, grigliaModifica, 1);
    creaEntry("Data esecuzione:", QString::fromStdString(es->getDataEsecuzione().dataToString()), 300, grigliaModifica, 2);

    forza* f=dynamic_cast<forza*>(es);
    if(f){
        creaEntry("Serie:", QString::fromStdString(std::to_string(f->getSerie())), 300, grigliaModifica, 3);
        creaEntry("Ripetizioni:", QString::fromStdString(std::to_string(f->getRipetizioni())), 300, grigliaModifica, 4);
        creaEntry("Peso:", QString::fromStdString(std::to_string(f->getPeso())), 300, grigliaModifica, 5);
    }ipertrofia* i=dynamic_cast<ipertrofia*>(es);
    if(i){
        creaEntry("Serie:", QString::fromStdString(std::to_string(i->getSerie())), 300, grigliaModifica, 3);
        creaEntry("Ripetizioni:", QString::fromStdString(std::to_string(i->getRipetizioni())), 300, grigliaModifica, 4);
        creaEntry("Recupero:", QString::fromStdString(i->getRecupero().orarioToString()), 300, grigliaModifica, 5);
    }hiit* h=dynamic_cast<hiit*>(es);
    if(h){
        creaEntry("BPM:", QString::fromStdString(std::to_string(h->getBPM())), 300, grigliaModifica, 3);
        creaEntry("Età:", QString::fromStdString(std::to_string(h->getEta())), 300, grigliaModifica, 4);
        creaEntry("Numero intervalli:", QString::fromStdString(std::to_string(h->getNumeroIntervalli())), 300, grigliaModifica, 5);
        creaEntry("Durata intervalli:", QString::fromStdString(h->getDurataIntervalli().orarioToString()), 300, grigliaModifica, 6);
        creaEntry("Durata recupero tra intervalli:", QString::fromStdString(h->getRiposo().orarioToString()), 300, grigliaModifica, 7);
    }liss* l=dynamic_cast<liss*>(es);
    if(l){
        creaEntry("BPM:", QString::fromStdString(std::to_string(l->getBPM())), 300, grigliaModifica, 3);
        creaEntry("Età:", QString::fromStdString(std::to_string(l->getEta())), 300, grigliaModifica, 4);
        creaEntry("Durata:", QString::fromStdString(l->getDurata().orarioToString()), 300, grigliaModifica, 5);
    }
}

void modifica::schiacciaModifica() {
    modificaElemento();
    emit inviaModifica();
}

void modifica::modificaElemento() {
    es->setNome(vettoreModifiche[0]->text().toStdString());
    std::string data=vettoreModifiche[1]->text().toStdString();
    es->setDataEsecuzione(data::stringToData(data).getGiorno(), data::stringToData(data).getMese(), data::stringToData(data).getAnno());

    forza* f=dynamic_cast<forza*>(es);
    if(f){
        f->setSerie(vettoreModifiche[2]->text().toInt());
        f->setRipetizioni(vettoreModifiche[3]->text().toInt());
        f->setPeso(vettoreModifiche[4]->text().toInt());
    }ipertrofia* i=dynamic_cast<ipertrofia*>(es);
    if(i){
        i->setSerie(vettoreModifiche[2]->text().toInt());
        i->setRipetizioni(vettoreModifiche[3]->text().toInt());
        std::string orario=vettoreModifiche[4]->text().toStdString();
        i->setRecupero(orario::stringToOrario(orario).getSec());
    }hiit* h=dynamic_cast<hiit*>(es);
    if(h){
        h->setBPM(vettoreModifiche[2]->text().toInt());
        h->setEta(vettoreModifiche[3]->text().toInt());
        h->setNumeroIntervalli(vettoreModifiche[4]->text().toInt());
        std::string intervalli=vettoreModifiche[5]->text().toStdString();
        h->setDurataIntervalli(orario::stringToOrario(intervalli).getSec());
        std::string riposo=vettoreModifiche[6]->text().toStdString();
        h->setRiposo(orario::stringToOrario(riposo).getSec());
    }liss* l=dynamic_cast<liss*>(es);
    if(l){
        l->setBPM(vettoreModifiche[2]->text().toInt());
        l->setEta(vettoreModifiche[3]->text().toInt());
        std::string durata=vettoreModifiche[4]->text().toStdString();
        l->setDurata(orario::stringToOrario(durata).getSec());
    }
}

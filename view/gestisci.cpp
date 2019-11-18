#include "gestisci.h"

gestisci::gestisci(Container<esercizio*>* cont, QWidget* parent):
    QWidget(parent), contenuto(cont) {
    layout = new QVBoxLayout(this);
    layout->setObjectName("layout");

    didascalia=new QLabel();
    didascalia->setText("Seleziona la categoria dell'esercizio che vuoi modificare/eliminare:");
    didascalia->setMaximumHeight(15);
    layout->addWidget(didascalia);

    corpo=new QGridLayout();

    bottoneForza=new QPushButton();
    bottoneForza->setText("Forza");
    bottoneForza->setIcon(QIcon(":/view/images/icons/dumbbell_w.png"));
    corpo->addWidget(bottoneForza,0,0);

    bottoneIpertrofia=new QPushButton();
    bottoneIpertrofia->setText("Ipertrofia");
    bottoneIpertrofia->setIcon(QIcon(":/view/images/icons/bicep_w.png"));
    corpo->addWidget(bottoneIpertrofia,1,0);

    bottoneHIIT=new QPushButton();
    bottoneHIIT->setText("HIIT");
    bottoneHIIT->setIcon(QIcon(":/view/images/icons/cronometro_w.png"));
    corpo->addWidget(bottoneHIIT,2,0);

    bottoneLISS=new QPushButton();
    bottoneLISS->setText("LISS");
    bottoneLISS->setIcon(QIcon(":/view/images/icons/heartrate_w.png"));
    corpo->addWidget(bottoneLISS,3,0);

    boxEsercizi=new QVBoxLayout();

    corpo->addLayout(boxEsercizi,0,1,5,3);
    layout->addLayout(corpo);
    this->setLayout(layout);

    connect(bottoneForza, SIGNAL(clicked()), this, SLOT(bottoneForzaCliccato()));
    connect(bottoneIpertrofia, SIGNAL(clicked()), this, SLOT(bottoneIpertrofiaCliccato()));
    connect(bottoneHIIT, SIGNAL(clicked()), this, SLOT(bottoneHIITCliccato()));
    connect(bottoneLISS, SIGNAL(clicked()), this, SLOT(bottoneLISSCliccato()));
    connect(this, SIGNAL(inviaModifica(esercizio*)), parent, SLOT(modificaEsercizio(esercizio*)));
    connect(this, SIGNAL(inviaEliminazione()), parent, SLOT(risultatoEliminazione()));
}

void gestisci::bottoneForzaCliccato() { emit visualizzaEsercizi(1); }

void gestisci::bottoneIpertrofiaCliccato() { emit visualizzaEsercizi(2); }

void gestisci::bottoneHIITCliccato() { emit visualizzaEsercizi(3); }

void gestisci::bottoneLISSCliccato() { emit visualizzaEsercizi(4); }

void gestisci::creaEsercizio(int i, int pos, const Container<esercizio*>::Iterator& it) {
    QLabel* nome=new QLabel();
    nome->setText(QString::fromStdString((*contenuto)[it]->getNome()));
    QLabel* data=new QLabel();
    data->setText(QString::fromStdString((*contenuto)[it]->getDataEsecuzione().dataToString()));
    bottoneModifica=new QPushButton();
    bottoneModifica->setText("Modifica");
    bottoneModifica->setStyleSheet("background-color: grey; padding: 4px; border-radius: 2px;");
    bottoneModifica->setMaximumWidth(90);
    bottoneModifica->setObjectName(QString::number(pos));

    bottoneElimina=new QPushButton();
    bottoneElimina->setText("Elimina");
    bottoneElimina->setStyleSheet("background-color: grey; padding: 4px; border-radius: 2px;");
    bottoneElimina->setMaximumWidth(90);
    bottoneElimina->setObjectName(QString::number(pos));

    mostraEsercizi->addWidget(nome,i,0);
    mostraEsercizi->addWidget(data,i,1);
    mostraEsercizi->addWidget(bottoneModifica,i,2);
    mostraEsercizi->addWidget(bottoneElimina,i,3);

    connect(bottoneModifica, SIGNAL(clicked()), this, SLOT(schiacciaModifica()));
    connect(bottoneElimina, SIGNAL(clicked()), this, SLOT(schiacciaElimina()));

    ++i;
}

void gestisci::visualizzaEsercizi(int type) {
    eliminaContenuto();
    mostraEsercizi=new QGridLayout();

    QWidget* sfondo=new QWidget();
    sfondo->setStyleSheet("background-color: #fff;");
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setWidget(sfondo);
    boxEsercizi->addWidget(scrollArea);

    int i=0;
    if(type==1) {
        int pos=0;
        for(auto it=contenuto->begin(); it!=contenuto->end(); ++it) {
            if(dynamic_cast<forza*>((*contenuto)[it])){
                creaEsercizio(i,pos,it);
                ++i;
            } ++pos;
        }
    }if(type==2) {
        int pos=0;
        for(auto it=contenuto->begin(); it!=contenuto->end(); ++it) {
            if(dynamic_cast<ipertrofia*>((*contenuto)[it])){
                creaEsercizio(i,pos,it);
                ++i;
            } ++pos;
        }
    }if(type==3) {
        int pos=0;
        for(auto it=contenuto->begin(); it!=contenuto->end(); ++it) {
            if(dynamic_cast<hiit*>((*contenuto)[it])){
                creaEsercizio(i,pos,it);
                ++i;
            } ++pos;
        }
    }if(type==4) {
        int pos=0;
        for(auto it=contenuto->begin(); it!=contenuto->end(); ++it) {
            if(dynamic_cast<liss*>((*contenuto)[it])){
                creaEsercizio(i,pos,it);
                ++i;
            } ++pos;
        }
    } sfondo->setLayout(mostraEsercizi);
}

void gestisci::eliminaContenuto() {
    if(boxEsercizi) {
        QLayoutItem* item;
        while ((item=boxEsercizi->takeAt(0))) {
            if(dynamic_cast<QWidgetItem*>(item) && !(dynamic_cast<QScrollArea*>(item))) {
                QWidget* widgetCorrente=static_cast<QWidget*>(item->widget());
                delete widgetCorrente;
            }
        }
    }
}

void gestisci::eliminaEsercizio() {
    QPushButton* bottoneElimina=dynamic_cast<QPushButton*>(sender());
    if (bottoneElimina) {
        int indice=bottoneElimina->objectName().toInt(), i=0;
        for(auto it=contenuto->begin(); it!=contenuto->end() && i<=indice; ++it){
            if(i==indice) contenuto->remove((*contenuto)[it]);
            ++i;
        }
    }
}

void gestisci::schiacciaModifica() {
    QPushButton* bottoneModifica=dynamic_cast<QPushButton*>(sender());
        if (bottoneModifica) {
            int indice=bottoneModifica->objectName().toInt(), i=0;
            esercizio* esercizioDaModificare=nullptr;
            for(auto it=contenuto->begin(); it!=contenuto->end() && i<=indice; ++it){
                if(i==indice) esercizioDaModificare=(*contenuto)[it];
                ++i;
            }
            emit inviaModifica(esercizioDaModificare);
        }
}

void gestisci::schiacciaElimina() {
    QMessageBox messaggioEliminazione;
    messaggioEliminazione.setText("Sei sicuro di voler eliminare l'esercizio?");
    QPushButton* bottoneSi=messaggioEliminazione.addButton(tr("Sì"), QMessageBox::YesRole);
    QPushButton* bottoneNo=messaggioEliminazione.addButton(tr("No"), QMessageBox::NoRole);
    messaggioEliminazione.setDefaultButton(bottoneNo);
    messaggioEliminazione.exec();
    if(messaggioEliminazione.clickedButton()==bottoneSi){
        eliminaEsercizio();
        emit inviaEliminazione();
    }
}

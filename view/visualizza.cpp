#include "visualizza.h"

visualizza::visualizza(Container<esercizio*>* cont, QWidget* parent):
    QWidget(parent), contenuto(cont) {
    layout = new QVBoxLayout(this);
    layout->setObjectName("layout");

    didascalia=new QLabel();
    didascalia->setText("Seleziona la categoria dell'esercizio che vuoi visualizzare:");
    didascalia->setMaximumHeight(15);
    layout->addWidget(didascalia);

    corpo = new QGridLayout();

    bottoneForza = new QPushButton();
    bottoneForza->setText("Forza");
    bottoneForza->setIcon(QIcon(":/view/images/icons/dumbbell_w.png"));
    corpo->addWidget(bottoneForza,0,0);

    bottoneIpertrofia = new QPushButton();
    bottoneIpertrofia->setText("Ipertrofia");
    bottoneIpertrofia->setIcon(QIcon(":/view/images/icons/bicep_w.png"));
    corpo->addWidget(bottoneIpertrofia,1,0);

    bottoneHIIT = new QPushButton();
    bottoneHIIT->setText("HIIT");
    bottoneHIIT->setIcon(QIcon(":/view/images/icons/cronometro_w.png"));
    corpo->addWidget(bottoneHIIT,2,0);

    bottoneLISS = new QPushButton();
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
    connect(this, SIGNAL(inviaVisualizza(esercizio*)), parent, SLOT(visualizzaEsercizio(esercizio*)));
}

void visualizza::bottoneForzaCliccato() { emit visualizzaEsercizi(1); }

void visualizza::bottoneIpertrofiaCliccato() { emit visualizzaEsercizi(2); }

void visualizza::bottoneHIITCliccato() { emit visualizzaEsercizi(3); }

void visualizza::bottoneLISSCliccato() { emit visualizzaEsercizi(4); }

void visualizza::creaEsercizio(int i, int pos, const Container<esercizio*>::Iterator& it) {
    QLabel* nome=new QLabel();
    nome->setText(QString::fromStdString((*contenuto)[it]->getNome()));
    QLabel* data=new QLabel();
    data->setText(QString::fromStdString((*contenuto)[it]->getDataEsecuzione().dataToString()));
    QPushButton* bottoneVisualizza=new QPushButton();
    bottoneVisualizza->setText("Visualizza");
    bottoneVisualizza->setStyleSheet("background-color: grey; padding: 4px; border-radius: 2px;");
    bottoneVisualizza->setMaximumWidth(90);
    bottoneVisualizza->setObjectName(QString::number(pos));

    mostraEsercizi->addWidget(nome,i,0);
    mostraEsercizi->addWidget(data,i,1);
    mostraEsercizi->addWidget(bottoneVisualizza,i,2);

    connect(bottoneVisualizza, SIGNAL(clicked()), this, SLOT(schiacciaVisualizza()));

    ++i;
}

void visualizza::visualizzaEsercizi(int type) {
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

void visualizza::eliminaContenuto() {
    if(boxEsercizi) {
        QLayoutItem* item;
        while ((item = boxEsercizi->takeAt(0))) {
            if(dynamic_cast<QWidgetItem*>(item) && !(dynamic_cast<QScrollArea*>(item))) {
                QWidget* widgetCorrente = static_cast<QWidget*>(item->widget());
                delete widgetCorrente;
            }
        }
    }
}

void visualizza::schiacciaVisualizza() {
    QPushButton* bottoneVisualizza = dynamic_cast<QPushButton*>(sender());
        if (bottoneVisualizza) {
            int indice = bottoneVisualizza->objectName().toInt(), i=0;
            esercizio* esercizioDaVisualizzare = nullptr;
            for(auto it=contenuto->begin(); it!=contenuto->end() && i<=indice; ++it){
                if(i==indice) esercizioDaVisualizzare=(*contenuto)[it];
                ++i;
            }
            emit inviaVisualizza(esercizioDaVisualizzare);
        }
}

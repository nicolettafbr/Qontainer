#include "aggiungihome.h"

aggiungihome::aggiungihome(Container<esercizio*>* cont, QWidget* parent): QWidget(parent), contenuto(cont) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();

    didascalia = new QLabel();
    didascalia->setText("Scegli il tipo di esercizio che vuoi inserire:");
    layout->addWidget(didascalia,1,Qt::AlignCenter);

    grigliaBottoni = new QGridLayout();

    bottoneForza = new QPushButton();
    bottoneForza->setText("Forza");
    bottoneForza->setIcon(QIcon(":/view/images/icons/dumbbell_w.png"));
    bottoneForza->setObjectName("Forza");
    bottoneForza->setObjectName(QString::number(1));
    grigliaBottoni->addWidget(bottoneForza,0,0);

    bottoneIpertrofia = new QPushButton();
    bottoneIpertrofia->setText("Ipertrofia");
    bottoneIpertrofia->setIcon(QIcon(":/view/images/icons/bicep_w.png"));
    bottoneIpertrofia->setObjectName("Ipertrofia");
    bottoneIpertrofia->setObjectName(QString::number(2));
    grigliaBottoni->addWidget(bottoneIpertrofia,0,1);

    bottoneHIIT = new QPushButton();
    bottoneHIIT->setText("HIIT");
    bottoneHIIT->setIcon(QIcon(":/view/images/icons/cronometro_w.png"));
    bottoneHIIT->setObjectName("HIIT");
    bottoneHIIT->setObjectName(QString::number(3));
    grigliaBottoni->addWidget(bottoneHIIT,1,0);

    bottoneLISS = new QPushButton();
    bottoneLISS->setText("LISS");
    bottoneLISS->setIcon(QIcon(":/view/images/icons/heartrate_w.png"));
    bottoneLISS->setObjectName("LISS");
    bottoneLISS->setObjectName(QString::number(4));
    grigliaBottoni->addWidget(bottoneLISS,1,1);
    grigliaBottoni->setContentsMargins(60,0,60,100);
    grigliaBottoni->setSpacing(40);

    layout->addLayout(grigliaBottoni);
    connect(bottoneForza, SIGNAL(clicked()), this, SLOT(bottoneForzaCliccato()));
    connect(bottoneIpertrofia, SIGNAL(clicked()), this, SLOT(bottoneIpertrofiaCliccato()));
    connect(bottoneHIIT, SIGNAL(clicked()), this, SLOT(bottoneHIITCliccato()));
    connect(bottoneLISS, SIGNAL(clicked()), this, SLOT(bottoneLISSCliccato()));
    connect(this, SIGNAL(invioAggiunta(int)), parent, SLOT(aggiuntaAvanzata(int)));

    this->setLayout(layout);
}

void aggiungihome::bottoneForzaCliccato() {
    emit invioAggiunta(0);
}

void aggiungihome::bottoneIpertrofiaCliccato() {
    emit invioAggiunta(1);
}

void aggiungihome::bottoneHIITCliccato() {
    emit invioAggiunta(2);
}

void aggiungihome::bottoneLISSCliccato() {
    emit invioAggiunta(3);
}

#include "risultatomodifica.h"

risultatomodifica::risultatomodifica(QWidget* parent): QWidget(parent) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();

    immagine=new QLabel();
    immagine->setScaledContents(true);
    QPixmap img(":/view/images/icons/success.png");
    immagine->setPixmap(img);
    immagine->setMaximumSize(80,80);

    didascalia = new QLabel(this);
    didascalia->setText("L'esercizio e' stato modificato con successo!");
    didascalia->setAlignment(Qt::AlignHCenter);

    tornaHomePage = new QPushButton(this);
    tornaHomePage->setText("Home page");

    layout->addWidget(immagine,1,Qt::AlignCenter);
    layout->addWidget(didascalia,1,Qt::AlignCenter);
    layout->addWidget(tornaHomePage,1,Qt::AlignCenter);

    this->setLayout(layout);

    connect(tornaHomePage, SIGNAL(clicked()), parent, SLOT(bottoneAggiungiCliccato()));
}

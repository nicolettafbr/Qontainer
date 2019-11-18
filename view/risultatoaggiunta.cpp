#include "risultatoaggiunta.h"

risultatoaggiunta::risultatoaggiunta(QWidget* parent) : QWidget(parent) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();

    QLabel* immagine=new QLabel();
    immagine->setScaledContents(true);
    QPixmap img(":/view/images/icons/success.png");
    immagine->setPixmap(img);
    immagine->setMaximumSize(80,80);

    QLabel* messaggioConferma = new QLabel(this);
    messaggioConferma->setText("Il tuo esercizio e' stato aggiunto con successo!");
    messaggioConferma->setAlignment(Qt::AlignHCenter);

    tornaHomePage = new QPushButton(this);
    tornaHomePage->setText("Home page");

    layout->addWidget(immagine,1,Qt::AlignCenter);
    layout->addWidget(messaggioConferma,1,Qt::AlignCenter);
    layout->addWidget(tornaHomePage,1,Qt::AlignCenter);

    this->setLayout(layout);

    connect(tornaHomePage, SIGNAL(clicked()), parent, SLOT(bottoneAggiungiCliccato()));
}

#include "risultatoeliminazione.h"

risultatoeliminazione::risultatoeliminazione(QWidget* parent): QWidget(parent) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();

    QLabel* messaggioConferma = new QLabel(this);
    messaggioConferma->setText("L'esercizio e' stato eliminato con successo!");

    QLabel* immagine=new QLabel();
    immagine->setScaledContents(true);
    QPixmap img(":/view/images/icons/success.png");
    immagine->setPixmap(img);
    immagine->setMaximumSize(80,80);

    tornaMainWindow = new QPushButton(this);
    tornaMainWindow->setText("Home page");

    layout->addWidget(immagine,1,Qt::AlignCenter);
    layout->addWidget(messaggioConferma,1,Qt::AlignCenter);
    layout->addWidget(tornaMainWindow,1,Qt::AlignCenter);

    this->setLayout(layout);

    connect(tornaMainWindow, SIGNAL(clicked()), parent, SLOT(bottoneAggiungiCliccato()));
}

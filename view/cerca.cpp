#include "cerca.h"

cerca::cerca(Container<esercizio*>* cont, QWidget* parent):
    QWidget(parent), contenuto(cont) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();

    ricerca=new QGridLayout();

    didascalia=new QLabel();
    didascalia->setText("Inserisci i dati dell'esercizio che vuoi cercare:");
    layout->addWidget(didascalia);

    inserisciElemento("Nome:", "Inserisci il nome", 350, ricerca, 0);
    inserisciElemento("Data esecuzione:", "D/M/YYYY", 350, ricerca, 1);

    layout->addLayout(ricerca);

    bottoneCerca = new QPushButton();
    bottoneCerca->setText("Cerca");
    bottoneCerca->setMaximumSize(QSize(150,40));
    layout->addWidget(bottoneCerca,1,Qt::AlignCenter);

    this->setLayout(layout);

    connect(bottoneCerca, SIGNAL(clicked()), this, SLOT(schiacciaCerca()));
    connect(this, SIGNAL(invioRicerca(std::string,QDate)), parent, SLOT(risultatoRicerca(std::string,QDate)));
}

void cerca::inserisciElemento(QString nome, QString placeholder, int lunghezza, QGridLayout* griglia, int riga) {
    QLabel* label=new QLabel(this);
    label->setText(nome);

    QLineEdit* box=new QLineEdit(this);
    box->setFixedWidth(lunghezza);
    box->setPlaceholderText(placeholder);

    vettoreInput.push_back(box);
    griglia->addWidget(label, riga, 0, Qt::AlignLeft);
    griglia->addWidget(box, riga, 1, Qt::AlignLeft);
}

void cerca::schiacciaCerca() {
    std::string nome=vettoreInput[0]->text().toStdString();
    QDate data=QDate::fromString(vettoreInput[1]->text(),"d/M/yyyy");

    emit invioRicerca(nome,data);
}



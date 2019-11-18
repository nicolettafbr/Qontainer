#include "risultatoricerca.h"

risultatoricerca::risultatoricerca(Container<esercizio*>* cont, vector<esercizio*>& risultati, QWidget* parent) :
    QWidget(parent), contenuto(cont), risultatiRicerca(risultati) {
    setFocusPolicy(Qt::StrongFocus);

    layout = new QVBoxLayout();
    didascalia=new QLabel();

    if(risultatiRicerca.empty()) {
        didascalia->setText("OOOPS!\tLa tua ricerca non ha prodotto risultati.");
        layout->addWidget(didascalia,1,Qt::AlignCenter);
        QLabel* immagine=new QLabel();
        immagine->setScaledContents(true);
        QPixmap img(":/view/images/icons/fail.png");
        immagine->setPixmap(img);
        immagine->setMaximumSize(100,100);
        layout->addWidget(immagine,1,Qt::AlignCenter);
    }else{
        didascalia->setText("I risultati della tua ricerca:");
        layout->addWidget(didascalia);

        boxRisultati=new QVBoxLayout();
        QWidget* sfondo=new QWidget();
        sfondo->setStyleSheet("background-color: #fff;");
        QScrollArea* scrollArea = new QScrollArea();
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidget(sfondo);
        boxRisultati->addWidget(scrollArea);

        layoutRisultati=new QGridLayout();
        caricaRisultatoRicerca();
        sfondo->setLayout(layoutRisultati);

        layout->addLayout(boxRisultati);
    }

    this->setLayout(layout);

    connect(this, SIGNAL(inviaVisualizza(esercizio*)), parent, SLOT(visualizzaEsercizio(esercizio*)));
}

void risultatoricerca::caricaRisultatoRicerca() {
    for(unsigned int it=0; it!=risultatiRicerca.size(); ++it) {
        QLabel* tipoEsercizio=new QLabel();
        if(dynamic_cast<forza*>(risultatiRicerca[it]))
            tipoEsercizio->setText("FORZA");
        if(dynamic_cast<ipertrofia*>(risultatiRicerca[it]))
            tipoEsercizio->setText("IPERTROFIA");
        if(dynamic_cast<hiit*>(risultatiRicerca[it]))
            tipoEsercizio->setText("HIIT");
        if(dynamic_cast<liss*>(risultatiRicerca[it]))
            tipoEsercizio->setText("LISS");
        QLabel* nomeEsercizio=new QLabel();
        nomeEsercizio->setText(QString::fromStdString(risultatiRicerca[it]->getNome()));
        QLabel* dataEs=new QLabel();
        dataEs->setText(QString::fromStdString(risultatiRicerca[it]->getDataEsecuzione().dataToString()));
        QPushButton* bottoneVisualizza=new QPushButton();
        bottoneVisualizza->setText("Visualizza");
        bottoneVisualizza->setStyleSheet("background-color: grey; padding: 4px; border-radius: 2px;");
        bottoneVisualizza->setMaximumWidth(90);
        bottoneVisualizza->setObjectName(QString::number(it));
        layoutRisultati->addWidget(tipoEsercizio,it,0);
        layoutRisultati->addWidget(nomeEsercizio,it,1);
        layoutRisultati->addWidget(dataEs,it,2);
        layoutRisultati->addWidget(bottoneVisualizza,it,3);

        connect(bottoneVisualizza, SIGNAL(clicked()), this, SLOT(schiacciaVisualizza()));
    }
}

void risultatoricerca::schiacciaVisualizza() {
    QPushButton* bottoneVisualizza = dynamic_cast<QPushButton*>(sender());
        if (bottoneVisualizza) {
            int indice = bottoneVisualizza->objectName().toInt(), i=0;
            esercizio* esercizioDaVisualizzare = nullptr;
            for(auto it=risultatiRicerca.begin(); it!=risultatiRicerca.end() && i<=indice; ++it){
                if(i==indice) esercizioDaVisualizzare=*it;
                ++i;
            }
            emit inviaVisualizza(esercizioDaVisualizzare);
        }
}

#ifndef RISULTATORICERCA_H
#define RISULTATORICERCA_H
#include "model/container.h"
#include "model/forza.h"
#include "model/ipertrofia.h"
#include "model/hiit.h"
#include "model/liss.h"
#include "model/database.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollArea>
using std::vector;

class risultatoricerca: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout, * boxRisultati;
    QLabel* didascalia;
    QGridLayout* layoutRisultati;
    Container<esercizio*>* contenuto;
    vector<esercizio*> risultatiRicerca;
private slots:
    void caricaRisultatoRicerca();
    void schiacciaVisualizza();
signals:
    void inviaVisualizza(esercizio*);
public:
    risultatoricerca(Container<esercizio*>*,vector<esercizio*>&,QWidget* = nullptr);
    ~risultatoricerca() = default;
};

#endif // RISULTATORICERCA_H

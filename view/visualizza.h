#ifndef VISUALIZZA_H
#define VISUALIZZA_H
#include "model/container.h"
#include "model/forza.h"
#include "model/ipertrofia.h"
#include "model/hiit.h"
#include "model/liss.h"
#include "model/database.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <vector>
using std::vector;

class visualizza: public QWidget {
    Q_OBJECT
private:
   QVBoxLayout* layout, * boxEsercizi;
   QLabel* didascalia;
   QGridLayout* corpo, * mostraEsercizi;
   QScrollArea* scrollArea;
   QPushButton* bottoneForza, * bottoneIpertrofia, * bottoneHIIT, * bottoneLISS;
   Container<esercizio*>* contenuto;
private slots:
   void bottoneForzaCliccato();
   void bottoneIpertrofiaCliccato();
   void bottoneHIITCliccato();
   void bottoneLISSCliccato();
   void schiacciaVisualizza();
public slots:
   void visualizzaEsercizi(int);
   void creaEsercizio(int,int,const Container<esercizio*>::Iterator&);
   void eliminaContenuto();
public:
   visualizza(Container<esercizio*>*, QWidget* =nullptr);
   ~visualizza() =default;
signals:
   void inviaVisualizza(esercizio*);
};

#endif

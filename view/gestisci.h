#ifndef GESTISCI_H
#define GESTISCI_H
#include "model/container.h"
#include "model/forza.h"
#include "model/ipertrofia.h"
#include "model/hiit.h"
#include "model/liss.h"
#include "model/database.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QMessageBox>

class gestisci: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout, * boxEsercizi;
    QLabel* didascalia;
    QGridLayout* corpo, * mostraEsercizi;
    QScrollArea* scrollArea;
    QPushButton* bottoneForza, * bottoneIpertrofia, * bottoneHIIT, * bottoneLISS, * bottoneModifica, * bottoneElimina;
    Container<esercizio*>* contenuto;
private slots:
   void bottoneForzaCliccato();
   void bottoneIpertrofiaCliccato();
   void bottoneHIITCliccato();
   void bottoneLISSCliccato();
   void schiacciaModifica();
   void schiacciaElimina();
public slots:
   void visualizzaEsercizi(int);
   void creaEsercizio(int,int,const Container<esercizio*>::Iterator&);
   void eliminaContenuto();
   void eliminaEsercizio();
public:
   gestisci(Container<esercizio*>*, QWidget* =nullptr);
   ~gestisci() =default;
signals:
   void inviaModifica(esercizio*);
   void inviaEliminazione();
};
#endif // GESTISCI_H

#ifndef AGGIUNGI_H
#define AGGIUNGI_H
#include "model/container.h"
#include "model/forza.h"
#include "model/ipertrofia.h"
#include "model/hiit.h"
#include "model/liss.h"
#include "model/database.h"
#include <QVBoxLayout>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDateEdit>
#include <QDate>
#include <vector>
using std::vector;

class aggiungi: public QWidget {
    Q_OBJECT
private:
   QVBoxLayout* layout;
   QComboBox* sceltaCategoria;
   QGridLayout* grigliaAggiunta, * aggiuntaAvanzata, * grigliaBottoni;
   QPushButton* bottoneAggiunta, * bottoneAnnulla;
   Container<esercizio*>* contenuto;
   vector<QLineEdit*> vettoreInput;
private slots:
   void schiacciaAggiungi();
   void aggiungiEsercizio();
   void inserisciElemento(QString,QString,int,QGridLayout*,int);
   void aggiungiInput(int i);
signals:
   void invioAggiunta();
public:
   aggiungi(Container<esercizio*>*, int, QWidget* =nullptr);
   ~aggiungi() =default;
};

#endif // AGGIUNGI_H

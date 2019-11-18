#ifndef CERCA_H
#define CERCA_H
#include "model/container.h"
#include "model/forza.h"
#include "model/ipertrofia.h"
#include "model/hiit.h"
#include "model/liss.h"
#include "model/database.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <string>
#include <QLineEdit>
#include <QDate>
#include <vector>
using std::vector;

class cerca: public QWidget {
    Q_OBJECT
private:
   QVBoxLayout* layout;
   QLabel* didascalia;
   QGridLayout* ricerca;
   QPushButton* bottoneCerca;
   Container<esercizio*>* contenuto;
   vector<QLineEdit*> vettoreInput;
public:
   cerca(Container<esercizio*>*, QWidget* =nullptr);
   ~cerca() =default;
private slots:
   void inserisciElemento(QString,QString,int,QGridLayout*,int);
   void schiacciaCerca();
signals:
   void invioRicerca(std::string,QDate);
};

#endif // CERCA_H

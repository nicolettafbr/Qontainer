#ifndef MODIFICA_H
#define MODIFICA_H
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
#include <QLineEdit>
#include <vector>
using std::vector;

class modifica: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QGridLayout* grigliaModifica, * grigliaBottoni;
    QPushButton* bottoneAnnulla, * bottoneModifica;
    esercizio* es;
    vector<QLineEdit*> vettoreModifiche;
    void campiDaModificare();
    void creaEntry(QString,QString,int,QGridLayout*,int);
public:
    modifica(esercizio*,QWidget* =nullptr);
    ~modifica() =default;
private slots:
    void schiacciaModifica();
    void modificaElemento();
signals:
    void inviaModifica();
};

#endif // MODIFICA_H

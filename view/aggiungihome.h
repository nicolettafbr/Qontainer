#ifndef AGGIUNGIHOME_H
#define AGGIUNGIHOME_H
#include "aggiungi.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class aggiungihome: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QLabel* didascalia;
    QGridLayout* grigliaBottoni;
    QPushButton* bottoneForza, * bottoneIpertrofia, * bottoneHIIT, * bottoneLISS;
    Container<esercizio*>* contenuto;
private slots:
    void bottoneForzaCliccato();
    void bottoneIpertrofiaCliccato();
    void bottoneHIITCliccato();
    void bottoneLISSCliccato();
signals:
    void invioAggiunta(int);
public:
    aggiungihome(Container<esercizio*>*,QWidget* =nullptr);
    ~aggiungihome() =default;
};

#endif // AGGIUNGIHOME_H

#ifndef VISUALIZZAESERCIZIO_H
#define VISUALIZZAESERCIZIO_H
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
#include <QLineEdit>
#include <QMessageBox>

class visualizzaesercizio: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QLabel* titoloFinestra;
    QPushButton* annulla, * modifica, * elimina;
    QGridLayout* griglia, * grigliaBottoni;
    void creaEntry(QString, QString, int, QGridLayout*, int);
    void campiDaVisualizzare();
    esercizio* elementoDaVisualizzare;
    Container<esercizio*>* contenuto;
    QWidget* paginaPrecedente;
private slots:
    void schiacciaModifica();
    void schiacciaElimina();
    void eliminaEsercizio();
signals:
    void inviaModifica(esercizio*);
    void inviaEliminazione(esercizio*);
public:
    visualizzaesercizio(esercizio*, QWidget* =nullptr);
    ~visualizzaesercizio() =default;
};

#endif // VISUALIZZAESERCIZIO_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "model/container.h"
#include "model/database.h"
#include "model/forza.h"
#include "model/ipertrofia.h"
#include "model/hiit.h"
#include "model/liss.h"
#include "aggiungihome.h"
#include "aggiungi.h"
#include "visualizza.h"
#include "cerca.h"
#include "gestisci.h"
#include "modifica.h"
#include "visualizzaesercizio.h"
#include "risultatoaggiunta.h"
#include "risultatoricerca.h"
#include "risultatoeliminazione.h"
#include "risultatomodifica.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QStackedWidget>
#include <QCloseEvent>
#include <QFile>
#include <QFileDialog>

class mainwindow : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QHBoxLayout* boxBottoni;
    QLabel* titoloFinestra;
    QPushButton* bottoneAggiungi,* bottoneVisualizza,* bottoneRicerca,* bottoneGestisci;
    QStackedWidget* pagineDaVisualizzare;
    aggiungihome* paginaAggiunta; cerca* paginaRicerca;
    Container<esercizio*> contenuto;
    database* db;
protected:
    void closeEvent(QCloseEvent*) override;
private slots:
    QString aperturaFile();
    void bottoneAggiungiCliccato();
    void bottoneRicercaCliccato();
    void bottoneVisualizzaCliccato();
    void bottoneGestisciCliccato();
    void inizializzaPagine(QStackedWidget*);
    void aggiuntaAvanzata(int);
    void risultatoAggiunta();
    void modificaEsercizio(esercizio*);
    void risultatoEliminazione();
    void risultatoModifica();
    void risultatoRicerca(std::string,QDate);
    void visualizzaEsercizio(esercizio*);
    void eliminaWidget();
    void eliminaSingoloEsercizio(esercizio*);
public:
    mainwindow(QWidget* = nullptr);
    ~mainwindow() =default;
};

#endif

#ifndef RISULTATOELIMINAZIONE_H
#define RISULTATOELIMINAZIONE_H
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

class risultatoeliminazione: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QPushButton* tornaGestisci, * tornaMainWindow;
public:
    risultatoeliminazione(QWidget* =nullptr);
    ~risultatoeliminazione() =default;
};

#endif // RISULTATOELIMINAZIONE_H

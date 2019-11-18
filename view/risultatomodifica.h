#ifndef RISULTATOMODIFICA_H
#define RISULTATOMODIFICA_H
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>


class risultatomodifica: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QLabel* immagine, * didascalia;
    QPushButton* tornaHomePage;
public:
    risultatomodifica(QWidget* =nullptr);
    ~risultatomodifica() =default;
};

#endif // RISULTATOMODIFICA_H

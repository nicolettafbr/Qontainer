#ifndef RISULTATOAGGIUNTA_H
#define RISULTATOAGGIUNTA_H
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class risultatoaggiunta: public QWidget {
    Q_OBJECT
private:
    QVBoxLayout* layout;
    QGridLayout* griglia;
    QPushButton* tornaHomePage;
public:
    risultatoaggiunta(QWidget* = nullptr);
    ~risultatoaggiunta() = default;
};

#endif // RISULTATOAGGIUNTA_H

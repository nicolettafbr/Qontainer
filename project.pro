QT += core
QT += widgets
QT += gui
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
CONFIG+=sdk_no_version_check

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
	model/classidiutilita.h \
        model/esercizio.h \
        model/cardio.h \
        model/sovraccarico.h \
        model/hiit.h \
        model/liss.h \
        model/forza.h \
        model/ipertrofia.h \
        model/database.h \
        model/container.h \
        view/aggiungi.h \
        view/aggiungihome.h \
        view/cerca.h \
        view/gestisci.h \
        view/mainwindow.h \
        view/modifica.h \
        view/risultatoaggiunta.h \
        view/risultatoeliminazione.h \
        view/risultatomodifica.h \
        view/risultatoricerca.h \
        view/visualizza.h \
        view/visualizzaesercizio.h

SOURCES += \
	main.cpp \
	model/classidiutilita.cpp \
	model/esercizio.cpp \
	model/cardio.cpp \
	model/sovraccarico.cpp \
	model/hiit.cpp \
	model/liss.cpp \
	model/forza.cpp \
	model/ipertrofia.cpp \
	model/database.cpp \
        view/aggiungi.cpp \
        view/aggiungihome.cpp \
        view/cerca.cpp \
        view/gestisci.cpp \
        view/mainwindow.cpp \
        view/modifica.cpp \
        view/risultatoaggiunta.cpp \
        view/risultatoeliminazione.cpp \
        view/risultatomodifica.cpp \
        view/risultatoricerca.cpp \
        view/visualizza.cpp \
        view/visualizzaesercizio.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qontainer.qrc

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db.cpp \
    f1_f2.cpp \
    f1_f3.cpp \
    f1_f4.cpp \
    f2_f3.cpp \
    f2_f4.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    table_hachage.cpp

HEADERS += \
    db.h \
    f1_f2.h \
    f1_f3.h \
    f1_f4.h \
    f2_f3.h \
    f2_f4.h \
    mainwindow.h \
    qcustomplot.h \
    table_hachage.h

FORMS += \
    f1_f2.ui \
    f1_f3.ui \
    f1_f4.ui \
    f2_f3.ui \
    f2_f4.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

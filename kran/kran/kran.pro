QT       += core gui
QT       += printsupport
QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        chart.cpp \
        editdialog.cpp \
        kranData.cpp \
        kranModel.cpp \
        main.cpp \
        mainwindow.cpp \
        mysortproxymodel.cpp \
        mytableview.cpp \
        printpreview.cpp \
        search.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    chart.h \
    editdialog.h \
    kranData.h \
    kranModel.h \
    mainwindow.h \
    mysortproxymodel.h \
    mytableview.h \
    printpreview.h \
    search.h

FORMS += \
    chart.ui \
    editdialog.ui \
    mainwindow.ui \
    printpreview.ui \
    search.ui

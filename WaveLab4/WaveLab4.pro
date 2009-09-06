# -------------------------------------------------
# Project created by QtCreator 2009-09-03T14:54:41
# -------------------------------------------------
TARGET = WaveLab
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    wavewidget.cpp \
    waverender.cpp \
    datacontainer.cpp \
    vectorwidget.cpp \
    vectorrender.cpp
HEADERS += mainwindow.h \
    wavewidget.h \
    waverender.h \
    datacontainer.h \
    vectorwidget.h \
    vectorrender.h
FORMS += mainwindow.ui

# --------------------------------------------
# Added for Qwt
# --------------------------------------------
QWT_ROOT = /usr/local/qwt-5.2.0
win32 {
    QWT_ROOT = C:/Qwt-5.2.0
}
QWTLIB = qwt
CONFIG += static
INCLUDEPATH += $${QWT_ROOT}/include
INCLUDEPATH += $${QWT_ROOT}/src
DEPENDPATH += $${QWT_ROOT}/src
LIBS += -L$${QWT_ROOT}/lib \
    -l$${QWTLIB}
LIBS += -L$${QWT_ROOT}/lib/libqwt.a
MOC_DIR = moc
OBJECTS_DIR = obj

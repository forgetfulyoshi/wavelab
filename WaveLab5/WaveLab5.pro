HEADERS += wavewidget.h \
    vectorwidget.h \
    mainwindow.h \
    labwidget.h \
    datacontainer.h \
    intensitywavewidget.h \
    intensityvectorwidget.h
SOURCES += wavewidget.cpp \
    vectorwidget.cpp \
    mainwindow.cpp \
    main.cpp \
    labwidget.cpp \
    datacontainer.cpp \
    intensitywavewidget.cpp \
    intensityvectorwidget.cpp
FORMS += mainwindow.ui


# --------------------------------------------
# Added for Qwt
# --------------------------------------------

win32 {

    QWT_ROOT = C:/Qwt-5.2.0

} else : macx {

    QWT_ROOT = /usr/local/qwt-5.2.0

} else { # Linux, etc.

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


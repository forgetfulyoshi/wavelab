# --------------------------------------------
# Added for Qwt
# --------------------------------------------
QWT_ROOT = /usr/local/qwt-5.2.0
win32:QWT_ROOT = C:/Qwt-5.2.0
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
HEADERS += wavewidget.h \
    vectorwidget.h \
    mainwindow.h \
    labwidget.h \
    datacontainer.h
SOURCES += wavewidget.cpp \
    vectorwidget.cpp \
    mainwindow.cpp \
    main.cpp \
    labwidget.cpp \
    datacontainer.cpp

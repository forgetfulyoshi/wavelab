/****************************************************************************
** Meta object code from reading C++ file 'wavewidget.h'
**
** Created: Fri Sep 4 17:31:25 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../wavewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wavewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WaveWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      19,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,
      43,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WaveWidget[] = {
    "WaveWidget\0\0step()\0reset()\0show_wave1(int)\0"
    "show_wave2(int)\0"
};

const QMetaObject WaveWidget::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_WaveWidget,
      qt_meta_data_WaveWidget, 0 }
};

const QMetaObject *WaveWidget::metaObject() const
{
    return &staticMetaObject;
}

void *WaveWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WaveWidget))
        return static_cast<void*>(const_cast< WaveWidget*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int WaveWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: step(); break;
        case 1: reset(); break;
        case 2: show_wave1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: show_wave2((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

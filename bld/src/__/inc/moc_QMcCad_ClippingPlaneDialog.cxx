/****************************************************************************
** Meta object code from reading C++ file 'QMcCad_ClippingPlaneDialog.h'
**
** Created: Fri Jun 29 13:22:52 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCad_ClippingPlaneDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCad_ClippingPlaneDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCad_ClippingPlaneDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x0a,
      47,   41,   27,   27, 0x0a,
      75,   69,   27,   27, 0x0a,
      97,   27,   27,   27, 0x0a,
     110,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMcCad_ClippingPlaneDialog[] = {
    "QMcCad_ClippingPlaneDialog\0\0IsAccepted()\0"
    "chVal\0VisuStateChanged(int)\0slVal\0"
    "SliderValChanged(int)\0IsCanceled()\0"
    "LineEdited()\0"
};

void QMcCad_ClippingPlaneDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMcCad_ClippingPlaneDialog *_t = static_cast<QMcCad_ClippingPlaneDialog *>(_o);
        switch (_id) {
        case 0: _t->IsAccepted(); break;
        case 1: _t->VisuStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SliderValChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->IsCanceled(); break;
        case 4: _t->LineEdited(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMcCad_ClippingPlaneDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMcCad_ClippingPlaneDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QMcCad_ClippingPlaneDialog,
      qt_meta_data_QMcCad_ClippingPlaneDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMcCad_ClippingPlaneDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMcCad_ClippingPlaneDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMcCad_ClippingPlaneDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMcCad_ClippingPlaneDialog))
        return static_cast<void*>(const_cast< QMcCad_ClippingPlaneDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QMcCad_ClippingPlaneDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'QMcCad_ClippingPlaneDialog.h'
**
** Created: Fri Jun 29 14:21:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCad_ClippingPlaneDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCad_ClippingPlaneDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCad_ClippingPlaneDialog[] = {

 // content:
       4,       // revision
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

const QMetaObject QMcCad_ClippingPlaneDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QMcCad_ClippingPlaneDialog,
      qt_meta_data_QMcCad_ClippingPlaneDialog, 0 }
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
        switch (_id) {
        case 0: IsAccepted(); break;
        case 1: VisuStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: SliderValChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: IsCanceled(); break;
        case 4: LineEdited(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

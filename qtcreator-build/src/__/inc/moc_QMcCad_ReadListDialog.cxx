/****************************************************************************
** Meta object code from reading C++ file 'QMcCad_ReadListDialog.hxx'
**
** Created: Mon Apr 22 15:02:37 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCad_ReadListDialog.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCad_ReadListDialog.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCad_ReadListDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      38,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMcCad_ReadListDialog[] = {
    "QMcCad_ReadListDialog\0\0SlotOpenFile()\0"
    "SlotDyeSolids()\0"
};

void QMcCad_ReadListDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMcCad_ReadListDialog *_t = static_cast<QMcCad_ReadListDialog *>(_o);
        switch (_id) {
        case 0: _t->SlotOpenFile(); break;
        case 1: _t->SlotDyeSolids(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QMcCad_ReadListDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMcCad_ReadListDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QMcCad_ReadListDialog,
      qt_meta_data_QMcCad_ReadListDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMcCad_ReadListDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMcCad_ReadListDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMcCad_ReadListDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMcCad_ReadListDialog))
        return static_cast<void*>(const_cast< QMcCad_ReadListDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QMcCad_ReadListDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

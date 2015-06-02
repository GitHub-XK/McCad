/****************************************************************************
** Meta object code from reading C++ file 'McCadDesign_CopyTo.hxx'
**
** Created: Fri Jun 29 13:22:51 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/McCadDesign_CopyTo.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'McCadDesign_CopyTo.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_McCadDesign_CopyTo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_McCadDesign_CopyTo[] = {
    "McCadDesign_CopyTo\0\0CreateCopy()\0"
};

void McCadDesign_CopyTo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        McCadDesign_CopyTo *_t = static_cast<McCadDesign_CopyTo *>(_o);
        switch (_id) {
        case 0: _t->CreateCopy(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData McCadDesign_CopyTo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject McCadDesign_CopyTo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_McCadDesign_CopyTo,
      qt_meta_data_McCadDesign_CopyTo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &McCadDesign_CopyTo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *McCadDesign_CopyTo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *McCadDesign_CopyTo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_McCadDesign_CopyTo))
        return static_cast<void*>(const_cast< McCadDesign_CopyTo*>(this));
    if (!strcmp(_clname, "McCadDesign_Tool"))
        return static_cast< McCadDesign_Tool*>(const_cast< McCadDesign_CopyTo*>(this));
    return QDialog::qt_metacast(_clname);
}

int McCadDesign_CopyTo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

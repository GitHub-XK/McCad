/****************************************************************************
** Meta object code from reading C++ file 'McCadDesign_MoveTo.hxx'
**
** Created: Fri Jun 29 14:21:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/McCadDesign_MoveTo.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'McCadDesign_MoveTo.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_McCadDesign_MoveTo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      42,   33,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_McCadDesign_MoveTo[] = {
    "McCadDesign_MoveTo\0\0CreateMove()\0"
    "dummyStr\0ConfirmMoveToPnt(QString)\0"
};

const QMetaObject McCadDesign_MoveTo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_McCadDesign_MoveTo,
      qt_meta_data_McCadDesign_MoveTo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &McCadDesign_MoveTo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *McCadDesign_MoveTo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *McCadDesign_MoveTo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_McCadDesign_MoveTo))
        return static_cast<void*>(const_cast< McCadDesign_MoveTo*>(this));
    if (!strcmp(_clname, "McCadDesign_Tool"))
        return static_cast< McCadDesign_Tool*>(const_cast< McCadDesign_MoveTo*>(this));
    return QDialog::qt_metacast(_clname);
}

int McCadDesign_MoveTo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: CreateMove(); break;
        case 1: ConfirmMoveToPnt((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

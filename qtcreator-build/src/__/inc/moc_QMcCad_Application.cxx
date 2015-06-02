/****************************************************************************
** Meta object code from reading C++ file 'QMcCad_Application.h'
**
** Created: Mon Apr 22 15:02:37 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCad_Application.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCad_Application.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCad_Application[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      34,   19,   19,   19, 0x08,
      58,   49,   19,   19, 0x08,
      81,   19,   19,   19, 0x08,
      97,   19,   19,   19, 0x08,
     112,   19,   19,   19, 0x08,
     129,   19,   19,   19, 0x08,
     142,   19,   19,   19, 0x08,
     155,   19,   19,   19, 0x08,
     170,   19,   19,   19, 0x08,
     182,   19,   19,   19, 0x08,
     193,   19,   19,   19, 0x08,
     210,   19,   19,   19, 0x08,
     222,   19,   19,   19, 0x08,
     233,   19,   19,   19, 0x08,
     251,   19,   19,   19, 0x08,
     273,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QMcCad_Application[] = {
    "QMcCad_Application\0\0SlotFileNew()\0"
    "SlotFileOpen()\0fileName\0SlotFileOpen(QString&)\0"
    "SlotFileClose()\0SlotFileSave()\0"
    "SlotFileSaveAs()\0SlotImport()\0"
    "SlotExport()\0SlotHardcopy()\0SlotPrint()\0"
    "SlotQuit()\0OpenRecentFile()\0SlotAbout()\0"
    "SlotHelp()\0SlotUpdateMenus()\0"
    "SlotEditorClosed(int)\0SlotUpdateMainTitle()\0"
};

void QMcCad_Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMcCad_Application *_t = static_cast<QMcCad_Application *>(_o);
        switch (_id) {
        case 0: _t->SlotFileNew(); break;
        case 1: _t->SlotFileOpen(); break;
        case 2: _t->SlotFileOpen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->SlotFileClose(); break;
        case 4: _t->SlotFileSave(); break;
        case 5: _t->SlotFileSaveAs(); break;
        case 6: _t->SlotImport(); break;
        case 7: _t->SlotExport(); break;
        case 8: _t->SlotHardcopy(); break;
        case 9: _t->SlotPrint(); break;
        case 10: _t->SlotQuit(); break;
        case 11: _t->OpenRecentFile(); break;
        case 12: _t->SlotAbout(); break;
        case 13: _t->SlotHelp(); break;
        case 14: _t->SlotUpdateMenus(); break;
        case 15: _t->SlotEditorClosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->SlotUpdateMainTitle(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMcCad_Application::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMcCad_Application::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QMcCad_Application,
      qt_meta_data_QMcCad_Application, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMcCad_Application::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMcCad_Application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMcCad_Application::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMcCad_Application))
        return static_cast<void*>(const_cast< QMcCad_Application*>(this));
    if (!strcmp(_clname, "McCadAEV_Application"))
        return static_cast< McCadAEV_Application*>(const_cast< QMcCad_Application*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QMcCad_Application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

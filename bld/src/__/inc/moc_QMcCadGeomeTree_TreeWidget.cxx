/****************************************************************************
** Meta object code from reading C++ file 'QMcCadGeomeTree_TreeWidget.hxx'
**
** Created: Fri Jun 29 13:22:51 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCadGeomeTree_TreeWidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCadGeomeTree_TreeWidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCadGeomeTree_TreeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x0a,
      51,   27,   27,   27, 0x0a,
      90,   78,   27,   27, 0x0a,
     132,   27,   27,   27, 0x0a,
     155,   27,   27,   27, 0x0a,
     187,  180,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMcCadGeomeTree_TreeWidget[] = {
    "QMcCadGeomeTree_TreeWidget\0\0"
    "SlotSelectionChanged()\0"
    "SlotVisuSelectionChanged()\0item,column\0"
    "SlotItemNameChanged(QTreeWidgetItem*,int)\0"
    "SlotAddMaterialGroup()\0SlotAddToMaterialGroup()\0"
    "theTWI\0SlotEditMCard(QTreeWidgetItem*)\0"
};

void QMcCadGeomeTree_TreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMcCadGeomeTree_TreeWidget *_t = static_cast<QMcCadGeomeTree_TreeWidget *>(_o);
        switch (_id) {
        case 0: _t->SlotSelectionChanged(); break;
        case 1: _t->SlotVisuSelectionChanged(); break;
        case 2: _t->SlotItemNameChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->SlotAddMaterialGroup(); break;
        case 4: _t->SlotAddToMaterialGroup(); break;
        case 5: _t->SlotEditMCard((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMcCadGeomeTree_TreeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMcCadGeomeTree_TreeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QMcCadGeomeTree_TreeWidget,
      qt_meta_data_QMcCadGeomeTree_TreeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMcCadGeomeTree_TreeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMcCadGeomeTree_TreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMcCadGeomeTree_TreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMcCadGeomeTree_TreeWidget))
        return static_cast<void*>(const_cast< QMcCadGeomeTree_TreeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QMcCadGeomeTree_TreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

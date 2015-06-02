/****************************************************************************
** Meta object code from reading C++ file 'QMcCadGeomeTree_TreeWidget.hxx'
**
** Created: Fri Jun 29 14:21:52 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../inc/QMcCadGeomeTree_TreeWidget.hxx"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMcCadGeomeTree_TreeWidget.hxx' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMcCadGeomeTree_TreeWidget[] = {

 // content:
       4,       // revision
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

const QMetaObject QMcCadGeomeTree_TreeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QMcCadGeomeTree_TreeWidget,
      qt_meta_data_QMcCadGeomeTree_TreeWidget, 0 }
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
        switch (_id) {
        case 0: SlotSelectionChanged(); break;
        case 1: SlotVisuSelectionChanged(); break;
        case 2: SlotItemNameChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: SlotAddMaterialGroup(); break;
        case 4: SlotAddToMaterialGroup(); break;
        case 5: SlotEditMCard((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

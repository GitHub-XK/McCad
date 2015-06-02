#ifndef QMCCADGEOMETREE_TREEVIEW_GRID_H
#define QMCCADGEOMETREE_TREEVIEW_GRID_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

class Ui_McTreeView
{
public:
    QGridLayout *gridLayout;
    QTreeView *myTreeView;

    void setupUi(QWidget *McTreeView)
    {
    McTreeView->setObjectName(QString::fromUtf8("McTreeView"));
    McTreeView->resize(QSize(236, 762).expandedTo(McTreeView->minimumSizeHint()));
    McTreeView->setWindowIcon(QIcon());
    gridLayout = new QGridLayout(McTreeView);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    myTreeView = new QTreeView(McTreeView);
    myTreeView->setObjectName(QString::fromUtf8("myTreeView"));
    myTreeView->setAcceptDrops(true);
    myTreeView->setFrameShape(QFrame::NoFrame);
    myTreeView->setFrameShadow(QFrame::Plain);
    myTreeView->setLineWidth(0);
    myTreeView->setProperty("showDropIndicator", QVariant(true));
    myTreeView->setDragEnabled(true);
    myTreeView->setSelectionMode(QAbstractItemView::MultiSelection);
    myTreeView->setSelectionBehavior(QAbstractItemView::SelectItems);

    gridLayout->addWidget(myTreeView, 0, 0, 1, 1);

    retranslateUi(McTreeView);

    QMetaObject::connectSlotsByName(McTreeView);
    } // setupUi

    void retranslateUi(QWidget *McTreeView)
    {
    McTreeView->setWindowTitle(QApplication::translate("McTreeView", "GeomeTree", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(McTreeView);
    } // retranslateUi

};

namespace Ui {
    class McTreeView: public Ui_McTreeView {};
} // namespace Ui

#endif // QMCCADGEOMETREE_TREEVIEW_GRID_H

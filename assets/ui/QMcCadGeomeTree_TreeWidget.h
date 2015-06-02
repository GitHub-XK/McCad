#ifndef QMCCADGEOMETREE_TREEWIDGET_GRID_H
#define QMCCADGEOMETREE_TREEWIDGET_GRID_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

class Ui_McTreeView
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *McTreeView)
    {
    McTreeView->setObjectName(QString::fromUtf8("McTreeView"));
    McTreeView->resize(QSize(236, 762).expandedTo(McTreeView->minimumSizeHint()));
    McTreeView->setWindowIcon(QIcon());
    gridLayout = new QGridLayout(McTreeView);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    treeWidget = new QTreeWidget(McTreeView);
    treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
    treeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    treeWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
    treeWidget->setColumnCount(0);

    gridLayout->addWidget(treeWidget, 0, 0, 1, 1);

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

#endif // QMCCADGEOMETREE_TREEWIDGET_GRID_H

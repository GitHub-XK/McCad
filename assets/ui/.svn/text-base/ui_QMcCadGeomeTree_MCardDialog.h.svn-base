#ifndef QMCCADGEOMETREE_MCARDDIALOG_H
#define QMCCADGEOMETREE_MCARDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

class Ui_Dialog
{
public:
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QTextEdit *mCardText;

    void setupUi(QDialog *Dialog)
    {
    Dialog->setObjectName(QString::fromUtf8("Dialog"));
    Dialog->resize(QSize(518, 287).expandedTo(Dialog->minimumSizeHint()));
    label_2 = new QLabel(Dialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 10, 91, 17));
    layoutWidget = new QWidget(Dialog);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(10, 250, 501, 33));
    hboxLayout = new QHBoxLayout(layoutWidget);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(layoutWidget);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    cancelButton = new QPushButton(layoutWidget);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout->addWidget(cancelButton);

    mCardText = new QTextEdit(Dialog);
    mCardText->setObjectName(QString::fromUtf8("mCardText"));
    mCardText->setGeometry(QRect(10, 30, 501, 211));
    mCardText->setUndoRedoEnabled(false);
    retranslateUi(Dialog);
    QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Dialog", "Material Card", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("Dialog", "OK", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

#endif // QMCCADGEOMETREE_MCARDDIALOG_H

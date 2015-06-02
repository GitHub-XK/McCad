#ifndef SCALE_H
#define SCALE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

class Ui_McCadDesign_Scale
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *sf_Y;
    QLineEdit *sf_Z;
    QLineEdit *sf_X;
    QLineEdit *sf_All;

    void setupUi(QDialog *McCadDesign_Scale)
    {
    McCadDesign_Scale->setObjectName(QString::fromUtf8("McCadDesign_Scale"));
    McCadDesign_Scale->resize(QSize(197, 200).expandedTo(McCadDesign_Scale->minimumSizeHint()));
    layoutWidget = new QWidget(McCadDesign_Scale);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(0, 160, 188, 33));
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

    label = new QLabel(McCadDesign_Scale);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 20, 101, 17));
    groupBox = new QGroupBox(McCadDesign_Scale);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(20, 50, 161, 101));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(40, 30, 21, 17));
    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(40, 50, 21, 17));
    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(40, 70, 21, 17));
    sf_Y = new QLineEdit(groupBox);
    sf_Y->setObjectName(QString::fromUtf8("sf_Y"));
    sf_Y->setGeometry(QRect(70, 50, 51, 20));
    sf_Y->setAlignment(Qt::AlignRight);
    sf_Z = new QLineEdit(groupBox);
    sf_Z->setObjectName(QString::fromUtf8("sf_Z"));
    sf_Z->setGeometry(QRect(70, 70, 51, 20));
    sf_Z->setAlignment(Qt::AlignRight);
    sf_X = new QLineEdit(groupBox);
    sf_X->setObjectName(QString::fromUtf8("sf_X"));
    sf_X->setGeometry(QRect(70, 30, 51, 20));
    sf_X->setAlignment(Qt::AlignRight);
    sf_All = new QLineEdit(McCadDesign_Scale);
    sf_All->setObjectName(QString::fromUtf8("sf_All"));
    sf_All->setGeometry(QRect(120, 20, 51, 20));
    sf_All->setAlignment(Qt::AlignRight);
    retranslateUi(McCadDesign_Scale);
    QObject::connect(okButton, SIGNAL(clicked()), McCadDesign_Scale, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), McCadDesign_Scale, SLOT(reject()));

    QMetaObject::connectSlotsByName(McCadDesign_Scale);
    } // setupUi

    void retranslateUi(QDialog *McCadDesign_Scale)
    {
    McCadDesign_Scale->setWindowTitle(QApplication::translate("McCadDesign_Scale", "Scaling", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("McCadDesign_Scale", "OK", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("McCadDesign_Scale", "Cancel", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("McCadDesign_Scale", "Scale Factor", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("McCadDesign_Scale", "Axis Dependent Scaling", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("McCadDesign_Scale", "X", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("McCadDesign_Scale", "Y", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("McCadDesign_Scale", "Z", 0, QApplication::UnicodeUTF8));
    sf_Y->setText(QApplication::translate("McCadDesign_Scale", "", 0, QApplication::UnicodeUTF8));
    sf_Z->setText(QApplication::translate("McCadDesign_Scale", "", 0, QApplication::UnicodeUTF8));
    sf_X->setText(QApplication::translate("McCadDesign_Scale", "", 0, QApplication::UnicodeUTF8));
    sf_All->setText(QApplication::translate("McCadDesign_Scale", "1", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(McCadDesign_Scale);
    } // retranslateUi

};

namespace Ui {
    class McCadDesign_Scale: public Ui_McCadDesign_Scale {};
} // namespace Ui

#endif // SCALE_H

/********************************************************************************
** Form generated from reading UI file 'ControllerLayout.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERLAYOUT_H
#define UI_CONTROLLERLAYOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControllerLayout
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *ControllerLayout)
    {
        if (ControllerLayout->objectName().isEmpty())
            ControllerLayout->setObjectName(QString::fromUtf8("ControllerLayout"));
        ControllerLayout->resize(696, 365);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ControllerLayout/controller.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ControllerLayout->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(ControllerLayout);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 641, 342));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/ControllerLayout/Controllerlayout.jpg")));

        verticalLayout->addWidget(label);


        retranslateUi(ControllerLayout);

        QMetaObject::connectSlotsByName(ControllerLayout);
    } // setupUi

    void retranslateUi(QDialog *ControllerLayout)
    {
        ControllerLayout->setWindowTitle(QCoreApplication::translate("ControllerLayout", "ControllerLayout", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ControllerLayout: public Ui_ControllerLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERLAYOUT_H

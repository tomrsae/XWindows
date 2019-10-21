/********************************************************************************
** Form generated from reading UI file 'XSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XSETTINGS_H
#define UI_XSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XSettings
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_header;
    QLabel *label_functionality;
    QLabel *label_sensitivity;
    QDoubleSpinBox *js_sense;
    QLabel *label_triggerSense;
    QSpinBox *trigger_sense;
    QLabel *label_maxReconnect;
    QSpinBox *max_reconnects;
    QLabel *label_administrative;
    QCheckBox *startWithSystem;
    QSpacerItem *verticalSpacer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *XSettings)
    {
        if (XSettings->objectName().isEmpty())
            XSettings->setObjectName(QString::fromUtf8("XSettings"));
        XSettings->resize(351, 456);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(XSettings->sizePolicy().hasHeightForWidth());
        XSettings->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/XSettings/settings1.ico"), QSize(), QIcon::Selected, QIcon::On);
        XSettings->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(XSettings);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 331, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_header = new QLabel(verticalLayoutWidget);
        label_header->setObjectName(QString::fromUtf8("label_header"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_header->sizePolicy().hasHeightForWidth());
        label_header->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Leelawadee UI"));
        font.setPointSize(17);
        label_header->setFont(font);
        label_header->setScaledContents(false);
        label_header->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_header, 0, Qt::AlignVCenter);

        label_functionality = new QLabel(verticalLayoutWidget);
        label_functionality->setObjectName(QString::fromUtf8("label_functionality"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Leelawadee UI"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        label_functionality->setFont(font1);

        verticalLayout->addWidget(label_functionality);

        label_sensitivity = new QLabel(verticalLayoutWidget);
        label_sensitivity->setObjectName(QString::fromUtf8("label_sensitivity"));
        QFont font2;
        font2.setPointSize(9);
        label_sensitivity->setFont(font2);

        verticalLayout->addWidget(label_sensitivity);

        js_sense = new QDoubleSpinBox(verticalLayoutWidget);
        js_sense->setObjectName(QString::fromUtf8("js_sense"));
        js_sense->setMaximumSize(QSize(100, 16777215));
        js_sense->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        js_sense->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        js_sense->setDecimals(1);
        js_sense->setMinimum(1.000000000000000);
        js_sense->setMaximum(10.000000000000000);
        js_sense->setSingleStep(0.100000000000000);
        js_sense->setValue(5.000000000000000);

        verticalLayout->addWidget(js_sense);

        label_triggerSense = new QLabel(verticalLayoutWidget);
        label_triggerSense->setObjectName(QString::fromUtf8("label_triggerSense"));
        label_triggerSense->setFont(font2);

        verticalLayout->addWidget(label_triggerSense);

        trigger_sense = new QSpinBox(verticalLayoutWidget);
        trigger_sense->setObjectName(QString::fromUtf8("trigger_sense"));
        trigger_sense->setMaximumSize(QSize(100, 16777215));
        trigger_sense->setMinimum(1);
        trigger_sense->setMaximum(10);
        trigger_sense->setValue(5);

        verticalLayout->addWidget(trigger_sense);

        label_maxReconnect = new QLabel(verticalLayoutWidget);
        label_maxReconnect->setObjectName(QString::fromUtf8("label_maxReconnect"));
        label_maxReconnect->setFont(font2);

        verticalLayout->addWidget(label_maxReconnect);

        max_reconnects = new QSpinBox(verticalLayoutWidget);
        max_reconnects->setObjectName(QString::fromUtf8("max_reconnects"));
        max_reconnects->setMaximumSize(QSize(100, 16777215));
        max_reconnects->setMinimum(1);
        max_reconnects->setMaximum(30);
        max_reconnects->setValue(5);

        verticalLayout->addWidget(max_reconnects);

        label_administrative = new QLabel(verticalLayoutWidget);
        label_administrative->setObjectName(QString::fromUtf8("label_administrative"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Leelawadee UI"));
        font3.setPointSize(12);
        font3.setUnderline(true);
        label_administrative->setFont(font3);

        verticalLayout->addWidget(label_administrative);

        startWithSystem = new QCheckBox(verticalLayoutWidget);
        startWithSystem->setObjectName(QString::fromUtf8("startWithSystem"));

        verticalLayout->addWidget(startWithSystem);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayoutWidget = new QWidget(XSettings);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 419, 333, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelBtn = new QPushButton(horizontalLayoutWidget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(0, 30));
        cancelBtn->setAutoDefault(true);

        horizontalLayout->addWidget(cancelBtn);

        okBtn = new QPushButton(horizontalLayoutWidget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setMinimumSize(QSize(200, 30));

        horizontalLayout->addWidget(okBtn);


        retranslateUi(XSettings);

        okBtn->setDefault(true);


        QMetaObject::connectSlotsByName(XSettings);
    } // setupUi

    void retranslateUi(QDialog *XSettings)
    {
        XSettings->setWindowTitle(QCoreApplication::translate("XSettings", "XSettings", nullptr));
        label_header->setText(QCoreApplication::translate("XSettings", "User settings", nullptr));
        label_functionality->setText(QCoreApplication::translate("XSettings", "Functionality", nullptr));
        label_sensitivity->setText(QCoreApplication::translate("XSettings", "Joystick sensitivity (mouse sense):", nullptr));
        label_triggerSense->setText(QCoreApplication::translate("XSettings", "Trigger sensitivity (scroll sense):", nullptr));
        label_maxReconnect->setText(QCoreApplication::translate("XSettings", "Maximum reconnect time (in minutes):", nullptr));
        max_reconnects->setSuffix(QString());
        max_reconnects->setPrefix(QString());
        label_administrative->setText(QCoreApplication::translate("XSettings", "Administrative", nullptr));
        startWithSystem->setText(QCoreApplication::translate("XSettings", "Start XWindows on system startup", nullptr));
        cancelBtn->setText(QCoreApplication::translate("XSettings", "Cancel", nullptr));
        okBtn->setText(QCoreApplication::translate("XSettings", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XSettings: public Ui_XSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XSETTINGS_H

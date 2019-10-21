/********************************************************************************
** Form generated from reading UI file 'XWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XWINDOWS_H
#define UI_XWINDOWS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XWindowsClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mainLayout;
    QLabel *label_logo;
    QLabel *label_controller;
    QPushButton *toggleBtn;
    QLabel *label_reconnect;
    QSpacerItem *bottomSpacer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *menuLayout;
    QPushButton *xboxBtn;
    QPushButton *settingsBtn;
    QLabel *label_verNum;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *footerLayout;
    QLabel *label_footer;

    void setupUi(QMainWindow *XWindowsClass)
    {
        if (XWindowsClass->objectName().isEmpty())
            XWindowsClass->setObjectName(QString::fromUtf8("XWindowsClass"));
        XWindowsClass->resize(391, 591);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/XWindows/controller.ico"), QSize(), QIcon::Normal, QIcon::Off);
        XWindowsClass->setWindowIcon(icon);
        XWindowsClass->setStyleSheet(QString::fromUtf8("background-color:  rgb(13, 115, 130);"));
        centralWidget = new QWidget(XWindowsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 50, 391, 511));
        mainLayout = new QVBoxLayout(verticalLayoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        label_logo = new QLabel(verticalLayoutWidget);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        QFont font;
        font.setFamily(QString::fromUtf8("Leelawadee UI"));
        font.setPointSize(45);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        label_logo->setFont(font);
        label_logo->setStyleSheet(QString::fromUtf8("color: rgb(244, 244, 244);\n"
"border-top: 2px solid rgb(255, 223, 32);"));
        label_logo->setFrameShadow(QFrame::Plain);
        label_logo->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_logo->setWordWrap(false);
        label_logo->setMargin(0);
        label_logo->setIndent(-1);

        mainLayout->addWidget(label_logo, 0, Qt::AlignTop);

        label_controller = new QLabel(verticalLayoutWidget);
        label_controller->setObjectName(QString::fromUtf8("label_controller"));
        label_controller->setPixmap(QPixmap(QString::fromUtf8(":/XWindows/ControllerON.png")));
        label_controller->setAlignment(Qt::AlignCenter);
        label_controller->setMargin(1);

        mainLayout->addWidget(label_controller);

        toggleBtn = new QPushButton(verticalLayoutWidget);
        toggleBtn->setObjectName(QString::fromUtf8("toggleBtn"));
        sizePolicy.setHeightForWidth(toggleBtn->sizePolicy().hasHeightForWidth());
        toggleBtn->setSizePolicy(sizePolicy);
        toggleBtn->setMinimumSize(QSize(0, 50));
        toggleBtn->setMaximumSize(QSize(250, 50));
        toggleBtn->setSizeIncrement(QSize(0, 0));
        toggleBtn->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Leelawadee"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        toggleBtn->setFont(font1);
        toggleBtn->setStyleSheet(QString::fromUtf8("color: rgb(243, 243, 243);\n"
"width: 175px;\n"
"margin-top: 5px;"));
        toggleBtn->setFlat(false);

        mainLayout->addWidget(toggleBtn, 0, Qt::AlignHCenter);

        label_reconnect = new QLabel(verticalLayoutWidget);
        label_reconnect->setObjectName(QString::fromUtf8("label_reconnect"));
        label_reconnect->setEnabled(true);
        QFont font2;
        font2.setPointSize(13);
        label_reconnect->setFont(font2);
        label_reconnect->setStyleSheet(QString::fromUtf8("color: rgb(255, 223, 32);"));
        label_reconnect->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(label_reconnect);

        bottomSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(bottomSpacer);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 391, 51));
        menuLayout = new QHBoxLayout(horizontalLayoutWidget);
        menuLayout->setSpacing(6);
        menuLayout->setContentsMargins(11, 11, 11, 11);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuLayout->setContentsMargins(0, 0, 0, 0);
        xboxBtn = new QPushButton(horizontalLayoutWidget);
        xboxBtn->setObjectName(QString::fromUtf8("xboxBtn"));
        xboxBtn->setMinimumSize(QSize(0, 33));
        xboxBtn->setMaximumSize(QSize(49, 16777215));
        xboxBtn->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"margin-left: 3px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/XWindows/xbox-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        xboxBtn->setIcon(icon1);
        xboxBtn->setIconSize(QSize(45, 45));

        menuLayout->addWidget(xboxBtn);

        settingsBtn = new QPushButton(horizontalLayoutWidget);
        settingsBtn->setObjectName(QString::fromUtf8("settingsBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(settingsBtn->sizePolicy().hasHeightForWidth());
        settingsBtn->setSizePolicy(sizePolicy1);
        settingsBtn->setMaximumSize(QSize(67, 16777215));
        settingsBtn->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"border-right: 2px outset rgb(255, 223, 35);\n"
"border-left: 2px outset rgb(255, 223, 35);\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/XWindows/settings1.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsBtn->setIcon(icon2);
        settingsBtn->setIconSize(QSize(40, 45));
        settingsBtn->setFlat(false);

        menuLayout->addWidget(settingsBtn);

        label_verNum = new QLabel(horizontalLayoutWidget);
        label_verNum->setObjectName(QString::fromUtf8("label_verNum"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sylfaen"));
        font3.setPointSize(15);
        label_verNum->setFont(font3);
        label_verNum->setLayoutDirection(Qt::LeftToRight);
        label_verNum->setStyleSheet(QString::fromUtf8("margin-right:7px;\n"
"color: rgb(243,243,243);\n"
"border-left: 2px solid rgb(255, 223, 32);"));
        label_verNum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        menuLayout->addWidget(label_verNum, 0, Qt::AlignRight);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 560, 391, 31));
        footerLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        footerLayout->setSpacing(6);
        footerLayout->setContentsMargins(11, 11, 11, 11);
        footerLayout->setObjectName(QString::fromUtf8("footerLayout"));
        footerLayout->setContentsMargins(0, 0, 0, 0);
        label_footer = new QLabel(horizontalLayoutWidget_2);
        label_footer->setObjectName(QString::fromUtf8("label_footer"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Leelawadee UI"));
        font4.setPointSize(9);
        label_footer->setFont(font4);
        label_footer->setStyleSheet(QString::fromUtf8("color: rgb(255, 211, 32);\n"
"border-top: 2px solid rgb(255, 211, 32);"));
        label_footer->setAlignment(Qt::AlignCenter);

        footerLayout->addWidget(label_footer);

        XWindowsClass->setCentralWidget(centralWidget);

        retranslateUi(XWindowsClass);

        toggleBtn->setDefault(true);


        QMetaObject::connectSlotsByName(XWindowsClass);
    } // setupUi

    void retranslateUi(QMainWindow *XWindowsClass)
    {
        XWindowsClass->setWindowTitle(QCoreApplication::translate("XWindowsClass", "XWindows", nullptr));
        label_logo->setText(QCoreApplication::translate("XWindowsClass", "XWindows", nullptr));
        label_controller->setText(QString());
        toggleBtn->setText(QCoreApplication::translate("XWindowsClass", "Turn OFF", nullptr));
        label_reconnect->setText(QCoreApplication::translate("XWindowsClass", "Attempting to reconnect...", nullptr));
        xboxBtn->setText(QString());
#if QT_CONFIG(tooltip)
        settingsBtn->setToolTip(QCoreApplication::translate("XWindowsClass", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        settingsBtn->setText(QString());
        label_verNum->setText(QCoreApplication::translate("XWindowsClass", "X.X", nullptr));
        label_footer->setText(QCoreApplication::translate("XWindowsClass", "www.github.com/Henduww", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XWindowsClass: public Ui_XWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XWINDOWS_H

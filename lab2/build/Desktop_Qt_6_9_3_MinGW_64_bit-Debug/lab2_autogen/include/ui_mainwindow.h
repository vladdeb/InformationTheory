/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QTextBrowser *tbrSrc;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *tedKey;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QTextBrowser *tbrKey;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QTextBrowser *tbrDest;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblSrc;
    QPushButton *btnSrc;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblDest;
    QPushButton *btnDest;
    QSpacerItem *verticalSpacer;
    QPushButton *btnEncrypt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(772, 568);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(widget_5);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        tbrSrc = new QTextBrowser(widget_5);
        tbrSrc->setObjectName("tbrSrc");

        horizontalLayout_4->addWidget(tbrSrc);


        verticalLayout_2->addWidget(widget_5);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName("widget_7");
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(widget_7);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        tedKey = new QLineEdit(widget_7);
        tedKey->setObjectName("tedKey");

        horizontalLayout_5->addWidget(tedKey);


        verticalLayout_2->addWidget(widget_7);

        widget_8 = new QWidget(widget_2);
        widget_8->setObjectName("widget_8");
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(widget_8);
        label->setObjectName("label");

        horizontalLayout_7->addWidget(label);

        tbrKey = new QTextBrowser(widget_8);
        tbrKey->setObjectName("tbrKey");

        horizontalLayout_7->addWidget(tbrKey);


        verticalLayout_2->addWidget(widget_8);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName("widget_6");
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(widget_6);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 0));

        horizontalLayout_6->addWidget(label_5);

        tbrDest = new QTextBrowser(widget_6);
        tbrDest->setObjectName("tbrDest");

        horizontalLayout_6->addWidget(tbrDest);


        verticalLayout_2->addWidget(widget_6);


        horizontalLayout->addWidget(widget_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lblSrc = new QLabel(widget_3);
        lblSrc->setObjectName("lblSrc");

        horizontalLayout_3->addWidget(lblSrc);

        btnSrc = new QPushButton(widget_3);
        btnSrc->setObjectName("btnSrc");

        horizontalLayout_3->addWidget(btnSrc);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblDest = new QLabel(widget_4);
        lblDest->setObjectName("lblDest");

        horizontalLayout_2->addWidget(lblDest);

        btnDest = new QPushButton(widget_4);
        btnDest->setObjectName("btnDest");

        horizontalLayout_2->addWidget(btnDest);


        verticalLayout->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnEncrypt = new QPushButton(widget);
        btnEncrypt->setObjectName("btnEncrypt");
        btnEncrypt->setEnabled(false);

        verticalLayout->addWidget(btnEncrypt);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 772, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(btnSrc, SIGNAL(clicked()), MainWindow, SLOT(load()));
        QObject::connect(btnDest, SIGNAL(clicked(bool)), MainWindow, SLOT(store()));
        QObject::connect(btnEncrypt, SIGNAL(clicked()), MainWindow, SLOT(encrypt()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\204\320\260\320\271\320\273               ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207                                ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \320\272\320\273\321\216\321\207", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202                          ", nullptr));
        lblSrc->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        btnSrc->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267...", nullptr));
        lblDest->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        btnDest->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262...", nullptr));
        btnEncrypt->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

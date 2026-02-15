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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *edKey;
    QPushButton *btnBrowse;
    QLabel *lblFileName;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPlainTextEdit *edSource;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QPlainTextEdit *edDest;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnChipher;
    QPushButton *btnDechipher;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rdbColumn;
    QRadioButton *rdbVigenere;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(554, 451);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::WeatherClear));
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout_3->addWidget(label_2);

        edKey = new QLineEdit(centralwidget);
        edKey->setObjectName("edKey");

        verticalLayout_3->addWidget(edKey);


        horizontalLayout->addLayout(verticalLayout_3);

        btnBrowse = new QPushButton(centralwidget);
        btnBrowse->setObjectName("btnBrowse");

        horizontalLayout->addWidget(btnBrowse);

        lblFileName = new QLabel(centralwidget);
        lblFileName->setObjectName("lblFileName");

        horizontalLayout->addWidget(lblFileName);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        edSource = new QPlainTextEdit(centralwidget);
        edSource->setObjectName("edSource");

        verticalLayout_2->addWidget(edSource);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        edDest = new QPlainTextEdit(centralwidget);
        edDest->setObjectName("edDest");

        verticalLayout_4->addWidget(edDest);


        verticalLayout->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnChipher = new QPushButton(centralwidget);
        btnChipher->setObjectName("btnChipher");

        horizontalLayout_2->addWidget(btnChipher);

        btnDechipher = new QPushButton(centralwidget);
        btnDechipher->setObjectName("btnDechipher");

        horizontalLayout_2->addWidget(btnDechipher);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        rdbColumn = new QRadioButton(centralwidget);
        rdbColumn->setObjectName("rdbColumn");
        rdbColumn->setChecked(true);

        verticalLayout_5->addWidget(rdbColumn);

        rdbVigenere = new QRadioButton(centralwidget);
        rdbVigenere->setObjectName("rdbVigenere");

        verticalLayout_5->addWidget(rdbVigenere);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 554, 25));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);
        QObject::connect(btnChipher, SIGNAL(clicked()), MainWindow, SLOT(cipher()));
        QObject::connect(btnDechipher, SIGNAL(clicked()), MainWindow, SLOT(decrypt()));
        QObject::connect(btnBrowse, SIGNAL(clicked()), MainWindow, SLOT(loadFile()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\204\321\200\320\260\321\202\320\276\321\200", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        btnBrowse->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\244\320\260\320\271\320\273", nullptr));
        lblFileName->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        btnChipher->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        btnDechipher->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        rdbColumn->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\273\320\261\321\206\320\276\320\262\321\213\320\271", nullptr));
        rdbVigenere->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\266\320\265\320\275\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

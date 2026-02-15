#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "funcs.h"
#include "ColumnCipher.h"
#include "vigenere.h"
#include <string>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cipher()
{
    std::wstring source = ui->edSource->toPlainText().toStdWString();
    std::wstring key = ui->edKey->displayText().toStdWString();
    source = prepareKey(source);
    key = prepareKey(key);
    if(0 == key.size()) {
        QMessageBox::warning(this, "Ошибка", "Ключ пустой");
        return;
    }
    if(ui->rdbColumn->isChecked()) {
        std::wstring res = ColumnCipher(source, key);
        ui->edDest->setPlainText(QString::fromStdWString(res));
        QFile file("output.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        QTextStream out(&file);
        out << res;
    }
    else {
        std::wstring res = vigenereEncrypt(source, key);
        ui->edDest->setPlainText(QString::fromStdWString(res));
        QFile file("output.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        QTextStream out(&file);
        out << res;
    }
}

void MainWindow::decrypt()
{
    std::wstring source = ui->edSource->toPlainText().toStdWString();
    std::wstring key = ui->edKey->displayText().toStdWString();
    source = prepareKey(source);
    key = prepareKey(key);
    if(0 == key.size()) {
        QMessageBox::warning(this, "Ошибка", "Ключ пустой");
        return;
    }
    if(ui->rdbColumn->isChecked()) {
        std::wstring res = ColumnDecipher(source, key);
        ui->edDest->setPlainText(QString::fromStdWString(res));
        QFile file("output.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        QTextStream out(&file);
        out << res;
    }
    else {
        std::wstring res = vigenereDecrypt(source, key);
        ui->edDest->setPlainText(QString::fromStdWString(res));
        QFile file("output.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }
        QTextStream out(&file);
        out << res;
    }
}

void MainWindow::loadFile() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Открыть файл"));
    if(!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        ui->lblFileName->setText(fileInfo.fileName());
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }
        QString content = file.readAll();
        ui->edSource->setPlainText(content);
        file.close();
    }
}

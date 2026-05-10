#include "mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "./ui_mainwindow.h"
#include "NumberTheory.h"
#include "solve.h"
#include <iomanip>

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

void MainWindow::setP()
{
    _p = ui->spbP->value();
    _r = _p * _q;
    _phi = (_p - 1) * (_q - 1);
    ui->spbD->setMaximum(_phi - 1);
}

void MainWindow::setQ()
{
    _q = ui->spbQ->value();
    _r = _p * _q;
    _phi = (_p - 1) * (_q - 1);
    ui->spbD->setMaximum(_phi - 1);
}

void MainWindow::setD()
{
    _d = ui->spbD->value();
}

void MainWindow::sign()
{
    if (!isPrime(_p)) {
        QMessageBox::warning(this, "Error", "p must be prime");
        return;
    }
    if (!isPrime(_q)) {
        QMessageBox::warning(this, "Error", "q must be prime");
        return;
    }
    if (std::gcd(_phi, _d) != 1) {
        QMessageBox::warning(this, "Error", "d must be coprime with phi");
        return;
    }
    QString name = QFileDialog::getOpenFileName(this, "Sing file");
    if (!name.isEmpty()) {
        ui->ledFile->setText(name);
        QFile file(name);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)) {
            return;
        }
        QTextStream ts(&file);
        _h = H(static_cast<std::uint64_t>(100), _r, ts, false);
        _sign = bpow(_h, _d, _r);
        ui->ledH->setText(QString::number(_h));
        ui->ledSign->setText(QString::number(_sign));
        ts << Qt::endl << _sign;
        file.close();
    }
}

void MainWindow::check()
{
    if (!isPrime(_p)) {
        QMessageBox::warning(this, "Error", "p must be prime");
        return;
    }
    if (!isPrime(_q)) {
        QMessageBox::warning(this, "Error", "q must be prime");
        return;
    }
    if (std::gcd(_phi, _d) != 1) {
        QMessageBox::warning(this, "Error", "d must be coprime with phi");
        return;
    }
    QString name = QFileDialog::getOpenFileName(this, "Sing file");
    if (!name.isEmpty()) {
        ui->ledFile->setText(name);
        QFile file(name);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Append | QIODevice::Text)) {
            return;
        }
        QTextStream ts(&file);
        _h = H(static_cast<std::uint64_t>(100), _r, ts, true);
        ts.seek(0);
        try {
            _sign = getSign(ts);
        } catch (std::runtime_error &e) {
            QMessageBox::warning(this, "Error", e.what());
            return;
        }

        _e = inverse(_d, _phi);
        std::uint64_t cmp = bpow(_sign, _e, _r);
        if (cmp == _h) {
            QMessageBox::information(this, "Result", "Sign correct");
        } else {
            QMessageBox::warning(this, "Result", "Sign incorrect");
        }
        ui->ledH->setText(QString::number(_h));
        ui->ledSign->setText(QString::number(_sign));
        ui->ledCmp->setText(QString::number(cmp));
        ui->ledE->setText(QString::number(_e));
        file.close();
    }
}

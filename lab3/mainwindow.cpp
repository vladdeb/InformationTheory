#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "NumberTheory.h"
#include <QFileDialog>
#include "elgamal.h"

#define RETURN_LEN 1024

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _data = new QStandardItemModel(0, 2, this);

    ui->tvAB->setModel(_data);
    QHeaderView *header = ui->tvAB->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    _data->setHorizontalHeaderItem(0, new QStandardItem(QString("a")));
    _data->setHorizontalHeaderItem(1, new QStandardItem(QString("b")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setP(int p) {
    _p = static_cast<std::uint64_t>(p);
    ui->spbK->setMaximum(p - 1);
    ui->spbX->setMaximum(p - 2);
}

void MainWindow::setG(int index) {
    if(index == -1) return;
    _g = static_cast<std::uint64_t>(ui->cmbG->currentData().toInt());
}

void MainWindow::setK(int k) {
    _k = static_cast<std::uint64_t>(k);
}

void MainWindow::setX(int x) {
    _x = static_cast<std::uint64_t>(x);
}

void MainWindow::getG() {
    if(!isPrime(_p))  {
        ui->cmbG->clear();
        ui->lblTotalG->setText("Total roots: ");
        QMessageBox::warning(this, "Error", "P must be prime");
        return;
    }
    auto roots = getPrimaryRoots(_p);
    ui->cmbG->clear();
    for(auto g: roots) {
        ui->cmbG->addItem(QString::number(g), QVariant(g));
    }
    emit ui->cmbG->activated(ui->cmbG->currentIndex());
    ui->lblTotalG->setText("Total roots: " + QString::number(roots.size()));
}

void MainWindow::selectIn() {
    inPath = QFileDialog::getOpenFileName(this,
                                        tr("Открыть файл"));
    if(!inPath.isEmpty()) {
        ui->ledInput->setText(inPath);
    }
}

void MainWindow::selectOut() {
    outPath = QFileDialog::getSaveFileName(this,
                                          tr("Открыть файл"));
    if(!outPath.isEmpty()) {
        ui->ledOutput->setText(outPath);
    }
}

void MainWindow::encrypt() {
    if(ui->cmbG->currentIndex() == -1) {
        QMessageBox::warning(this, "Error", "Choose g");
        return;
    }
    if(!isPrime(_p)) {
        QMessageBox::warning(this, "Error", "p must be prime");
        return;
    }
    if(inPath.isEmpty() || outPath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Choose input and output files");
        return;
    }
    if(std::gcd(_k, _p - 1) != 1) {
        QMessageBox::warning(this, "Error", "gcd(p - 1, k) must be 1");
        return;
    }
    try {
        auto ab = elgamal::encrypt(inPath, outPath, _p, _g, _k, _x, RETURN_LEN);
        int row = 0;
        _data->removeRows(0, _data->rowCount());
        for(auto [a, b]: ab) {
            _data->insertRow(row);
            _data->setData(_data->index(row, 0), a);
            _data->setData(_data->index(row, 1), b);
            row++;
        }
    }
    catch(std::runtime_error& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::decrypt() {
    if(ui->cmbG->currentIndex() == -1) {
        QMessageBox::warning(this, "Error", "Choose g");
        return;
    }
    if(!isPrime(_p)) {
        QMessageBox::warning(this, "Error", "p must be prime");
        return;
    }
    if(inPath.isEmpty() || outPath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Choose input and output files");
        return;
    }
    if(std::gcd(_k, _p - 1) != 1) {
        QMessageBox::warning(this, "Error", "gcd(p - 1, k) must be 1");
        return;
    }
    try {
        auto ab = elgamal::decrypt(inPath, outPath, _p, _g, _k, _x, RETURN_LEN);
        int row = 0;
        _data->removeRows(0, _data->rowCount());
        for(auto [a, b]: ab) {
            _data->insertRow(row);
            _data->setData(_data->index(row, 0), a);
            _data->setData(_data->index(row, 1), b);
            row++;
        }
    }
    catch(std::runtime_error& e) {
        QMessageBox::warning(this, "Error", e.what());
    }

}

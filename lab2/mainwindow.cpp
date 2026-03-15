#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <sstream>
#include <bitset>
#include <algorithm>
#include "encrypter.h"

#define PREVIEW_SIZE 1024

std::vector<bool> p(31, false);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _encrypter(Encrypter(_src, _dest, {}, {}))
{
    ui->setupUi(this);
    p[2] = true;
    p[30] = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string toBin(const char *buf, int n) {
    std::stringstream ss;
    for(int i = 0; i < n; ++i) {
        ss << std::bitset<8>(buf[i]);
    }
    std::string content;
    ss >> content;
    return content;
}

void MainWindow::load() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Открыть файл"));
    if(!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        ui->lblSrc->setText(fileInfo.fileName());
        if(_src.isOpen()){
            _src.close();
        }
        _src.setFileName(fileName);
        if (!_src.open(QIODevice::ReadOnly)) {
            return;
        }
        //char buf[PREVIEW_SIZE + 1] = {0};
        int retval;
        if((retval = _src.read(buf, PREVIEW_SIZE)) == -1) {
            return;
        }
        std::string content = toBin(buf, retval);
        _src.seek(0);
        ui->tbrSrc->setText(QString::fromStdString(content));
        _src.close();
        _l = true;
        if(_l && _s) {
            ui->btnEncrypt->setEnabled(true);
        }
    }
}

void MainWindow::store() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Открыть файл"));
    if(!fileName.isEmpty()) {
        QFileInfo fileInfo(fileName);
        ui->lblDest->setText(fileInfo.fileName());
        _destStr = fileName;
        _s = true;
        if(_l && _s) {
            ui->btnEncrypt->setEnabled(true);
        }
    }
}

void MainWindow::encrypt() {
    std::string result;
    std::string key;
    _dest.setFileName(_destStr);
    if(!_dest.open(QFile::WriteOnly)) {
        return;
    }
    if (!_src.open(QIODevice::ReadOnly)) {
        _dest.close();
        return;
    }
    QString userKey = ui->tedKey->text();
    int i, skip;
    for(i = 0, skip = 0; i + skip < userKey.size(); ){
        if(userKey[i + skip] != '1' && userKey[i + skip] != '0') {
            skip++;
            continue;
        }
        userKey[i] = userKey[i + skip];
        i++;
    }
    userKey.resize(std::min(i, (int)p.size()));
    while(userKey.size() < p.size()) {
        userKey += '0';
    }
    _encrypter._lsfr = LSFR(userKey.toStdString(), p);
    LSFR lsfr(userKey.toStdString(), p);
    for(int i = 0; i < std::min(PREVIEW_SIZE, (int)_src.size()) * 8; ++i) {
        key += lsfr.GetNextBit() + '0';
    }
    _encrypter.Encrypt(result, PREVIEW_SIZE);
    ui->tbrDest->setText(QString::fromStdString(toBin(result.c_str(), (int)result.size())));
    ui->tbrKey->setText(QString::fromStdString(key.c_str()));
    _src.close();
    _dest.close();
}

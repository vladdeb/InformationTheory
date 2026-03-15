#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "encrypter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Encrypter _encrypter;
    bool _l = 0, _s = 0;
    QFile _src;
    QString _destStr;
    QFile _dest;

private slots:
    void load();
    void store();
    void encrypt();

};
#endif // MAINWINDOW_H

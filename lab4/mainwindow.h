#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdint>

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
    std::uint64_t _p = 11, _q = 11, _r = 121, _h, _sign, _d = 2, _e, _phi = 100;
private slots:
    void sign();
    void setP();
    void setQ();
    void setD();
    void check();
};
#endif // MAINWINDOW_H

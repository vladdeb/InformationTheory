#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

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
    std::uint64_t _p = 257;
    std::uint64_t _g = -1;
    std::uint64_t _k = 1;
    std::uint64_t _x = 2;
    QString inPath = "";
    QString outPath = "";
    QStandardItemModel *_data;

private slots:
    void getG();
    void selectIn();
    void selectOut();
    void encrypt();
    void decrypt();
    void setP(int);
    void setG(int);
    void setK(int);
    void setX(int);
};
#endif // MAINWINDOW_H

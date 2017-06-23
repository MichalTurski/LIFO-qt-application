#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_wypiszButton_clicked();

    void on_zapiszButton_clicked();

private:
    Ui::MainWindow *ui;
    std::stack <QString> lifoQueue;
};

#endif // MAINWINDOW_H

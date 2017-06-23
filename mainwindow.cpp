#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->outputField->setReadOnly(true);
    ui->inputField->setPlaceholderText("Tu wprowadź tekst");
    ui->outputField->setPlaceholderText("Tu będzie prezentowane wyjście");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_wypiszButton_clicked()
{
    if(!lifoQueue.empty()){
        ui->outputField->setPlainText(lifoQueue.top());
        lifoQueue.pop();
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Błąd","Kolejka jest pusta, wprowadź kolejny element i spróbuj ponownie");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::on_zapiszButton_clicked()
{
    QString str = ui->inputField->toPlainText();
    if(str.isEmpty())
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Błąd","Nie można wprowadzić pustego tekstu");
        messageBox.setFixedSize(500,200);
    }
    else{
        lifoQueue.push(str);
        ui->inputField->clear();
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <map>
#include <QString>
#include <QProgressBar>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimer>
#include <QRadioButton>
#include <QTimeEdit>

const int length = 7;
QString arrComboBox[length];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arrComboBox[0] = "progressbar";
    arrComboBox[1] = "textarea";
    arrComboBox[2] = "timer";
    arrComboBox[3] = "pushbotton";
    arrComboBox[4] = "label";
    arrComboBox[5] = "textbox";
    arrComboBox[6] = "radiobutton";
    for(int i = 0; i < length; i++){
        ui->comboBox->addItem(arrComboBox[i]);
    }
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onAddWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddWidget()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->verticalLayout->layout());
    QPushButton* button = new QPushButton("hi");
    layout->addWidget(button);
    connect(button, &QPushButton::clicked, this, &MainWindow::onRemoveWidget);
}

void MainWindow::onRemoveWidget()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    delete button;
}
void MainWindow::on_pushButton_2_clicked()
{
    //QMessageBox::information(this, "you choose",arrComboBox[ui->comboBox->currentIndex()]);
    /*if(ui->comboBox->currentText()  == "progressbar"){
        test.setValue(50);
        QWidget widget = test;
        ui->setupUi(&widget);
    }*/
    //map<string,int> stringCounts;
    //qDebug(arrComboBox[ui->comboBox->currentIndex()])
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->verticalLayout->layout());
    if(ui->comboBox->currentText() == "progressbar")
    {
        /////////////////////////////////////
    }
    else if(ui->comboBox->currentText() == "textarea")
    {
        QTextEdit* te = new QTextEdit("NEW TEXT AREA");
        layout->addWidget(te);
    }
    else if(ui->comboBox->currentText() == "timer")
    {
        qDebug("timer");
        QTimeEdit* te = new QTimeEdit();
        layout->addWidget(te);

    }
    else if(ui->comboBox->currentText() == "pushbotton")
    {
        QPushButton* button = new QPushButton("NEW BUTTON");
        layout->addWidget(button);
    }
    else if(ui->comboBox->currentText() == "label")
    {
        QLabel* l = new QLabel("NEW LABEL");
        layout->addWidget(l);
    }
    else if(ui->comboBox->currentText() == "textbox"){
        QLineEdit* le = new QLineEdit("NEW TEXT BOX");
        layout->addWidget(le);
    }
    else if(ui->comboBox->currentText() == "radiobutton"){
        QRadioButton* rb = new QRadioButton("NEW RADIO BUTTON");
        layout->addWidget(rb);
    }
}

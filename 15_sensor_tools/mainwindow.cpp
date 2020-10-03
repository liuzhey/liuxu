#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QMessageBox>
#include <QLatin1String>
#include "sensor.h"
#include "form.h"
#include "QKeyEvent"

int MainWindow:: exchange_the_hex(uint hex)
{
    QString str;
    ui->textBrowser->clear();
    str.append("无安全攻击\n");
    if(hex){
        str.clear();
        if(hex & 0x80000000)
             str.append("安全域数据丢失(或未清过安全)\n");
        for(int i = 0; i <= 20;i++){
            if(hex & (1 << i)){
                if(i < 6)
                    str.append(QString("外部第%1路触发\n").arg(i));
                else if(i >=6 && i <= 10){
                    str.append(err_list[i - 6]);
                }
                else{
                  str.append(err_list[i - 10]);
                }
            }
        }
        ui->textBrowser->setText(str);
        return 0;
    }
    else{
        ui->textBrowser->setText(str);
        return 1;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene2 = new Form;
    setWindowIcon(QIcon(":/sample/ranbe.png"));
    setWindowTitle("安全寄存器查询工具");
    this->setFixedSize(500,500);
    connect(ui->exit_action,&QAction::triggered,[=](){
        scene2->show();
    });
    connect(ui->btn_cacel,&QPushButton::clicked,[=](){
        ui->lineEdit->clear();
        ui->textBrowser->clear();
    });

    connect(ui->btn_enter,&QPushButton::clicked,[=](){
       QString str = ui->lineEdit->text();
       if(str.length() != 8){
           QMessageBox::warning(this,"warning","请输入格式正确的寄存器值");   //警告
       }
       else{
            bool ok = true;
            int i = 0;
            QByteArray b = str.toLatin1();
            for (i = 0; i < b.length(); i++ )
            {
                if (!(65 <= b[i]  &&  70 >= b[i] ) && !(48 <= b[i]  && 57 >= b[i]) && !(97 <= b[i]  && 102 >= b[i]))
                {
                   break;
                }
            }
            if(i != b.length()){
                QMessageBox::warning(this,"warning","请输入格式正确的寄存器值");   //警告
            }
            else{
                uint b_hex = b.toUInt(&ok,16);
                exchange_the_hex(b_hex);
            }
       }
    });
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Return){
        QString str = ui->lineEdit->text();
        if(str.length() != 8){
            QMessageBox::warning(this,"warning","请输入格式正确的寄存器值");   //警告
        }
        else{
             bool ok = true;
             int i = 0;
             QByteArray b = str.toLatin1();
             for (i = 0; i < b.length(); i++ )
             {
                 if (!(65 <= b[i]  &&  70 >= b[i] ) && !(48 <= b[i]  && 57 >= b[i]) && !(97 <= b[i]  && 102 >= b[i]))
                 {
                    break;
                 }
             }
             if(i != b.length()){
                 QMessageBox::warning(this,"warning","请输入格式正确的寄存器值");   //警告
             }
             else{
                 uint b_hex = b.toUInt(&ok,16);
                 exchange_the_hex(b_hex);
             }
        }
    }
    else if(ev->key() == Qt::Key_Escape){
        ui->lineEdit->clear();
        ui->textBrowser->clear();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

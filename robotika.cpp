#include "robotika.h"
#include "ui_robotika.h"
#include <QDebug>

Robotika::Robotika(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Robotika)
{
    ui->setupUi(this);
    this->ui->lcdNumber->display("00:00");
    this->ui->lcdNumberT1->display("000000");
    this->ui->lcdNumberT2->display("000000");

    this->ui->lcdNumber_2->display("00:00");
    this->point=0;
    this->point2=0;

    this->ui->lcdNumber->setFixedSize(200,100);
    this->ui->lcdNumberT1->setFixedSize(200,100);
    this->ui->lcdNumberT2->setFixedSize(200,100);
    this->ui->lcdNumber_2->setFixedSize(200,100);
    this->ui->webView->setFixedSize(1000,250);
}

Robotika::~Robotika()
{
    delete ui;
}

void Robotika::on_pushButton_clicked()
{
    timer = new QTimer();
    timeValue = new QTime(0,3,0);
    ui->lcdNumber->display(timeValue->toString());
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    this->timer->start(1000);
    this->point=0;
    this->point2=0;
    this->ui->lcdNumberT1->display("000000");
    this->ui->lcdNumberT2->display("000000");
    this->ui->pushButton_3->hide();

    this->timer2->stop();
    this->ui->lcdNumber_2->display("00:00");
}

void Robotika::showTime(){
    this->timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
    ui->lcdNumber->display(this->timeValue->toString());
}


void Robotika::on_pushButton_2_clicked()
{
    this->timer->stop();
    this->ui->lcdNumber->display("00:00");
    this->ui->pushButton_3->show();
}


void Robotika::on_btnPoint100A_2_clicked()
{
    int p=50;
    if (p==50){
        point+=50;
    }
    this->ui->lcdNumberT1->display(point);
}

void Robotika::on_btnPoint50A_clicked()
{
    int p=100;
    if (p==100){
        point+=100;
    }
    this->ui->lcdNumberT1->display(point);
}

void Robotika::on_pushButton_5_clicked()
{
    int p2=50;
    if (p2==50){
        point2+=50;
    }
    this->ui->lcdNumberT2->display(point2);

}

void Robotika::on_pushButton_6_clicked()
{
    int p2=100;
    if (p2==100){
        point2+=100;
    }
    this->ui->lcdNumberT2->display(point2);
}

void Robotika::on_pushButton_9_clicked()
{
    int p2=10;
    if (p2==10){
        point2-=10;
    }
    this->ui->lcdNumberT2->display(point2);
}

void Robotika::on_pushButton_10_clicked()
{
    int p2=5;
    if (p2==5){
        point2-=5;
    }
    this->ui->lcdNumberT2->display(point2);
}

void Robotika::on_pushButton_7_clicked()
{
    int p=10;
    if (p==10){
        point-=10;
    }
    this->ui->lcdNumberT1->display(point);
}

void Robotika::on_pushButton_8_clicked()
{
    int p=5;
    if (p==5){
        point-=5;
    }
    this->ui->lcdNumberT1->display(point);
}

void Robotika::on_pushButton_3_clicked()
{
    timer2 = new QTimer();
    timeValue2 = new QTime(0,1,0);
    ui->lcdNumber_2->display(timeValue2->toString());
    connect(timer2, SIGNAL(timeout()), this, SLOT(showTimePrepare()));
    this->timer2->start(1000);
}

void Robotika::showTimePrepare(){
    this->timeValue2->setHMS(0,this->timeValue2->addSecs(-1).minute(),this->timeValue2->addSecs(-1).second());
    ui->lcdNumber_2->display(this->timeValue2->toString());

   }

void Robotika::on_pushButton_4_clicked()
{
    this->timer2->stop();
    this->ui->lcdNumber_2->display("00:00");
}



void Robotika::on_toolButton_clicked()
{

     img1 = QFileDialog::getOpenFileName(this, tr("Open Picture"), "/home/", "*.png *.jpg *.jpeg *.bmp");
     this->ui->lineEdit_3->setText(img1);

}

void Robotika::on_toolButton_2_clicked()
{
    img2 = QFileDialog::getOpenFileName(this, tr("Open Picture"), "/home/", "*.png *.jpg *.jpeg *.bmp");
    this->ui->lineEdit_4->setText(img2);
}

void Robotika::on_pushButton_12_clicked()
{
    imgScene1 = new QGraphicsScene(this->ui->graphicsView_3);
    this->ui->graphicsView_3->setScene(imgScene1);
    QPixmap imgPic1 (this->img1);
    imgScene1->addPixmap(imgPic1);
    QString teamA =  this->ui->lineEdit->text();
    QString format ="<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">"+teamA+"</span></p></body></html>";
    this->ui->label_2->setText(format);
    if (teamA==""){
        QMessageBox::warning(0, "Peringatan", "Maaf Nama Team A Kosong");
    }
}

void Robotika::on_pushButton_13_clicked()
{
    imgScene2 = new QGraphicsScene(this->ui->graphicsView_2);
    this->ui->graphicsView_2->setScene(imgScene2);
    QPixmap imgPic2 (this->img2);
    QString teamB = this->ui->lineEdit_2->text();
    QString formatb ="<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">"+teamB+"</span></p></body></html>";
    imgScene2->addPixmap(imgPic2);
    this->ui->label_3->setText(formatb);
    if (teamB==""){
        QMessageBox::warning(0, "Peringatan", "Maaf Nama Team B Kosong");
    }
}

#ifndef ROBOTIKA_H
#define ROBOTIKA_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QGraphicsScene>
namespace Ui {
class Robotika;
}

class Robotika : public QMainWindow
{
    Q_OBJECT

public:
    explicit Robotika(QWidget *parent = 0);
    ~Robotika();
    QTimer* timer;
    QTimer* timer2;
    QTime*  timeValue;
    QTime*  timeValue2;
    int point;
    int point2;

private slots:
    void on_pushButton_clicked();
    void showTime();
    void showTimePrepare();
    void on_pushButton_2_clicked();

    void on_btnPoint100A_2_clicked();

    void on_btnPoint50A_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::Robotika *ui;

    QString img1;
    QString img2;

    QGraphicsScene *imgScene1;
    QGraphicsScene *imgScene2;
};

#endif // ROBOTIKA_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algotirm.h"
#include <QMessageBox>
algotirm Target;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    countShoot = 0;
    countHit = 0;
    ui->label_4->setText(QString::number(countHit));
    ui->label_3->setText(QString::number(countShoot));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
        painter.drawRect(Target.getRad(), Target.getRad(), Target.getRad(), Target.getRad());
        painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
        painter.drawPie(Target.getRad(), Target.getRad(), Target.getRad()*2, Target.getRad()*2, 1, -90*16);
        painter.setBrush(QBrush(Qt::white   , Qt::SolidPattern));
        painter.drawEllipse(0, 0, Target.getRad()*2, Target.getRad()*2);


        painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
        painter.setBrush(QBrush(Qt::red   , Qt::SolidPattern));
        painter.drawEllipse(lastPoint.x(), lastPoint.y(), 10, 10);

}



void MainWindow::on_shootButton_clicked()
{
    QString NumX = ui->lineEdit->text();
    bool okX;
    int decX = NumX.toInt(&okX, 10);
    QString NumY = ui->lineEdit_2->text();
    bool okY;
    int decY = NumX.toInt(&okY, 10);
    if(decX >= 1 && decX <= 9999 && decY >= 1 && decY <= 9999) {
        lastPoint.setX(decX);
        lastPoint.setY(decY);
        Target.hit(Target.getRad(), decX, decY);
        if (Target.getCheckCircuit() && Target.getCheckSquare()) {
                countHit++;
                countMoves();
                ui->label_4->setText(QString::number(countHit));
                Target.setCheckSquare(false);
                Target.setCheckCircuit(false);
            }
        else if (Target.getCheckSemicircle()) {
            countHit++;
            countMoves();
            ui->label_4->setText(QString::number(countHit));
            Target.setCheckSemicircle(false);
            Target.setCheckSquare(false);
            Target.setCheckCircuit(false);
            }
        else {
            countMoves();
            Target.setCheckSquare(false);
            Target.setCheckCircuit(false);
            Target.setCheckSemicircle(false);
        }
        repaint();
        }
        else {
           QMessageBox::critical(this, "", "Error! Enter wrong number!");
        }
}


void MainWindow::countMoves()
{
    countShoot++;
    ui->label_3->setText(QString::number(countShoot));
}

void MainWindow::on_radiusButton_clicked()
{
    QString NumRad = ui->lineEdit_3->text();
    bool okRad;
    int decRad = NumRad.toInt(&okRad, 10);
    if(decRad >= 1 && decRad <= 300) {
        Target.setRad(decRad);
        repaint();
        }
        else {
           QMessageBox::critical(this, "", "Error! Enter wrong number!");
        }
}

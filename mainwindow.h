#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event) override;
    void countMoves();

private slots:

    void on_shootButton_clicked();

    void on_radiusButton_clicked();

private:
    int countShoot;
    int countHit;
    QPoint lastPoint;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

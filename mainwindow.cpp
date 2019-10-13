#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mOpenCV = new MyVideoCapture(this);
    connect(mOpenCV,&MyVideoCapture::newPixmapCapture,this,[&](){
        ui->label_1->setPixmap(mOpenCV->pixmap());
        ui->label_1->setScaledContents(true);
        ui->label_2->setPixmap(mOpenCV->pixmapDif());
        ui->label_2->setScaledContents(true);
        ui->label_3->setPixmap(mOpenCV->pixmapDST());
        ui->label_3->setScaledContents(true);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    mOpenCV->terminate();
}

void MainWindow::on_pushButton_clicked()
{
    mOpenCV->start(QThread::HighPriority);
}

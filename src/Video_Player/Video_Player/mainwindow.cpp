#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    display = new QVideoWidget(this);
    player->setVideoOutput(display);
    this->setCentralWidget(display);
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
    // temporary - program should calculate procentage of length
    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionChoose_file_triggered()
{
    QString File = QFileDialog::getOpenFileName(this, tr("Choose film file"),"",tr("Video File (*.*)"));
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(File));

    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
}

void MainWindow::on_fileButton_clicked()
{
on_actionChoose_file_triggered();
}

void MainWindow::on_PlayButton_clicked()
{
on_actionPlay_triggered();
}

void MainWindow::on_stopButton_clicked()
{
on_actionStop_triggered();
}


void MainWindow::on_pauseButton_clicked()
{
    on_actionPause_triggered();
}

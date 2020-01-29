#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDockWidget>
#include <QGraphicsDropShadowEffect>
#include <QStyle>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    auto display = new QGraphicsView(scene);
    player = new QMediaPlayer(this);
    item = new QGraphicsVideoItem;
    player->setVideoOutput(item);
    scene->addItem(item);
    this->setCentralWidget(display);
    display->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);

    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
    // temporary - program should calculate procentage of lengt
    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::valueChanged,player,&QMediaPlayer::setPosition);


    //volume
    volume = new QSlider(this);
    volume->setOrientation(Qt::Horizontal);
    volume->setMaximum(100);
    volume->setValue(50);
    volume->setStyleSheet("color:red;");
    connect(volume, &QSlider::valueChanged,player,&QMediaPlayer::setVolume);
    ui->statusBar->addPermanentWidget(volume);
    //buttons
    ui->mainToolBar->addWidget(ui->PlayButton);
    ui->mainToolBar->addWidget(ui->pauseButton);
    ui->mainToolBar->addWidget(ui->stopButton);
    ui->mainToolBar->addWidget(ui->FullScreenButton);

    ui->pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->PlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));


    subtitle = new QLabel(display);
   // display->setAlignment()
    subtitle->setStyleSheet("color: white; font-family: 'Helvetica Neue'; text-shadow: 10px black; font-size: 30px;");
    subtitle->setWordWrap(true);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(0);
    effect->setColor(QColor("#000000"));
    effect->setOffset(5,5);
    subtitle->setGraphicsEffect(effect);
    subtitle->setText("Napisy, napisy, napisy, napisy, napisy, napisy, napisy, napisy, napisy, napisy, napisy, napisy, napisy ");
    subtitle->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
    subtitle->setWindowFlags(Qt::FramelessWindowHint);
    //subtitle->setAttribute(Qt::WA_OpaquePaintEvent);
    subtitle->setAttribute(Qt::WA_NoSystemBackground,true);
    subtitle->resize(MainWindow::width()/2, MainWindow::height()-150);
    subtitle->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
    item->setSize(this->size());



}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_subtitle_change()
{


}

void MainWindow::on_subtitle_choosen()
{


    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::on_subtitle_change);
    connect(slider,&QSlider::valueChanged,this,&MainWindow::on_place_change);
}

void MainWindow::on_place_change()
{


}

void MainWindow::on_actionChoose_file_triggered()
{
    QString File = QFileDialog::getOpenFileName(this, tr("Choose film file"),"",tr("Video File (*.avi *.3gp *.mp4 *.flv *.ogv *.webm)"));
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

void MainWindow::on_actionFullScreen_triggered()
{
    if (!isFullScreen())
    {
    this->setWindowFlags( Qt::FramelessWindowHint);
    ui->mainToolBar->hide();
    ui->statusBar->hide();
    ui->menuBar->hide();
    this->showFullScreen();
    }
    else
    {
        Qt::WindowFlags flags;
        flags = flags & (~Qt::FramelessWindowHint);
        this->setWindowFlags(flags);
        ui->mainToolBar->show();
        ui->statusBar->show();
        ui->menuBar->show();
        this->showNormal();
    }
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


void MainWindow::keyPressEvent(QKeyEvent *key)
{
    if((key->key()==Qt::Key_Escape ||key->key()==Qt::Key_T))
    {
        on_actionFullScreen_triggered();
    }

}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    subtitle->setGeometry(MainWindow::width()/4,0,0,0);
    subtitle->resize(MainWindow::width()/2, MainWindow::height()-150);
    item->setSize(this->centralWidget()->size());
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_FullScreenButton_clicked()
{
    on_actionFullScreen_triggered();
}


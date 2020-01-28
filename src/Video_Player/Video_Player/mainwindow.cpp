#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDockWidget>
#include <QStyle>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    QWidget* cw= new QWidget;
//    QDockWidget *dockWidget = new QDockWidget(tr("Dock Widget"), this);
//    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
//                                   Qt::RightDockWidgetArea);
//    //dockWidget->setWidget(dockWidgetContents);
//    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    ui->setupUi(this);
    player = new QMediaPlayer(this);
    display = new VideoWidget(this);
    player->setVideoOutput(display);
    this->setCentralWidget(display);




    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);

    ui->statusBar->addPermanentWidget(slider);
    // temporary - program should calculate procentage of lengt
    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::valueChanged,player,&QMediaPlayer::setPosition);
    connect(display,&VideoWidget::fullscreen_return,this,&MainWindow::on_fullscreen_return);





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

    ui->pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->PlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    subtitle = new QLabel(display);
    subtitle->setStyleSheet("color: white");
    subtitle->setText("Napisy, napisy, napisy");
    subtitle->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    //subtitle->setAlignment(Qt::AlignCenter | Qt::AlignBottom);

    //display->setLocale()

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionChoose_file_triggered()
{
    QString File = QFileDialog::getOpenFileName(this, tr("Choose film file"),"",tr("Video File (*.avi *.3gp *.mp4 *.flv *.ogv *.webm)"));
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(File));
    on_actionPlay_triggered();
}

void MainWindow::on_fullscreen_return()
{
    qDebug()<<"XD";

    for (int i=0; i<100;++i)
    {
    display->setParent(nullptr);
    display->setParent(this);
    display->setFullScreen(0);
    display->showNormal();
    this->setCentralWidget(display);
    }
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

    display->setParent(nullptr);
    display->showFullScreen();

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
    if(key->key()==Qt::Key_Escape ||key->key()==Qt::Key_T )
    {
        on_actionFullScreen_triggered();
    }

}

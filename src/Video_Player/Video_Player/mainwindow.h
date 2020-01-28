#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "videowidget.h"
#include <QFileDialog>
#include <QSlider>
#include <QKeyEvent>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:



    void on_actionChoose_file_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionFullScreen_triggered();

    void on_fileButton_clicked();

    void on_PlayButton_clicked();

    void on_stopButton_clicked();

    void on_pauseButton_clicked();

    void on_fullscreen_return();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    VideoWidget* display;
    QSlider* volume;
    QSlider* slider;
};

#endif // MAINWINDOW_H

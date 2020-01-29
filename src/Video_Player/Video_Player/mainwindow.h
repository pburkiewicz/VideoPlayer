#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "videowidget.h"
#include <QFileDialog>
#include <QSlider>
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QGraphicsVideoItem>
#include <QGraphicsView>
#include "subtitles.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:

    void keyPressEvent(QKeyEvent* key)override;
     void resizeEvent(QResizeEvent *event)override;

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

    void on_FullScreenButton_clicked();

    void on_subtitle_change();

    void on_place_change();

    void on_subtitle_choosen();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QGraphicsView* display;
    QSlider* volume;
    QSlider* slider;
    QLabel* subtitle;
    QGraphicsScene* scene;
    QGraphicsVideoItem * item;
    Subtitles subs;
};

#endif // MAINWINDOW_H

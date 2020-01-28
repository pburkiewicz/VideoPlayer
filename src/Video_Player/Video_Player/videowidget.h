#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QVideoWidget>
#include <QDebug>

class VideoWidget : public QVideoWidget
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* key);

private:
    QWidget* my_parent;

signals:
    void fullscreen_return();

public slots:
};

#endif // VIDEOWIDGET_H


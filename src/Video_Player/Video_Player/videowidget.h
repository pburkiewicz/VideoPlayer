#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QDebug>

class VideoWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* key) override;


private:
    QWidget* my_parent;

signals:
    void fullscreen_return();

public slots:
};

#endif // VIDEOWIDGET_H


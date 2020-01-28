#include "videowidget.h"

VideoWidget::VideoWidget(QWidget *parent) : QVideoWidget(parent)
{
    my_parent=parent;
}

void VideoWidget::keyPressEvent(QKeyEvent *key)
{
     qDebug()<<"I'm here";
    if(key->key()==Qt::Key_Escape && isFullScreen())
    {
        qDebug()<<"Or here!!";
        setFullScreen(false);
        setParent(my_parent);
        emit fullscreen_return();
        key->accept();
    }
    else {
        key->ignore();
    }
}

#include "Task38_3.h"

Task38_3::Task38_3(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QImage blurImage(QImage sourse,int &b) 
{
    if (sourse.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(sourse));
    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(b);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(sourse.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0,0, sourse.width(), sourse.height()));
    return result;
}
void Task38_3::workingPicture(QImage pix, int numBlure)
{
    ui.label->setPixmap(QPixmap::fromImage(blurImage(p, numBlure).scaled(ui.label->width(), ui.label->height(), Qt::KeepAspectRatio)));
}

Task38_3::~Task38_3()
{}



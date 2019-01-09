#include "imageprovider.h"

ImageProvider::ImageProvider(ImageType type, Flags flags) : QQuickImageProvider(type, flags)
{

}

QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {

    int width = 100;
    int height = 50;

    if(size){
        *size = QSize(height, width);
    }
    QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
                   requestedSize.height() > 0 ? requestedSize.height() : height);
    pixmap.fill(QColor(id).rgba());
    return pixmap;
};

QImage requestImage(const QString& id, QSize* size, const QSize& requestedSize){

    return QImage(100, 50, QImage::Format_ARGB32);
};

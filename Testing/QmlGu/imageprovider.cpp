#include "imageProvider.h"

using namespace std;

ImageProvider::ImageProvider(ImageType type, Flags flags)
    : QQuickImageProvider(type, flags)
{
}

QPixmap ImageProvider::requestPixmap(const QString& id,
                                     QSize* size,
                                     const QSize& requestedSize)
{
    int width = 100;
    int height = 50;

    if (size)
    {
        *size = QSize(width, height);
    }

    QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
                   requestedSize.height() > 0 ? requestedSize.height() :
                                                height);
    pixmap.fill(QColor(id).rgba());
    QPainter painter(&pixmap);
    QFont f = painter.font();
    f.setPixelSize(20);
    painter.setFont(f);
    painter.setPen(Qt::black);
    if (requestedSize.isValid())
        painter.scale(requestedSize.width() / width,
                      requestedSize.height() / height);
    painter.drawText(QRectF(0, 0, width, height), Qt::AlignCenter, id);

    return pixmap;
}

QImage ImageProvider::requestImage(const QString& id,
                                   QSize* size,
                                   const QSize& requestedSize)
{
    return QImage(10000, 10000, QImage::Format_ARGB32);
}

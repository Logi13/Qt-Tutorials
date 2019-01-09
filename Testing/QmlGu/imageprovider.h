#ifndef IMAGE_PROVIDER_H
#define IMAGE_PROVIDER_H

#include <QQuickImageProvider>
#include <QPixmap>
#include <QPainter>

class ImageProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    explicit ImageProvider(ImageType type, Flags flags = 0);
    QPixmap requestPixmap(const QString& id,
                          QSize* size,
                          const QSize& requestedSize);
    QImage requestImage(const QString& id,
                        QSize* size,
                        const QSize& requestedSize);
};
#endif // IMAGE_PROVIDER_H

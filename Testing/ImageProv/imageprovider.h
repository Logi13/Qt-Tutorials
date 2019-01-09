#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QPixmap>
#include <QPainter>

class ImageProvider : public QQuickImageProvider
{
    Q_OBJECT
public:
    ImageProvider(ImageType type, Flags flags = nullptr);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override;
    QImage requestImage(const QString &id, QSize *sieze, const QSize &requestedSize) override;
};

#endif // IMAGEPROVIDER_H

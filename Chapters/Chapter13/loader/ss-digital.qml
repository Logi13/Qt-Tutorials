import QtQuick 2.5

Loader {
    id: loader

    focus: true

    source: "main.qml"

    onLoaded: {
        setSize(loader.item.width, loader.item.height);
        shorty.sendMouseClick(500, 350);
        shootWithDelay(1500);
    }
}

import QtQuick 2.0

Loader {
    id: root
    source: 'http://localhost:8000/main.qml'
    onLoaded: {
        root.width = item.width
        root.height = item.height
    }
}

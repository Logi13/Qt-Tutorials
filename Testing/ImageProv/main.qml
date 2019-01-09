import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Column {
        Image { source: "image://colors/yellow" }
        Image { source: "image://colors/red" }
    }
}

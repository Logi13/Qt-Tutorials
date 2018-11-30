import QtQuick 2.9
import QtQuick.Window 2.2
import Qt.labs.settings 1.0
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle {
        id: root
        width: 320; height: 240
        color: settings.color
        Settings {
            id: settings
            property color color: '#000000'
        }
        function storeSettings() {
            settings.color = root.color
        }
    }
}

import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 320
    height: 320
    title: qsTr("Hello World")

    Rectangle {
        width: 320
        height: 320
        color: '#ff0000'

        Button {
            anchors.centerIn: parent
            text: 'Click Me'
            onClicked: Qt.quit()
        }
    }
}

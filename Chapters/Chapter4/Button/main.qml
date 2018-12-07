import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Test")
    Item {
        id: selector

        Button {
            id: button
            x: 12; y: 12
            text: "Start"
            onClicked: {
                status.text = "Button clicked!"
                status.rotation = 45
                !selector.enabled
                reset.enabled
                status.scale = 2.0
            }
        }
        Text {
            id: status
            x: 12; y: 76
            width: 116; height: 26
            text: "waiting ..."
            horizontalAlignment: Text.AlignHCenter

        }
    }
    Item {
        id: reset
        Button {
            id: button2
            x: 76; y: 152
            text: "Reset"
            onClicked: {
                status.text = "waiting ..."
                status.rotation = status.rotation - 45
                status.scale = 1.0
                selector.enabled
                !reset.enabled
            }
        }
    }

}

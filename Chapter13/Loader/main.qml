import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle {
        id: root

        width: 600
        height: 400

        property int speed: 0

        SequentialAnimation {
            running: true
            loops: Animation.Infinite

            NumberAnimation { target: root; property: "speed"; to: 145; easing.type: Easing.InOutQuad; duration: 4000; }
            NumberAnimation { target: root; property: "speed"; to: 10; easing.type: Easing.InOutQuad; duration: 2000; }
        }
        // M1>>
        Loader {
            id: dialLoader

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: analogButton.top

            onLoaded: {
                binder.target = dialLoader.item;
            }
        }
        Binding {
            id: binder

            property: "speed"
            value: speed
        }
        // <<M1
        Rectangle {
            id: analogButton

            anchors.left: parent.left
            anchors.bottom: parent.bottom

            color: "gray"

            width: parent.width/2
            height: 100

            Text {
                anchors.centerIn: parent
                text: "Analog"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: root.state = "analog";
            }
        }

        Rectangle {
            id: digitalButton

            anchors.right: parent.right
            anchors.bottom: parent.bottom

            color: "gray"

            width: parent.width/2
            height: 100

            Text {
                anchors.centerIn: parent
                text: "Digital"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: root.state = "digital";
            }
        }

        state: "analog"

        // M3>>
        states: [
            State {
                name: "analog"
                PropertyChanges { target: analogButton; color: "green"; }
                PropertyChanges { target: dialLoader; source: "Analog.qml"; }
            },
            State {
                name: "digital"
                PropertyChanges { target: digitalButton; color: "green"; }
                PropertyChanges { target: dialLoader; source: "Digital.qml"; }
            }
        ]
        // <<M3
    }
}

import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id: rect1
        x: 12; y: 12
        color: "lightsteelblue"
        border.color: "magenta"
        border.width: 3
        width: 76; height: 96
        MouseArea{
            id: area
            width: parent.width
            height: parent.height
            onClicked: rect2.visible = !rect2.visible
        }

        Text{
            id: text1
            width: 120; height: 240
            verticalAlignment: Rectangle.AlignTop
            text: "The Quick \n brown fox"
            elide: Text.ElideMiddle
            style: Text.Sunken
            styleColor: '#FF4444'
            //color: "#303030"
            //font.family: "Ubuntu"
            //font.pixelSize: 28
        }
    }
    Rectangle{
        id: rect2
        x: 112; y:12
        width: 76; height: 96
        border.color: "lightsteelblue"
        border.width: 4
        Text {
            id: text2
            text: qsTr("text")
        }
    }


}

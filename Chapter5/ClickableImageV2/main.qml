import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    width: 360
    height: 240
    title: qsTr("Clickable Image V2")
    Image {
        id: background
        width: root.width
        height: root.height
        source: "assets/background.png"
    }

    ClickableImageV2 {
        id: greenBox
        x: 40; y: root.height - height
        source: "assets/box_green.png"
        text: "animation on property"
        NumberAnimation on y {
            to: 40; duration: 4000
        }
    }
    ClickableImageV2 {
        id: blueBox
        x: (root.width-width)/2; y: root.height-height
        source: "assets/box_blue.png"
        text: "behavior on property"
        Behavior on y {
            NumberAnimation { duration: 4000}
        }

        onClicked: y = 40
        //random y on each click
        //onClicked: y = 40+Math.random()*(205-40)
    }
    ClickableImageV2 {
        id: redBox
        x: root.width-width-40; y: root.height-height
        source: "assets/box_red.png"
        onClicked: anim.start()
            //onClicked: anim.restart()
        text: "Standalone Animation"

        NumberAnimation {
            id: anim
            target: redBox
            properties: "y"
            to: 40
            duration: 4000
        }
    }
}

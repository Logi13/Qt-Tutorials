//ClickableImage.qml
import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    visible: true
    width: bg.width
    height: bg.height
    title: qsTr("Clickable Image")
    Item{
        //set width based on give background
        width: bg.width
        height: bg.height
        Image {
            id: bg
            source: "assets/background.png"
        }
    }
    MouseArea {
        id: backgroundClicker
        // needs to be bofore the images as order matters
        //otherwise this mousearea would be before the other elements
        //and consume the mouse events
        anchors.fill: parent
        onClicked: {
            //reset the little scene
            circle.x = 84
            box.rotation = 0
            triangle.rotation = 0
            triangle.scale = 1.0
        }
    }
    ClickableImage {
        id: circle
        x: 84; y: 68
        source: "assets/circle_blue.png"
        antialiasing: true
        onClicked: {
            //increase the x-position
            x +=20
        }
    }
    ClickableImage {
        id: box
        x: 164; y: 68
        source: "assets/box_green.png"
        antialiasing: true
        onClicked: {
           // increase the rotation on click
            rotation +=15
        }
    }
    ClickableImage {
        id: triangle
        x: 248; y: 68
        source: "assets/triangle_red.png"
        antialiasing: true
        onClicked: {
            // several transformations
            rotation += 15
            scale += 0.05
        }
    }
    function _test_transformed() {
        circle.x += 20
        box.rotation = 15
        triangle.scale = 1.2
        triangle.rotation = -15
    }
    function _test_overlap() {
        circle.x += 40
        box.rotation = 15
        triangle.scale = 2.0
        triangle.rotation = 45
    }
}

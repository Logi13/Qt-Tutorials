import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Button {
        id: buttonTest
        objectName: "buttonTest"
        text: "Press ME"

        signal clickedButton(string str)
        onClicked: {
            buttonTest.clickedButton("clicked !")
        }
    }
}

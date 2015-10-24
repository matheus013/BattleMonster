import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Item {
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        id: name
        text: qsTr(ui.title)
    }
    ColumnLayout{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Button{
            text: "New Game"
            onClicked: stackPages.push(newGame)
        }
        Button{
            text: "Load Game"
        }
        Button{
            text: "My Page"
        }
        Button{
            text: "Info"
        }
    }

    Component{
        id: newGame
        NewPage{}
    }
}




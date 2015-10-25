import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Item {
    ColumnLayout{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Button{
            text: "New Game"
            onClicked: stackPages.push(newGame)
        }
        Button{
            text: "Battle"
            onClicked: stackPages.push(battle)
        }
        Button{
            text: "My Page"
            onClicked: myPage.visible = !myPage.visible
        }
        Button{
            text: "Info"
        }
    }

    Component{
        id: newGame
        NewPage{}
    }
    Component{
        id: battle
        BattlePage{}
    }
}




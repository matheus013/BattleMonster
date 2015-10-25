import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
Item {

    Image {
        id: battleBackground
        height: parent.height
        width: parent.width*0.70
        anchors.horizontalCenter: parent.horizontalCenter
        source: "qrc:/../build-BattleMonster/data/images/background-battle.png"
        GridLayout{
            ProgressBar{
                id: enemyBar
                maximumValue: 100
                value:10
            }ProgressBar{
                id: myBar
                maximumValue: 100
                value:10
            }
            Rectangle{
            }

            Button{
                text: "back"
                onClicked: stackPages.pop()
            }
        }
    }

}


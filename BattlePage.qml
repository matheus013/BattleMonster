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
        Text{
            text:"Id:" + _battle.enemy.name + " Lv:" + _battle.enemy.level
            anchors.bottom: enemyBar.top
            anchors.left: enemyBar.left
            font.pixelSize: 25
        }
        ProgressBar{
            id: enemyBar
            maximumValue: _battle.enemy.hp
            value:_battle.enemyHp
            x: ui.width*0.25 - width
            y: ui.height/3 - height*3
        }
        Image {
            source: getSprite(_battle.enemy.name)
            width: 200
            height: width
            y: ui.height/3 - height*0.75
            x: ui.width*0.6 - width
        }
        Text{
            text:"Id:" + _battle.front.name + " Lv:" + _battle.front.level
            anchors.bottom: myBar.top
            anchors.left: myBar.left
            font.pixelSize: 25
        }
        ProgressBar{
            id: myBar
            y: ui.height/1.6 - height
            x: ui.width*0.6 - width
            maximumValue: _battle.front.hp
            value:_battle.playerHp
        }
        Image {
            width: 200
            height: width
            x: ui.width/3 - width*1.35
            y: ui.height*0.62-height/2
            source: getSpriteBack(_battle.front.name)
        }
        Row{
            Button{
                text: "back"
                onClicked: stackPages.pop()
            }
        }
    }
}



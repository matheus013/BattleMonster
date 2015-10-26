import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
Item {

    Connections {
        target:_battle
        onEnemyChanged : {
            console.log("enemy.hp: " + enemy.hp)
            console.log("enemy.name: " + enemy.name)
            console.log(_battle.enemyHp)
        }
    }

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
            width: ui.width/6
            height: ui.height/4
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
            width: ui.width/6
            height: ui.height/4
            x: ui.width/3 - width*1.35
            anchors.bottom: battlePane.top
            source: getSpriteBack(_battle.front.name)
        }
        Item{
            id: battlePane
            width: battleBackground.width
            height: battleBackground.height*0.275
            anchors.bottom: battleBackground.bottom
            anchors.left: battleBackground.left
            RowLayout{
                //Skill List
                ListView{
                    model: _battle.front.skills
                    delegate: Rectangle{
                        Text{
                            anchors.fill: parent
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            font.pixelSize: height/3
                            text: modelData.name
                        }
                        MouseArea{
                            anchors.fill: parent
                        }
                    }
                }
                //Team Monster
                ListView{
                    model: _battle.player.team
                    delegate: Item{
                        height: ui.height/8
                        width: ui.width/10
                        Image {
                            anchors.fill: parent
                            source: getSprite(modelData.name)
                        }
                    }
                }
            }
        }

        Row{
            Button{
                text: "back"
                onClicked: stackPages.pop()
            }
            Button{
                text: "hit"
                onClicked: _battle.enemyHp -= 10
            }
        }
    }
}



import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
Window {
    function getSprite(num){
        return ":/../build-BattleMonster/data/images/sprite/" + num + ".png"
    }
    function getSpriteBack(num){
        return ":/../build-BattleMonster/data/images/sprite/back/" + num + ".png"
    }

    function cm(value){
        return value*10*Screen.pixelDensity
    }

    Image {
        id: background
        anchors.fill: parent
        source: "qrc:/../build-BattleMonster/data/images/background4.jpg"
    }

    title: "Battle Monster"
    id: ui
    visible: true
    width: Screen.width
    height: Screen.height
    ColumnLayout{
        CheckBox{
            id:adminCheckBox
            text: "Admin Mode"
        }
        Rectangle{
            id: admin
            visible: adminCheckBox.checked
            height: ui.height*0.25
            width: ui.width*0.15
            color: "black"
            ColumnLayout{
                Button{
                    text: "Make data monster"
                    onClicked: _make.buildMonster()
                }
                Button{
                    text: "Next Monster"
                    onClicked: _battle.nextEnemy(5)
                }
                RowLayout{
                    Button{
                        text: "Add Monster"
                        onClicked:{
                            _data.addMonster(idMonster.text)
                            _battle.reloadPlayer()
                        }
                    }
                    TextField{
                        id: idMonster
                    }
                }
            }
        }
    }

    StackView{
        id: stackPages
        anchors.fill: parent
        initialItem: MenuPage {}
    }

}


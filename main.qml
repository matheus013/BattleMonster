import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
Window {
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
            text: "Admin Mode"
            onCheckedChanged: {
                admin.visible = checked
            }
        }
        Rectangle{
            id: admin
            visible: false
            height: ui.height*0.25
            width: ui.width*0.2
            color: "black"
        }
    }

    StackView{
        id: stackPages
        anchors.fill: parent
        initialItem: MenuPage {}
    }

}


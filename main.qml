import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
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
    width: cm(8)
    height: cm(10)
    StackView{
        id: stackPages
        anchors.fill: parent

        initialItem: MenuPage {}
    }

}


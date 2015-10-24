import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
Window {
    title: "Battle Monster"
    id: ui
    visible: true
    StackView{
        id: stackPages
        anchors.fill: parent

        initialItem: MenuPage {}
    }

}


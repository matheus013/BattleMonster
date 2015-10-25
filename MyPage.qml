import QtQuick 2.0

Item {
        id: myPage
        visible: false
        width: ui.width/5
        height: ui.height
        Text {
            text: qsTr("Name: " + _data.player.name)
        }
}


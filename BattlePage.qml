import QtQuick 2.0
import QtQuick.Layouts 1.1
Item {
    function getColor() {
        var letters = '0123456789ABCDEF'.split('');
        var color = '#';
        for (var i = 0; i < 6; i++ ) {
            color += letters[Math.floor(Math.random() * 16)];
        }
        return color;
    }
    Image {
        id: battleBackground
        height: parent.height
        width: parent.width*0.60
        anchors.horizontalCenter: parent.horizontalCenter
        source: "qrc:/../build-BattleMonster/data/images/background-battle.png"
    }
    GridLayout{
        rows: 2
        columns: 3
        ListView{

        }

        Rectangle{
            width: parent.width*0.2
            height: parent.height*0.3
            color: getColor()
            MouseArea{
                anchors.fill: parent
                onClicked: stackPages.pop()
            }
        }
    }

}


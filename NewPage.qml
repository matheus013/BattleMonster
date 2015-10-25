import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
ColumnLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    property int choose: 0
    function randomMonster(){
        return Math.floor(Math.random() * 99);
    }

    RowLayout{
        Text {
            id: name
            text: qsTr("Name:")
        }
        TextField{
            id: content
        }
    }
    Text {
        text: qsTr("Sex")
    }
    RowLayout{
        CheckBox{
            text: "No Sex"
            onCheckedChanged: {

            }
        }
        CheckBox{
            text: "Male"
        }
        CheckBox{
            text: "Female"
        }
    }
    Text {
        text: qsTr("Initial Monster")
    }
    RowLayout{
        CheckBox{
            id: monster_1
            text: randomMonster()
            onCheckedChanged: {
                choose = 1
            }
        }
        CheckBox{
            id: monster_2
            text: randomMonster()
            onCheckedChanged: {
                choose = 2
            }
        }
        CheckBox{
            id: monster_3
            text: randomMonster()
            onCheckedChanged: {
                choose = 3
            }
        }
    }
    RowLayout{
        Button{
            text: "Back"
            onClicked: stackPages.pop()
        }
        Button{
            text: "Ok"
            onClicked: _data.newTrainer(content.text)
        }
    }
}


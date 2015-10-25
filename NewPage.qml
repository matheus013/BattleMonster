import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Item {
    Image {
        anchors.fill: parent
        source: "qrc:/../build-BattleMonster/data/images/background3.jpg"
    }
    property int choose: 0
    property string sex: ""
    function randomMonster(){
        return Math.floor(Math.random() * 82);
    }
    height: parent.height
    width: parent.width*0.6
    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        RowLayout{
            Text {
                text: qsTr("Name:")
                font.bold: true
                color: "red"
            }
            TextField{
                id: content
            }
        }
        Text {
            text: qsTr("Sex")
            font.bold: true
            color: "red"
        }
        RowLayout{
            CheckBox{
                text: "No Sex"
                onCheckedChanged: {
                    sex = text
                }
            }
            CheckBox{
                text: "Male"
                onCheckedChanged: {
                    sex = text
                }
            }
            CheckBox{
                text: "Female"
                onCheckedChanged: {
                    sex = text
                }
            }
        }
        Text {
            text: qsTr("Initial Monster")
            font.bold: true
            color: "red"
        }
        GridLayout{
            columns: 3
            rows: 2
            Image {
                source: ":/../build-BattleMonster/data/images/sprite/" + monster_1.text + ".png"

                sourceSize.height: 70
                sourceSize.width: 70
            }
            Image {
                source: ":/../build-BattleMonster/data/images/sprite/" + monster_2.text + ".png"
                sourceSize.height: 70
                sourceSize.width: 70
            }
            Image {
                source: ":/../build-BattleMonster/data/images/sprite/" + monster_3.text + ".png"
                sourceSize.height: 70
                sourceSize.width: 70
            }
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
                onClicked: _data.newTrainer(content.text,sex,choose)
            }
        }
    }
}


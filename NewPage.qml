import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    Button{
        text: "Back"
        onClicked: stackPages.pop()
    }

}


import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {
    RowLayout {
        anchors.fill: parent
        RowLayout {
            Layout.alignment: Qt.AlignCenter
            spacing: 50
            Button {
                id: hallButton
                text: "hallbutton"
                implicitWidth: 150
                implicitHeight: 150
            }
            Button {
                id: myroomButton
                text: "myroomButton"
                implicitWidth: 150
                implicitHeight: 150
            }
            Button {
                id: myInfo
                text: "myInfo"
                implicitWidth: 150
                implicitHeight: 150
            }
        }
    }


}

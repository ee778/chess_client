import QtQuick 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls 2.15
Item {
    ColumnLayout {
        spacing: 100
        anchors.horizontalCenter: parent.horizontalCenter
        RowLayout {
            Button {
                id: registerCannel
                text: qsTr("返回")
                onClicked: registerCannelclicked()
            }
        }

        ColumnLayout {
            spacing: 14
            TextField {
                id: registerUserName
                width: 200
                height: 40
            }
            TextField {
                id: registerPassword
                width: 200
                height: 40
                echoMode: TextInput.Password
            }
            Button {
                id: registerConfirm
                anchors.horizontalCenter: parent.horizontalCenter
                width: 200
                height: 40
                text: "注册"
            }
        }

    }

    signal registerCannelclicked()
}

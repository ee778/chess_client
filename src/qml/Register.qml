import QtQuick 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material
Item {
    id: registerPage
    implicitWidth: columnLayout1.implicitWidth
    implicitHeight: columnLayout1.implicitHeight
    Connections
    {
        target: LoginServer
        function onRegisterSuccess()
        {
            console.log("received register success signal")
            registerButton.text = qsTr("注册")
        }
        function onRegisterFailed(errorMessage) {
            console.log("received register failed signal", errorMessage)

            registerButton.text = qsTr("注册")
        }
    }

    // Rectangle {
    //     anchors.fill: parent
    //     gradient: Gradient {
    //         GradientStop {position: 0.0; color: "#f5f7fa"}
    //         GradientStop {position: 1.0; color: "#c3cfe2"}
    //     }
    // }

    ColumnLayout {
        //width: Math.min(parent.width * 0.85, 350)
        id: columnLayout1
        spacing: 30
        anchors.fill: parent

        ColumnLayout {
            spacing: 10
            Layout.alignment: Qt.AlignHCenter
            Label {
                text: qsTr("用户名")
                font.pixelSize: 12
            }
            TextField {
                id: registerUserName
                Layout.preferredWidth: 200
                Layout.preferredHeight: 40
            }
            Label {
                text: qsTr("密码")
                font.pixelSize: 12
            }
            TextField {
                id: registerPassword
                Layout.preferredWidth: 200
                Layout.preferredHeight: 40
                echoMode: TextInput.Password
            }
        }

        // 注册按钮
        Button {
            id: registerButton
            text: qsTr("注册")
            //anchors.horizontalCenter: parent.horizontalCenter
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            Material.background: Material.Purple
            onClicked: {

                if (registerUserName.text === "" || registerPassword.text === "") {

                    return
                }
                registerButton.enabled = false
                registerButton.text = qsTr("注册中...")
                LoginServer.handleRegister(registerUserName.text, registerPassword.text, true)
                registerCannel.enabled = false

            }
        }

        Item {
            id: spacer
            Layout.fillHeight: true
        }
    }

    signal registerCannelclicked()
}

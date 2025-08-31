import QtQuick 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls 2.15
Item {

    Connections
    {
        target: loginServer
        onRegisterSuccess:
        {
            console.log("received register success signal")
        }
        onRegisterFailed: {
            console.log("received register failed signal")
            registerErrorMessage.text = errorMessage
        }
    }

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {position: 0.0; color: "#f5f7fa"}
            GradientStop {position: 1.0; color: "#c3cfe2"}
        }
    }

    ColumnLayout {
        //width: Math.min(parent.width * 0.85, 350)
        spacing: 50
        anchors.centerIn: parent
        RowLayout {
            Button {
                id: registerCannel
                text: qsTr("返回")
                onClicked: registerCannelclicked()
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: "注册"
                font.pixelSize: 24
                font.bold: true
                color: "#2c3e50"
            }
        }

        ColumnLayout {
            spacing: 14

            Text {
                text: qsTr("用户名")
                font.pixelSize: 12
                color: "#34495e"
            }
            TextField {
                id: registerUserName
                width: 200
                height: 40
            }
            Text {
                text: qsTr("密码")
                font.pixelSize: 12
                color: "#34495e"
            }
            TextField {
                id: registerPassword
                width: 200
                height: 40
                echoMode: TextInput.Password
                selectByMouse: true
                background: Rectangle {
                    implicitHeight: 40
                    radius: 5
                    border.color: registerPassword.activeFocus ? "#3498db" : "#bdc3c7"
                    border.width: 1
                }
            }
        }

        // 错误信息
        Text {
            id: registerErrorMessage
            color: "e74c3c"
            font.pixelSize: 12
            visible: false
        }

        // 注册按钮
        Button {
            id: registerButton
            text: qsTr("注册")
            width: 200
            height: 40
            background: Rectangle {
                implicitHeight: 40
                radius: 5
                border.color: registerButton.activeFocus ? "#3498db" : "#2980b9"
                border.width: 1
                gradient: Gradient {
                    GradientStop {position: 0.0; color: "#3498db"}
                    GradientStop {position: 1.0; color: "#2980b9"}
                }
            }
            onClicked: {
                registerErrorMessage.visible = false
                if (registerUserName.text === "" || registerPassword.text === "") {
                    registerErrorMessage.text = qsTr("用户名和密码不能为空")
                    registerErrorMessage.visible = true
                    return
                }
                registerErrorMessage.visible = false
                registerButton.enabled = false
                registerButton.text = qsTr("注册中...")
                //registerWorker.register(registerUserName.text, registerPassword.text)
                registerCannel.enabled = false

            }
        }
    }

    signal registerCannelclicked()
}

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
//import com.chessclient.login 1.0
Item {
    // width: 600
    // height: 400
    //anchors.centerIn: parent
    Connections {
        target: LoginServer
        function onLoginSuccess() {
            console.log("登录成功");
            errorLabel.visible =false;
            logincuessbyqml();
        }

        // 处理登录失败的信号
        function onLoginFailed(errorMessage) {
            errorLabel.text = errorMessage;
            errorLabel.visible = true;
        }
    }
    Rectangle {
        id: bgimage
        anchors.fill: parent
        color: "#f0f0f0"
    }
    ColumnLayout {
        //Layout.alignment: Qt.AlignCenter
        anchors.centerIn: parent
        id: column1
        spacing: 5
        TextField {
            Layout.alignment: Qt.AlignHCenter
            id: username
            width: 200
            height: 40
            placeholderText: "请输入用户名称"
            echoMode: TextInput.Normal

            // 样式定制
            font.pixelSize: 14
            verticalAlignment: TextInput.AlignVCenter
            leftPadding: 10
        }
        TextField {
            Layout.alignment: Qt.AlignHCenter
            id: usepassword
            width: 200
            height: 40
            placeholderText: "请输入密码"
            echoMode: TextInput.Password

            font.pixelSize: 14
            leftPadding: 10
            verticalAlignment: TextInput.AlignVCenter
        }
        Text {
            Layout.alignment: Qt.AlignHCenter
            id: errorLabel
            visible: false
            text: ""
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20
            Button {
                id: loginbutton
                width: 90
                height: 40
                text: "登录"

                onClicked: {
                    // 调用C++函数
                    loginServer.handleLogin(username.text, usepassword.text)
                }
            }
            Button {
                id: registerbutton
                width: 90
                height: 40
                text: "注册"
                onClicked: {
                    registerbtnclicked()
                }
            }
        }
    }

    signal logincuessbyqml()
    signal registerbtnclicked()
}

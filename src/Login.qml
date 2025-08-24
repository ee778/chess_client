import QtQuick 2.15
import QtQuick.Controls 2.15
import com.chessclient.login 1.0
Item {
    width: 600
    height: 400

    LoginServer {
        id: loginServer

        onLoginSuccess: {
            console.log("登录成功");
            errorLabel.visible =false;
            logincuessbyqml();
        }

        // 处理登录失败的信号
        onLoginFailed: function(errorMessage) {
            errorLabel.text = errorMessage;
            errorLabel.visible = true;
        }
    }

    Column {
        anchors.centerIn: parent
        id: column1
        spacing: 5
        TextField {
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
            id: errorLabel
            visible: false
            text: ""
        }

        Row {
            anchors.horizontalCenter: column1.horizontalCenter
            spacing: 20
            Button {
                id: loginbutton
                width: 90
                height: 40
                anchors {
                    verticalCenter: parent.verticalCenter
                }
                text: "登录"

                onClicked: {
                    // 调用C++槽函数
                    loginServer.handleLogin(username.text, usepassword.text)
                }
            }
            Button {
                id: registerbutton
                width: 90
                height: 40
                anchors.verticalCenter: parent.verticalCenter
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

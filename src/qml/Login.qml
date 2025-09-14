import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls.Material
//import com.chessclient.login 1.0
Item {
    id: loginpage
    //让 Login.qml 的 Item 拥有明确的大小，可以根据 ColumnLayout 的内容自动撑开。
    implicitWidth: column1.implicitWidth
    implicitHeight: column1.implicitHeight

    Connections {
        target: LoginServer
        function onLoginSuccess() {
            console.log("登录成功");
            errorLabel.visible =false;
            loginpage.logincuessbyqml();
        }

        // 处理登录失败的信号
        function onLoginFailed(errorMessage) {
            errorLabel.text = errorMessage;
            errorLabel.visible = true;
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "red"
    }
    ColumnLayout {
        //anchors.centerIn: parent // 使用这个会导致缩小页面时占用topNav的位置
        anchors.fill: parent
        id: column1
        spacing: 5
        TextField {
            id: username
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            placeholderText: "请输入用户名称"
            echoMode: TextInput.Normal

            // 样式定制
            font.pixelSize: 14
            leftPadding: 10
        }
        TextField {
            Layout.alignment: Qt.AlignHCenter
            id: usepassword
            Layout.preferredWidth: 200
            Layout.preferredHeight: 40
            placeholderText: "请输入密码"
            echoMode: TextInput.Password

            font.pixelSize: 14
            leftPadding: 10
        }
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20
            Button {
                id: loginbutton
                Layout.preferredWidth: 90
                Layout.preferredHeight: 40
                Material.background: Material.Purple
                text: "登录"

                onClicked: {
                    // 调用C++函数
                    LoginServer.handleLogin(username.text, usepassword.text)
                }
            }
            Button {
                id: registerbutton
                Layout.preferredWidth: 90
                Layout.preferredHeight: 40
                text: "注册"
                onClicked: {
                    loginpage.registerbtnclicked();
                }
            }
        }
    }

    signal logincuessbyqml()
    signal registerbtnclicked()
}

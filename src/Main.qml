import QtQuick 2.15
import QtQuick.Controls 2.15
import com.chessclient.login 1.0
Window {
    id: root
    visible: true

    width: 800
    height: 600


    StackView {
        id: stackView
        initialItem: loginPage
        anchors.fill: parent
    }


    Login {
        id: loginPage
        anchors.fill: parent
        visible: falsel

        onRegisterbtnclicked: {
            intoSucess()
        }
    }

    MainPage {
        id: mainPage
        anchors.fill: parent
        visible: false
    }

    Register {
        id: registerPage
        anchors.fill: parent
        visible: false
    }

    function loginSucess() {
        stackView.push(mainPage);
    }

    function stackViewPop() {
        stackView.pop();
    }

    function intoSucess() {
        stackView.push(registerPage)
    }
    // 是一个重要的信号处理器，用于QML组件初始化后执行特定的逻辑
    Component.onCompleted: {
        loginPage.logincuessbyqml.connect(loginSucess)
        registerPage.registerCannelclicked.connect(stackViewPop)
        mainPage.mainPage_back_signal.connect(stackViewPop)
    }
    // Component.onCompleted: loginPage.registerbtnclicked.connect(intoSucess)
}

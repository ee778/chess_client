import QtQuick 2.15
import QtQuick.Controls 2.15
//import com.chessclient.login 1.0
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
        //anchors.fill: parent
        visible: false

        onRegisterbtnclicked: {
            intoSucess()
        }
    }

    MainPage {
        id: mainPage
        //anchors.fill: parent
        visible: false
    }

    Register {
        id: registerPage
        //anchors.fill: parent
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

    function registerSucess() {
        // 判断当前容器中是否包含注册页面
        if (stackView.currentItem === registerPage)
        {
            // 弹出注册页面
            stackView.pop();
        }
    }
    // 是一个重要的信号处理器，用于QML组件初始化后执行特定的逻辑
    Component.onCompleted: {
        loginPage.logincuessbyqml.connect(loginSucess)
        registerPage.registerCannelclicked.connect(stackViewPop)
        mainPage.mainPage_back_signal.connect(stackViewPop)
    }

    Connections {
        target: LoginServer   // 这里使用的是qml上下文，所以需要使用的名字和定义的名称一致，需要区分大小写

        function onRegisterSuccess() {
            registerSucess()
        }
    }
}

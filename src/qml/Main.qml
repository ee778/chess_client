import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material
import QtQuick.Layouts
import "singletons" as Singletons
//import com.chessclient.login 1.0
ApplicationWindow {
    id: root
    visible: true

    width: 800
    height: 600
    Material.theme: mainPageTopNav.isDarkTheme ? Material.Dark : Material.Light
    Material.accent: Material.Purple

    // Singletons.GlobalPopup {
    //     id: globalPopup
    //     parent: Overlay.overlay //表示将当前组件放置在应用程序的覆盖层(overlay)上，而不是常规的父组件中。这是一种常见的弹出框实现方式。
    // }

    ColumnLayout {
        anchors.fill: parent
        spacing: 2
        MainPageTopNav {
            id: mainPageTopNav
            visible: true
            //Layout.preferredWidth: 400
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop
        }

        StackView {
            id: stackView
            //Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            initialItem: gameMainWidget

        }

        Item {
            Layout.preferredHeight: 100
        }

        Login {
            id: loginPage
            visible: false
            onRegisterbtnclicked: {
                root.intoSucess()
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
        GameMainWidget {
            id: gameMainWidget
            visible: false
        }
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
        //mainPage.mainPage_back_signal.connect(stackViewPop)
        Singletons.GlobalPopup.parent = Overlay.overlay
    }

    Connections {
        target: LoginServer   // 这里使用的是qml上下文，所以需要使用的名字和定义的名称一致，需要区分大小写
        function onRegisterSuccess() {
            root.registerSucess()
        }
    }
    Connections {
        target: mainPageTopNav
        function onMainPageTopNav_back_clicked() {
            if (stackView.depth != 1) {
                console.log("stackView pop")
                stackView.pop()
            }
            else {
                console.log("stackView depth == 1")
            }

        }
    }
}

pragma Singleton  // 声明单例
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material
Popup {
    id: popupShow
    modal: false
    focus: false
    Material.background: {
        switch(popupShow.showType) {
            case "normal": return Material.Grey
            case "success": return Material.LightGreen
            case "warning": return Material.Yellow
            case "error": return Material.Red
            default: return Material.Blue
        }
    }

    x: (parent ? parent.width : Screen.width) / 2 - width / 2
    y: 40
    padding: 12
    visible: isVisible

    Material.theme: Material.Light
    Material.primary: Material.Purple
    Material.accent: Material.Purple
    property string showType: "normal"
    property string message: ""

    property bool isVisible: false
    Timer {
        id: autoCloseTimer
        repeat: false
        onTriggered: popupShow.closeWithAnimation()
    }

    function closeWithAnimation() {
        popupShow.isVisible = false
    }

    // NumberAnimation on opacity {
    //     id: anim
    //     from: 1.0
    //     to: 0.0
    //     duration: 300
    //     onStopped: popupShow.isVisible = false
    // }

    function showBase(text, duration) {
        popupShow.opacity = 1.0
        popupShow.message = text
        autoCloseTimer.interval = duration
        autoCloseTimer.restart()
        popupShow.isVisible = true

    }

    function showInfo(text, duration) {
        popupShow.showType = "normal"
        popupShow.showBase(text, duration)

    }
    function showWarning(text, duration) {
        popupShow.showType = "warning"
        popupShow.showBase(text, duration)

    }

    function showError(text, duration) {
        popupShow.showType = "error"
        popupShow.showBase(text, duration)

    }

    function showSuccess(text, duration) {
        popupShow.showType = "success"
        popupShow.showBase(text, duration)
    }

    contentItem: RowLayout {
        spacing: 8
        anchors.verticalCenter: parent.verticalCenter

        Label {
            text: {
                switch(popupShow.showType) {
                    case "warning": return "⚠"
                    case "error": return "✖"
                    case "normal": return "!"
                    default: return "✔"
                }
            }
            font.pixelSize: 20
        }

        Label {
            text: popupShow.message
            wrapMode: Text.WordWrap
            font.pixelSize: 14
        }

    }
}

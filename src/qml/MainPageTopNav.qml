import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "singletons" as Singletons
Item {
    //property Main main
    id: mainPageTopNav
    property bool isDarkTheme: false
    implicitWidth: rowlayout1.implicitWidth
    implicitHeight: rowlayout1.implicitHeight

    RowLayout {
        id: rowlayout1
        anchors.fill: parent
        Button {
            id: returnButton
            // Layout.preferredWidth: 40
            // Layout.preferredHeight: 40
            text: qsTr("back")

            onClicked: {
                console.log("send mainPageTopNav_back_clicked")
                mainPageTopNav.mainPageTopNav_back_clicked()
            }
        }
        Button {
            id: testPopup
            text: qsTr("testSuccess")
            onClicked: {
                Singletons.GlobalPopup.showSuccess("test", 1000)
            }
        }
        Button {
            id: testError
            text: qsTr("testError")
            onClicked: {
                Singletons.GlobalPopup.showError("test", 1000)
            }
        }
        Button {
            id: testInfo
            text: qsTr("testInfo")
            onClicked: {
                Singletons.GlobalPopup.showInfo("test", 1000)
            }
        }
        Button {
            id: testWarning
            text: qsTr("testWarning")
            onClicked: {
                Singletons.GlobalPopup.showWarning("test", 1000)
            }
        }
        Item {
            Layout.fillWidth: true
        }

        Switch {
            onCheckedChanged: mainPageTopNav.isDarkTheme = !mainPageTopNav.isDarkTheme
        }
    }

    signal mainPageTopNav_back_clicked()
}


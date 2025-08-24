import QtQuick 2.15
import QtQuick.Controls 2.15
Item {
    //property Main main
    Row {
        Button {
            //anchors.right: parent.right
            id: returnButton
            width: 40
            height: 40
            text: "返回"

            onClicked: {
                console.log("send mainPageTopNav_back_clicked")
                mainPageTopNav_back_clicked()

            }
        }
    }

    signal mainPageTopNav_back_clicked()
}

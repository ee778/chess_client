import QtQuick 2.15
import QtQuick.Controls 2.15
Item {
    width: 640
    height: 480
    visible: true

    Column {
        // Column 内部不能使用anchors.fill 锚点，Column布局会自动管理其子项的位置
        //anchors.fill: parent
        width: parent.width
        height: parent.height
        MainPageTopNav {
            id: mainPageTopNav
        }
        Item {
            Canvas {
                id: boardCanvas
                anchors.centerIn: parent
                width: 500
                height: 500
                property int gridSize: 19
                property int cellSize: width / (gridSize - 1)

                onPaint: {
                    var ctx = getContext("2d")

                    ctx.fillStyle = "#DCB35C"
                    ctx.fillRect(0, 0, width, height)

                    // 设置线条样式
                    ctx.strokeStyle = "black"
                    ctx.lineWidth = 1

                    for (var i = 0; i < gridSize; i++) {
                        ctx.beginPath()
                        ctx.moveTo(0, i * cellSize)
                        ctx.lineTo(width, i * cellSize)
                        ctx.stroke()
                    }

                    // 绘制竖线
                    for (var i = 0; i < gridSize; i++) {
                        ctx.beginPath()
                        ctx.moveTo(i * cellSize, 0)
                        ctx.lineTo(i * cellSize, height)
                        ctx.stroke()
                    }

                    // 绘制星位
                    drawStarPoint(ctx, (gridSize - 1) / 2, (gridSize - 1) / 2)

                    if (gridSize == 19) {
                        drawStarPoint(ctx, 3, 3)
                        drawStarPoint(ctx, 3, 15)
                        drawStarPoint(ctx, 15, 3)
                        drawStarPoint(ctx, 15, 15)
                    }

                }

                function drawStarPoint(ctx, x, y) {
                    ctx.fillStyle = "black"
                    ctx.beginPath()
                    ctx.arc(x * cellSize,  y * cellSize, 4, 0, Math.PI * 2)
                    ctx.fill()
                }

                Component.onCompleted: {
                    requestPaint()
                }
            }
        }
    }

    Component.onCompleted: {
        mainPageTopNav.mainPageTopNav_back_clicked.connect(slot_mainPageTopVav_back_clicked)
    }

    signal mainPage_back_signal()
    function slot_mainPageTopVav_back_clicked() {
        console.log("reviced function slot_mainPageTopVav_back_clicked")
        mainPage_back_signal()
    }
}

import QtQuick 2.0

Canvas {
    width: 100
    height: 20
    property var xPos: 100
    onPaint: {
        var ctx = getContext('2d')
        ctx.strokeStyle = "#5ba234"
        ctx.lineWidth = 10
        ctx.beginPath()
        ctx.moveTo(0, 10)
        ctx.lineTo(xPos, 10)
        ctx.stroke()
        ctx.closePath()
    }
}
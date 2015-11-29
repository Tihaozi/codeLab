import QtQuick 2.0

Canvas {

    id: hBar
    // anchors.centerIn: parent
    width: 200
    height: 20

    property   var chartWidth: 100
    property   var text: "Hello"
    // property   var chart
    // property   var chartData
    // property   int chartType: 0
    // property  bool chartAnimated: true
    // property alias chartAnimationEasing: chartAnimator.easing.type
    // property alias chartAnimationDuration: chartAnimator.duration
    // property   int chartAnimationProgress: 0
    // property   var chartOptions: ({})

    // /////////////////////////////////////////////////////////////////
    // Callbacks
    // /////////////////////////////////////////////////////////////////

    onPaint: {
        var ctx = getContext("2d")
        var x = hBar.width / 2
        var y = hBar.height / 2

        ctx.lineWidth = 2
        ctx.strokeStyle = "#5ba234"
        ctx.fillStyle = "#5ba234"

        ctx.beginPath()
        ctx.moveTo(0, 0)
        ctx.lineTo(chartWidth/2, 0)
        ctx.lineTo(chartWidth/2, 20)
        ctx.lineTo(0, 20)
        ctx.closePath()

        // ctx.stroke()
        ctx.fill()

        ctx.font = '10pt Calibri';
        // ctx.textAlign = 'center';
        ctx.textBaseline = 'middle';
        ctx.fillStyle = 'white';
        ctx.fillText(hBar.text, 5, y);
    }

    // onHeightChanged: {
    //     requestPaint();
    // }

    // onWidthChanged: {
    //     requestPaint();
    // }

    // /////////////////////////////////////////////////////////////////
    // Functions
    // /////////////////////////////////////////////////////////////////

    function repaint() {
        // chartAnimationProgress = 0;
        chartAnimator.start();
    }

    // /////////////////////////////////////////////////////////////////
    // Internals
    // /////////////////////////////////////////////////////////////////

    PropertyAnimation {
        id: chartAnimator;
        target: hBar;
        property: "chartAnimationProgress";
        to: 10;
        duration: 1000;
        easing.type: Easing.InOutElastic;
    }
}

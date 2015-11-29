import QtQuick 2.0

MouseArea {
    id: mouseArea
    property alias tip: tip
    property alias text: tip.text
    property alias hideDelay: hideTimer.interval //this makes it easy to have custom hide delays
                                                 //for different tools
    property alias showDelay: showTimer.interval
    anchors.fill: parent
    hoverEnabled: true
    Timer {
        id:showTimer
        interval: 100
        running: (mouseArea.containsMouse && !tip.visible)
        onTriggered: tip.show();
    }
    //this is the important part!
    Timer {
        id:hideTimer
        interval: 100 //ms before the tip is hidden
        running: !mouseArea.containsMouse && tip.visible
        onTriggered: tip.hide(); //this is the js code that hides the tip.
                                 //you could also use visible=false; if you
                                 //don't need animations
    }
    Tooltip{
        id:tip
    }
}
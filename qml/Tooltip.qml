import QtQuick 2.0

Rectangle {
    id: tooltip
    property alias text: textContainer.text
    property int verticalPadding: 1
    property int horizontalPadding: 5
    width: textContainer.width + horizontalPadding * 2
    height: textContainer.height + verticalPadding * 2
    color: "#131313"
    Text {
        anchors.centerIn: parent
        id:textContainer
        text: "Pyblish Timeline's Tooltip"
        color: "#5ba234"
    }
    NumberAnimation {
        id: fadein
        target: tooltip
        property: "opacity"
        easing.type: Easing.InOutQuad
        duration: 300
        from: 0
        to: 1
    }
    NumberAnimation {
        id: fadeout
        target: tooltip
        property: "opacity"
        easing.type: Easing.InOutQuad
        from: 1
        to: 0
        onStopped: visible = false;
    }
    visible:false
    onVisibleChanged: if(visible)fadein.start();
    function show(){
        visible = true;
        fadein.start();
    }
    function hide(){
        fadeout.start();
    }
}
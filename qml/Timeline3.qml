import QtQuick 2.0

Rectangle {
    id: root
    property var my_data: [
              {
                "name": "ValidateNameSpace1",
                "duration": 50
              },
              {
                "name": "ValidateNameSpace2",
                "duration": 100
              },
              {
                "name": "ValidateNameSpace3",
                "duration": 200
              },
              {
                "name": "ValidateNameSpace4",
                "duration": 90
              },
              {
                "name": "ValidateNameSpace5",
                "duration": 33
              },
            ]


    // property var levels: {
    //     "DEBUG":  {
    //         "color": Qt.lighter("steelblue", 1.3),
    //         "icon": "log-debug-16x16"
    //     },
    //     "INFO": {
    //         "color": Qt.lighter("steelblue", 1.5),
    //         "icon": "log-info-16x16"
    //     },
    //     "WARNING": {
    //         "color": Qt.lighter("red", 1.6),
    //         "icon": "log-warning-16x16"
    //     },
    //     "ERROR": {
    //         "color": Qt.lighter("red", 1.4),
    //         "icon": "log-error-16x16"
    //     },
    //     "CRITICAL": {
    //         "color": Qt.lighter("red", 1.2),
    //         "icon": "log-critical-16x16"
    //     }
    // }

    width: 380
    height: 175
    implicitWidth: 380
    color: "#3f3f3f"

    Text {
        id: timeline
        text: "Timeline"
        x: 5; y: 10
        font.pointSize: 8
        color: "white"      
    }

    Rectangle {
        width: parent.width - 20
        height: 140
        clip: true
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30
        radius: 7
        color: "#232323"

        // Grid Lines
        
        Canvas {
            id: lines
            anchors.centerIn: parent
            width: 350; height: 150
            onPaint: {
                var ctx = getContext("2d")
                ctx.strokeStyle = "#aaaaaa"
                ctx.lineWidth = 1
                ctx.beginPath()
                ctx.moveTo(160, 0)
                ctx.lineTo(160, 200)
                ctx.stroke()
                ctx.closePath()

            //     ctx.beginPath()
            //     ctx.moveTo(parent.width/4, 0)
            //     ctx.lineTo(parent.width/4, 200)
            //     ctx.stroke()
            //     ctx.closePath()
                
            //     ctx.beginPath()
            //     ctx.moveTo(parent.width/8, 0)
            //     ctx.lineTo(parent.width/8, 200)
            //     ctx.stroke()
            //     ctx.closePath()
                
            //     ctx.beginPath()
            //     ctx.moveTo(parent.width/16, 0)
            //     ctx.lineTo(parent.width/16, 200)
            //     ctx.stroke()
            //     ctx.closePath()
                
            //     ctx.beginPath()
            //     ctx.moveTo(parent.width/32, 0)
            //     ctx.lineTo(parent.width/32, 200)
            //     ctx.stroke()
            //     ctx.closePath()
                
            //     ctx.beginPath()
            //     ctx.moveTo(parent.width/64, 0)
            //     ctx.lineTo(parent.width/64, 200)
            //     ctx.stroke()
            //     ctx.closePath()
                
            //     ctx.beginPath()
            //     ctx.moveTo(parent.width/128, 0)
            //     ctx.lineTo(parent.width/128, 200)
            //     ctx.stroke()
            //     ctx.closePath()
            }
        }

        // Bars
        Column {
            id: col
            width: parent.width - 10
            // spacing: 1
            Repeater {
                id: bars
                model: my_data
                delegate: Rectangle {
                    width: modelData.duration
                    // x: parent.pos
                    // parent.pos = x + modelData.duration
                    height: 20
                    color: "#5ba234"
                    Text {
                        anchors.centerIn: parent
                        width: parent.width
                        text: modelData.name + " : " + modelData.duration + "ms"
                        elide: Text.ElideRight 
                        color: "white"
                    }
                }
            }
        }
    }
    // Component.onCompleted: {
    //     normalise()
    // }
    // onWidthChanged: {
    //     normalise()
    // }
    onMy_dataChanged: {
        normalise()
    }


    function normalise(){
        var normal_factor = all_ms() / root.width
        // print(normal_factor)
        for(var i=0;i < my_data.length;i++){
            my_data[i].duration = parseInt(my_data[i].duration / normal_factor);
            print(parseInt(my_data[i].duration));

            onPropertyChange: {
                bars.itemAt(i).width = my_data[i].duration;
                // bars.itemAt(i).x = bars.itemAt(i).x + parseInt(my_data[i-1].duration);
            }

        }

    }    
    function all_ms(){
        var count = 0
        for(var i=0;i < my_data.length;i++){
            count += my_data[i].duration
        }
        return count
    }
}
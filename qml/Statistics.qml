import QtQuick 2.0

Item {
    id: root
    width: 370
    height: 170
    property var new_data: []
    property var main_data: [
              {
                "name": "ValidateNameSpace1",
                "duration": 150
              },
              {
                "name": "ValidateNameSpace2",
                "duration": 25
              },
              {
                "name": "ValidateNameSpace3",
                "duration": 130
              },
              {
                "name": "ValidateNameSpace4",
                "duration": 90
              },
              {
                "name": "ValidateNameSpace5",
                "duration": 165
              },
              {
                "name": "ValidateNameSpace6",
                "duration": 50
              },
              {
                "name": "ValidateNameSpace7",
                "duration": 99
              },
              {
                "name": "ValidateNameSpace8",
                "duration": 32
              },
            ]
    Rectangle {
        id: main
        width: parent.width - 10
        height: parent.height - 10
        anchors.centerIn: parent
        color: "#232323"
        radius: 7
        // clip: true

        Canvas {
            id: lines
            // anchors.centerIn: parent
            width: parent.width
            height: parent.height
            onPaint: {
                var ctx = getContext("2d")
                ctx.lineWidth = .25
                ctx.strokeStyle = "#454545"
                ctx.fillStyle = '#454545'

                // for(var i = 0; i < parent.width; i++) {
                var c = 5
                while(c < width){
                    ctx.beginPath()
                    ctx.moveTo(c, 0)
                    ctx.lineTo(c, height)
                    ctx.stroke()
                    ctx.closePath()
                    c += width / 15

                }
                while(c < height){
                    ctx.beginPath()
                    ctx.moveTo(0, c)
                    ctx.lineTo(width, c)
                    ctx.stroke()
                    ctx.closePath()
                    c += height / 15

                }
                ctx.beginPath()
                ctx.strokeRect(5,5, width-15, height-15)
                ctx.closePath()

            }
            onWidthChanged: {
                requestPaint()
            }
        }

        Item {
            width: parent.width - 5
            height: parent.height - 5


            Canvas {
                id: canv
                anchors.centerIn: parent
                width: parent.width
                height: parent.height
                onPaint: {
                    var ctx = getContext("2d")
                    ctx.lineWidth = 2
                    ctx.strokeStyle = "#5ba234"
                    ctx.fillStyle = '#fff'

                    var xPos = 5
                    var yPos = height/(root.new_data.length + root.new_data.length/4)
                    ctx.beginPath()
                    ctx.moveTo(xPos, yPos)
                    for(var i = 0; i < root.new_data.length; i++) {                        
                        ctx.lineTo(xPos, yPos)
                        ctx.stroke()
                        xPos += root.new_data[i].duration
                        yPos += height/(root.new_data.length + root.new_data.length/4)
                    }
                    ctx.closePath()

                    var xPos = 5
                    var yPos = height/(root.new_data.length + root.new_data.length/4)
                    for(var i = 0; i < root.new_data.length; i++) {
                        ctx.beginPath()
                        ctx.arc(xPos, yPos, 3, 0, 360)
                        ctx.fill()
                        ctx.closePath()
                        xPos += root.new_data[i].duration
                        yPos += height/(root.new_data.length + root.new_data.length/4)
                    }
                }

                onWidthChanged: {
                    root.normalise()
                    requestPaint()
                }
            }
        }
    }


    function normalise(){
        new_data = deepCopy(main_data, new_data)
        var normal_factor = all_ms() / root.width
        for(var i=0;i < new_data.length;i++){
            new_data[i].duration = parseInt(new_data[i].duration / normal_factor);
        }
    }    

    function all_ms(){
        var count = 0
        for(var i=0;i < main_data.length;i++){
            count += main_data[i].duration
        }
        return count
    }

    function deepCopy(base, target) {
        var target = target || {};
        for (var i in base) {
            if (typeof base[i] === 'object') {
                target[i] = (base[i].constructor === Array) ? [] : {};
                deepCopy(base[i], target[i]);
            } else {
                target[i] = base[i];
            }
        }
        return target;
    }

    Component.onCompleted: {
        normalise()
    }

}

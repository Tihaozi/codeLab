import QtQuick 2.0

Item {
    id: root
    width: 400
    height: 160
    property var new_data: []
    property var main_data: [
              {
                "name": "plugin1",
                "duration": 150
              },
              {
                "name": "ValidateNameSpacePlugin2",
                "duration": 25
              },
              {
                "name": "ValidateName3",
                "duration": 100
              },
              {
                "name": "ValidateNameSpace4",
                "duration": 88
              },
              {
                "name": "ValidateNameSpace5",
                "duration": 56
              },
              {
                "name": "ValidateNameSpace6",
                "duration": 220
              },
              {
                "name": "ValidateNameSpace7",
                "duration": 110
              },
              {
                "name": "ValidateNameSpace8",
                "duration": 70
              },
              {
                "name": "ValidateNameSpace9",
                "duration": 35
              },
              {
                "name": "ValidateNameSpace10",
                "duration": 10
              },
              {
                "name": "ValidateNameSpace2",
                "duration": 2
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
            // property int all: 400 + width
            property int all: 0
            anchors.centerIn: parent
            width: parent.width
            height: parent.height
            onPaint: {
                var ctx = getContext("2d")
                ctx.lineWidth = .25
                ctx.strokeStyle = "#454545"
                ctx.fillStyle = '#454545'

                function normalise_all(c){
                    var factor = all / width
                    return c / factor
                }
                var c = 5
                while(c < all){
                    ctx.beginPath()
                    ctx.moveTo(normalise_all(c), 0)
                    ctx.lineTo(normalise_all(c), height)
                    ctx.stroke()
                    ctx.closePath()
                    ctx.fillText(" " + parseInt(c-5) + "ms", normalise_all(c), height-7)
                    c += all / 7

                }
                ctx.beginPath()
                ctx.moveTo(0, height-20)
                ctx.lineTo(width, height-20)
                ctx.stroke()
                ctx.closePath()

            }
            onWidthChanged: {
                requestPaint()
                all =all_ms2()
            }
            Component.onCompleted: {
                all =all_ms2()
            }
        }

        // Item {
        //     width: parent.width - 5
        //     height: parent.height - 5

        Canvas {
            id: canv
            // anchors.centerIn: parent
            property int character_width: 10
            property int max_characters: 0
            width: parent.width
            height: parent.height - 20
            onPaint: {
                var ctx = getContext("2d")
                if(height / root.new_data.length > 20){
                    ctx.lineWidth = 20
                }
                else{
                    ctx.lineWidth = height / root.new_data.length
                }
                ctx.strokeStyle = "#5ba234"
                ctx.fillStyle = '#fff'

                function elide_text(txt, duration, xPos, yPos){
                    // character_width
                    // print(txt.length)
                    // print(duration)
                    if(txt.length * character_width > duration){
                        max_characters = parseInt(duration / character_width)
                        txt = txt.slice(0, Math.abs(max_characters-3)) + "..."
                    }
                    if(duration < 50){
                        txt = ""
                    }

                    ctx.fillText(txt, xPos + 5, yPos + 3)
                    // print(txt)
                    // print(txt.length)
                    // print(txt.slice(0, 5))
                }

                var xPos = 5
                var yPos = ctx.lineWidth * 0.75
                for(var i = 0; i < root.new_data.length; i++) {
                    // print("xPos: " + xPos + " - yPos: " + yPos + " - Duration: " + root.new_data[i].duration)
                    ctx.beginPath()
                    ctx.moveTo(xPos, yPos)
                    ctx.lineTo(xPos + root.new_data[i].duration, yPos)
                    ctx.stroke()
                    ctx.closePath()
                    elide_text(main_data[i].name, main_data[i].duration, xPos, yPos)

                    xPos += root.new_data[i].duration
                    yPos += ctx.lineWidth
                }
            }

            onWidthChanged: {
                root.normalise()
                requestPaint()
            }
            // TooltipArea{
            //     text: "Name: blah blah\nDuration: adasd"
            //     hideDelay: 50
            //     showDelay: 500
            // }
            // MouseArea {
            //     id: click
            //     anchors.fill: parent
            //     onClicked: {
            //         print("main_data")
            //     }
            // }
        }
        // }
    }


    function normalise(){
        new_data = deepCopy(main_data, new_data)
        var all_durations = all_ms()
        var normal_factor = 1
        if(all_durations > root.width){
            normal_factor = all_durations / root.width
        }
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

    function all_ms2(){
        var count = 0
        for(var i=0;i < main_data.length;i++){
            count += main_data[i].duration
        }
        if(count < root.width)
            return root.width
        else            
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

        // for(var i=0;i < main_data.length;i++){
        //     print(main_data[i].name)
        // }
        normalise()
    }

}

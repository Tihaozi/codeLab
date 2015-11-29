import QtQuick 2.0

Rectangle {
	id: root
	property var myData: [
			  {
			    "name": "Plugin1",
			    "duration": 50
			  },
			  {
			    "name": "Plugin2",
			    "duration": 100
			  },
			  {
			    "name": "Plugin3",
			    "duration": 78
			  },
			]


    width: 372
    height: 175
    color: "#3f3f3f"

    Text {
    	id: test
    	anchors.centerIn: parent
		// text: root.levels["CRITICAL"].color
		text: myData[0].name
		x: 5; y: 10
		font.pointSize: 8
		color: "white"   	
    }
}
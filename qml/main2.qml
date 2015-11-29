import QtQuick 2.0
import QtQuick.Controls 1.0

ApplicationWindow {
	id: mainWindow
	title: "ApplicationWindow"
	Rectangle {
	    width: 500
	    height: 500
	    color: "lightgray"
	    Text {
	    	anchors.centerIn: parent
	    	text: "Hello World!"
	    }
	}
}


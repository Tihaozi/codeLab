import QtQuick 2.0

Item {
	id: root
	width: 300
	height: 300
	Canvas {
		id: canv
		width: parent.width - 20
		height: parent.height - 20
		onPaint: {
		    var ctx = getContext("2d")
		    root.paintshape(ctx, 100, 10)
		    root.paintshape(ctx, 200, 20)
		}
	}
	function paintshape(ctx, xPos, yPos){		
		ctx.strokeStyle = '#5ba234';
		ctx.lineWidth = 10;
		ctx.beginPath();
		ctx.moveTo(0, yPos);
		ctx.lineTo(xPos, yPos);
		ctx.stroke();
		ctx.closePath();
		
	}
}
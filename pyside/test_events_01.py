import sys

from PySide import QtCore, QtGui


class Form(QtGui.QDialog):
    """"""

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)
        self.resize(400, 400)

        btn1 = QtGui.QPushButton('Close Window')
        layout = QtGui.QVBoxLayout(self)

        layout.addWidget(btn1)

        btn1.clicked.connect(self.close)

    # def mousePressEvent(self, event):
    #     if event.button() == QtCore.Qt.LeftButton:
    #         print event.__class__.__mro__
    #         print "Mouse Pressed"
    #     else:
    #         self.mousePressEvent(event)

    # def closeEvent(self, event):
    #     # print "Window Closed"
    #     if self.userReallyWantsToQuit():
    #         event.accept()
    #     else:
    #         event.ignore()

    # def contextMenuEvent(self, event):
    #     print "Context Menu Event"

    # def enterEvent(self, event):
    #     print "Enter Event"

    # def hideEvent(self, event):
    #     print "Hide Event"

    # def keyPressEvent(self, event):
    #     # Default is accept()
    #     if event.key() == QtCore.Qt.Key_Tab:
    #         print "Tab Key Pressed"
    #     else:
    #         # QtGui.QWidget.keyPressEvent(event)      # ignore()
    #         # or
    #         QtGui.QDialog.keyPressEvent(event)      # ignore()

    # def mouseDoubleClickEvent(self, event):
    #     print "Double Clicked"

    # def resizeEvent(self, event):
    #     print "Resized"

    # def wheelEvent(self, event):
    #     print "Wheel"

    def event(self, event):
        if event.type() == QtCore.QEvent.KeyPress:
            if event.key() == QtCore.Qt.Key_Tab:
                print "Tab Key Pressed"
            if event.key() == QtCore.Qt.Key_Enter:
                print "Enter Key Pressed"
            if event.key() == QtCore.Qt.Key_Up:
                print "Up Arrow Key Pressed"
        elif event.type() == QtCore.QEvent.MouseButtonPress:
            if event.button() == QtCore.Qt.LeftButton:
                print "Left mouse button clicked"
        elif event.type() == QtCore.QEvent.Close:
            if self.userReallyWantsToQuit():
                event.accept()
            else:
                event.ignore()
        elif event.type() == MyEvent:
            print "here"
        elif event.type() == QtCore.QEvent.ContextMenu:
            menu = QtGui.QMenu(self)
            for label in ('new', 'open', 'settings', 'close'):
                action = QtGui.QAction(label, self, triggered=self.printMe)
                menu.addAction(action)
            menu.exec_(event.globalPos())

        return True

    def printMe(self):
        action = self.sender()
        label = action.text()

        if label == "new":
            print "New File Created"
        elif label == "open":
            print "File Opend"
        elif label == "settings":
            print "settings menu Opend"
        elif label == "close":
            self.close()


    def userReallyWantsToQuit(self):
        ret = QtGui.QMessageBox.warning(self, "My Application",
               "Do you want to close the window?",
               QtGui.QMessageBox.Yes, QtGui.QMessageBox.No)
        if ret == QtGui.QMessageBox.Yes:
            return True
        else:
            return False

class MyEvent(QtCore.QEvent):
    pass


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)

    form = Form()
    form.show()

    sys.exit(app.exec_())

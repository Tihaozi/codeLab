import sys

from PySide import QtCore, QtGui

class MainWindow(QtGui.QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.textEdit = QtGui.QTextEdit()
        self.setCentralWidget(self.textEdit)
        self.textEdit.installEventFilter(self)

    def eventFilter(self, obj, event):
        if obj == self.textEdit:
            if event.type() == QtCore.QEvent.KeyPress:
                print "Ate key press", event.key()
                return True
            else:
                return False
        else:
            # pass the event on to the parent class
            return QtGui.QMainWindow.eventFilter(self, obj, event)

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)

    win = MainWindow()
    win.show()

    sys.exit(app.exec_())

# madoodia@gmail.com
# this method use shiboken and OpenMayaUI.MQtUtil
# to find main window

from PySide.QtGui import *
import shiboken

from maya import OpenMayaUI


class Window(QDialog):
    def __init__(self, parent=None):
        super(Window, self).__init__(parent)

        self.textBox = QLineEdit()
        self.btn = QPushButton("Apply")
        layout = QVBoxLayout(self)
        layout.addWidget(self.textBox)
        layout.addWidget(self.btn)

        self.btn.clicked.connect(self.callMe)

        self.textBox.textEdited.connect(self.updateUi)
        self.updateUi()

    def callMe(self):
        print self.textBox.text()

    def updateUi(self):
        enable = not (self.textBox.text() == "")
        self.btn.setEnabled(enable)


def getMayaWindow():
    ptr = OpenMayaUI.MQtUtil.mainWindow()
    return shiboken.wrapInstance(long(ptr), QMainWindow)

window = Window(parent=getMayaWindow())
window.show()

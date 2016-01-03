# madoodia@gmail.com
# new method
# this method of finding main window of host
# tested in maya and nuke, works fine
# in houdini and realflow does not support pyside
# but with pyqt4 it works fine

from PySide.QtGui import *


class Window(QDialog):

    def __init__(self, *args, **kwargs):
        super(Window, self).__init__(*args, **kwargs)

        # custom code here
        self.resize(400, 400)


def getMainWindow():
    mainWindow = QApplication.activeWindow()
    while True:
        if mainWindow.parent():
            mainWindow = mainWindow.parent()
        else:
            break
    return mainWindow


win = Window(parent=getMainWindow())
win.show()

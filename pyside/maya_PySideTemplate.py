# madoodia@gmail.com
# this method use shiboken and OpenMayaUI.MQtUtil
# to find main window

"""This Is A Template Of PySide Programs In Maya"""

from PySide.QtGui import *

import shiboken

from maya import OpenMayaUI


class Window(QDialog):

    """docstring for Window"""

    def __init__(self, *args, **kwargs):
        super(Window, self).__init__(*args, **kwargs)
        # Or
        # QDialog.__init__(*args, **kwargs)

        # custom code here
        self.resize(400, 400)
        self.setWindowTitle('PySide Template in Maya')


def getMainWindow():
    ptr = OpenMayaUI.MQtUtil.mainWindow()
    mainWin = shiboken.wrapInstance(long(ptr), QMainWindow)
    return mainWin


def show():
    win = Window(parent=getMainWindow())
    win.show()


show()

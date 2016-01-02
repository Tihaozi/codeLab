import sys
from contextlib import contextmanager

from PySide.QtGui import *


class Window(QWidget):

    def __init__(self, parent=None):
        super(Window, self).__init__(parent)


@contextmanager
def application():
    """Enable running from within and outside host"""

    if not QApplication.instance():  # or using qApp
        app = QApplication(sys.argv)
        yield
        app.exec_()
    else:
        yield


with application():
    window = Window()
    window.show()

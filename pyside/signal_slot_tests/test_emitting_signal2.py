#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
In this example, we show how to emit a signal.
"""

import sys
from PySide.QtGui import *
from PySide.QtCore import *


class Example(QMainWindow):

    closeApp = Signal()

    def __init__(self):
        super(Example, self).__init__()

        self.closeApp.connect(self.close)

        self.setGeometry(300, 300, 290, 150)
        self.setWindowTitle('Emit signal')

    # this is an event that happens when user click on window
    def mouseReleaseEvent(self, event):
        self.closeApp.emit()


def main():
    app = QApplication(sys.argv)
    ex = Example()
    ex.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()

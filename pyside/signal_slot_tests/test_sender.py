#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
In this example, we determine the event sender object.
"""

import sys

from PySide.QtGui import *


class Example(QMainWindow):

    def __init__(self):
        super(Example, self).__init__()

        # WIDGETS
        # We use self here because we don't have layout
        btn1 = QPushButton("Button 1", self)
        btn2 = QPushButton("Button 2", self)

        # set the postion of buttons manually
        btn1.move(30, 50)
        btn2.move(150, 50)

        # SIGNALS
        btn1.clicked.connect(self.buttonClicked)
        btn2.clicked.connect(self.buttonClicked)

        # SET WINDOW PROPERTIES
        # statusBar() is a method of QMainWindow that return QStatusBar
        # and showMessage is a slot of QStatusBar
        self.statusBar().showMessage('click on one button!')
        self.setGeometry(300, 300, 290, 150)
        self.setWindowTitle('Event sender')

    # SLOT
    def buttonClicked(self):
        # sender() is a Protected Functions of QObject that return a QObject
        sender = self.sender()
        self.statusBar().showMessage(sender.text() + ' was pressed')


def main():

    app = QApplication(sys.argv)
    ex = Example()
    ex.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()

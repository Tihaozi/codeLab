#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
In this example, we connect a signal
of a QSlider to a slot 
of a QLCDNumber.
"""

import sys
from PySide.QtGui import *
from PySide.QtCore import *


class Example(QWidget):

    def __init__(self):
        super(Example, self).__init__()

        lcd = QLCDNumber()
        sld = QSlider(Qt.Horizontal)

        vbox = QVBoxLayout()
        vbox.addWidget(lcd)
        vbox.addWidget(sld)

        sld.valueChanged.connect(lcd.display)

        self.setLayout(vbox)
        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Signal & slot')


def main():

    app = QApplication(sys.argv)
    ex = Example()
    ex.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()

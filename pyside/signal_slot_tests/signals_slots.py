#!/usr/bin/env python
# -*- coding: utf-8 -*-

# “signals and slots” mechanism - this is a high-level communication
# mechanism for responding to user interaction that allows us to
# ignore irrelevant detail.

# For this reason Qt, and therefore PySide, provides two
# communication mechanisms:
# 1. a low-level event-handling mechanism which is similar to
# those provided by all the other GUI libraries,
# 2. a high-level mechanism which Trolltech (makers of Qt) have called
# “signals and slots”.

import sys
from PySide.QtCore import *
from PySide.QtGui import *


if sys.version_info[:2] < (2, 5):
    def partial(func, arg):
        def callme():
            return func(arg)
        return callme
else:
    from functools import partial


class ZeroSpinBox(QSpinBox):

    # STATIC DATA
    zeros = 0
    atZero = Signal(int)    # QtCore.Signal

    def __init__(self, parent=None):
        super(ZeroSpinBox, self).__init__(parent)
        self.valueChanged.connect(self.check_zero)

    # SLOT
    def check_zero(self):
        if self.value() == 0:
            self.zeros += 1
            self.atZero.emit(self.zeros)


class Form1(QDialog):

    def __init__(self, parent=None):
        super(Form1, self).__init__(parent)

        dial = QDial()
        lcd = QLCDNumber()
        spb = ZeroSpinBox()

        dial.setNotchesVisible(True)

        layout = QHBoxLayout(self)
        layout.addWidget(dial)
        layout.addWidget(spb)
        layout.addWidget(lcd)

        # SIGNALS
        dial.valueChanged.connect(spb.setValue)
        dial.valueChanged.connect(lcd.display)

        spb.valueChanged.connect(dial.setValue)
        spb.valueChanged.connect(lcd.display)

        spb.atZero.connect(self.announce)

        self.setWindowTitle("Signals ans Slots")

    def announce(self, zeros):
        print "ZeroSpinBox has been at zero %d times" % zeros


class Form2(QDialog):

    def __init__(self, parent=None):
        super(Form2, self).__init__(parent)

        spb = ZeroSpinBox()

        layout = QHBoxLayout(self)
        layout.addWidget(spb)

        # SIGNALS
        spb.atZero.connect(self.announce)

        self.setWindowTitle("Signals ans Slots")

    def announce(self, zeros):
        print "ZeroSpinBox has been at zero %d times" % zeros


class Form3(QDialog):

    def __init__(self, parent=None):
        super(Form3, self).__init__(parent)

        button1 = QPushButton("One")
        button2 = QPushButton("Two")
        button3 = QPushButton("Three")
        button4 = QPushButton("Four")
        button5 = QPushButton("Five")

        self.label = QLabel("Press any button you want")

        layout = QHBoxLayout(self)
        layout.addWidget(button1)
        layout.addWidget(button2)
        layout.addWidget(button3)
        layout.addWidget(button4)
        layout.addWidget(button5)
        layout.addWidget(self.label)

        # SIGNALS
        button1.clicked.connect(partial(self.any_button, "One"))

        self.button2_callback = partial(self.any_button, "Two")
        button2.clicked.connect(self.button2_callback)

        self.button3_callback = lambda who="Three": self.any_button(who)
        button3.clicked.connect(self.button3_callback)

        button4.clicked.connect(lambda who="Four": self.any_button(who))

        button5.clicked.connect(self.clicked_slot)

        self.setWindowTitle("Connections")

    def one(self):
        self.label.setText("You clicked button 'One'")

    def any_button(self, who):
        self.label.setText("You clicked button '%s'" % who)

    def clicked_slot(self):
        sender = self.sender()
        if sender is None or not isinstance(sender, QPushButton):
            return
        self.label.setText("You clicked button '%s'" % sender.text())


if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = Form3()
    form.show()
    sys.exit(app.exec_())

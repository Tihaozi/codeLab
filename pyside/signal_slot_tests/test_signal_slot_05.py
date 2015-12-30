#!/usr/bin/env python
from PySide.QtCore import *


def saySomething():
    print 'Hello World!'


class Communicate(QObject):    # Must inherit QObject for signals

    # signal should be static data
    speak = Signal()

    def __init__(self):
        # Must init QObject else runtime error:
        # PySide.Signal object has no attribute 'emit'
        super(Communicate, self).__init__()

    def emittingSignal(self):
        self.speak.emit()

someone = Communicate()
# calling static data (speak) of the Class
someone.speak.connect(saySomething)

someone.emittingSignal()
# someone.speak.emit()  # works too

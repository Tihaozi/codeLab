#!/usr/bin/env python
from PySide.QtCore import *

# define a new slot that receives a C 'int' or a 'str'
# and has 'saySomething' as its name


@Slot(int)
@Slot(str)
def saySomething(stuff):
    print stuff


class Communicate(QObject):
    # create two new signals on the fly:
    # one will handle int type, the other will handle strings
    speakNumber = Signal(int)
    speakWord = Signal(str)

someone = Communicate()
# connect signal and slot properly
someone.speakNumber.connect(saySomething)
someone.speakWord.connect(saySomething)
# emit each 'speak' signal
someone.speakNumber.emit(10)
someone.speakWord.emit("Hello everybody!")

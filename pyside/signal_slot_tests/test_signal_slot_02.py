#!/usr/bin/env python
# steps of SIGNAL-SOT Mechanism:
# 1. creating a Signal
# 2. creating a slot
# 3. connecting the Signal ti the Slot
# 4. emitting the Signal

from PySide.QtCore import *


# define a new slot that receives a string and has
# 'saySomeWords' as its name
@Slot(str)
def saySomeWords(words):
    print words


class Communicate(QObject):
    # create a new signal on the fly and name it 'speak'
    speak = Signal(str)

someone = Communicate()
# connect signal and slot
someone.speak.connect(saySomeWords)
# emit 'speak' signal
someone.speak.emit("Hello everybody!")
someone.speak.emit("This is a SIGNAL!")
someone.speak.emit("Goodbye everybody!")

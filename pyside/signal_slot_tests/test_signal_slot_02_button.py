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


class PushButton(QObject):
    # create a new signal on the fly and name it 'clicked'
    clicked = Signal(str)

my_btn = PushButton()
# connect signal and slot
my_btn.clicked.connect(saySomeWords)
# emit 'clicked' signal
# actually clicking on a GUI's button is like to emitting a signal
my_btn.clicked.emit("Hello everybody!")
my_btn.clicked.emit("This is a SIGNAL!")
my_btn.clicked.emit("Goodbye everybody!")

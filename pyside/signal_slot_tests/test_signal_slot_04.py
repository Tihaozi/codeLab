#!/usr/bin/env python
from PySide.QtCore import *

# define a new slot that receives an C 'int' or a 'str'
# and has 'saySomething' as its name


@Slot(int)
@Slot(str)
def saySomething(stuff):
    print stuff


class Communicate(QObject):
    # create two new signals on the fly:
    # ne will handle int type, the other will handle strings
    speak = Signal((int,), (str,))

someone = Communicate()
# connect signal and slot. As 'int' is the default
# we have to specify the str when connecting the
# second signal
someone.speak.connect(saySomething)
someone.speak[str].connect(saySomething)

# emit 'speak' signal with different arguments.
# we have to specify the str as int is the default
someone.speak.emit(10)
someone.speak[str].emit("Hello everybody!")
someone.speak.emit("Hello str")  # return 0, because default is int

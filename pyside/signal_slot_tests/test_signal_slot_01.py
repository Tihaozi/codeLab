#!/usr/bin/env python

import sys
from PySide.QtGui import *


# SLOT
def sayHello():
    print 'Hello world!'

app = QApplication(sys.argv)

button = QPushButton('Say hello!')

# connect the clicked signal of the button to the sayHello slot
button.clicked.connect(sayHello)
button.show()

sys.exit(app.exec_())

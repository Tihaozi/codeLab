#!/usr/bin/python

# Import PySide classes
import sys
from PySide.QtGui import *

# Create a Qt application
app = QApplication(sys.argv)
# Create a Button and show it
button = QPushButton("Hello World")
button.show()
# Enter Qt application main loop
sys.exit(app.exec_())

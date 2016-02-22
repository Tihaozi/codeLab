#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from PySide import QtCore, QtGui, QtDeclarative

# Create Qt application and the QDeclarative view
app = QtGui.QApplication(sys.argv)
view = QtDeclarative.QDeclarativeView()
# Create an URL to the QML file
url = QtCore.QUrl('main_qml.qml')
# Set the QML file and show
view.setSource(url)
view.show()
# Enter Qt main loop
sys.exit(app.exec_())

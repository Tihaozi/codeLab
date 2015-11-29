import sys
from PyQt5 import QtCore, QtGui, QtQuick


if __name__ == "__main__":
    app = QtGui.QGuiApplication(sys.argv)

    view = QtQuick.QQuickView()

    engine = view.engine()
    context = engine.rootContext()

    view.setSource(QtCore.QUrl("Timeline.qml"))
    view.setResizeMode(view.SizeRootObjectToView)
    view.show()

    app.exec_()

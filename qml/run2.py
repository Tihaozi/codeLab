import sys
from PyQt5 import QtCore, QtWidgets, QtQuick


if __name__ == "__main__":

    app = QtWidgets.QApplication(sys.argv)

    view = QtQuick.QQuickView()
    view.setSource(QtCore.QUrl("main.qml"))
    view.show()

    sys.exit(app.exec_())

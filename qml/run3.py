"""
This will works if qml file main item is ApplicationWindow, not Item or Rectangle
"""

import sys
import os

from PyQt5.QtWidgets import QApplication
from PyQt5.QtQml import QQmlApplicationEngine

if __name__ == '__main__':
    full_directory = os.path.dirname(os.path.abspath(__file__))
    app = QApplication(sys.argv)
    engine = QQmlApplicationEngine()
    qml_file = os.path.join(full_directory, "main2.qml")
    engine.load(str(qml_file))

    window = engine.rootObjects()[0]
    window.show()
    sys.exit(app.exec_())

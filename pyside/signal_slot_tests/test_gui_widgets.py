import sys

from PySide.QtCore import *
from PySide.QtGui import *


class Form(QDialog):

    """"""

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)

        txt1 = QLineEdit("Hello world")
        chk1 = QCheckBox('Our CheckBox')
        btn1 = QPushButton('Close')

        # chk1.setCheckState(Qt.Checked)
        # or
        chk1.setChecked(True)


        # txt1.setAlignment(Qt.AlignLeft)   # default
        # txt1.setAlignment(Qt.AlignHCenter)
        # txt1.setAlignment(Qt.AlignRight)
        # txt1.setCursor(Qt.WaitCursor)
        # txt1.setLayoutDirection(Qt.RightToLeft)

        layout = QVBoxLayout(self)

        layout.addWidget(txt1)
        layout.addWidget(chk1)
        layout.addWidget(btn1)

        btn1.clicked.connect(self.close)
        # or
        # btn1.clicked.connect(app.quit)

        self.resize(400, 400)
        # self.setWindowFlags(Qt.Window)
        # self.setWindowFlags(Qt.Widget)
        # self.setWindowFlags(Qt.SplashScreen)


def main():
    app = QApplication(sys.argv)
    # app = QCoreApplication(sys.argv)       # for non-GUI application
    # app.addLibraryPath('D:/')
    # print app.applicationDirPath()
    # print app.applicationFilePath()
    # print app.libraryPaths()

    form = Form()
    form.show()

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

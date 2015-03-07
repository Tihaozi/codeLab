from __future__ import division
import sys
import math

from PySide import QtCore, QtGui


class Form(QtGui.QDialog):
    """The Calculate Application Main class"""

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)

        self.browser = QtGui.QTextBrowser()
        self.line_edit = QtGui.QLineEdit("Type an expression and press Enter")
        self.line_edit.selectAll()

        layout = QtGui.QVBoxLayout(self)
        layout.addWidget(self.browser)
        layout.addWidget(self.line_edit)

        self.line_edit.returnPressed.connect(self.update_ui)
        self.line_edit.setFocus()
        self.setWindowTitle("Calculate")

    def update_ui(self):
        try:
            text = unicode(self.line_edit.text())
            self.browser.append("%s = <b>%s</b>" % (text, eval(text)))
            # self.line_edit.clear()
        except:
            self.browser.append("<font color=red>%s is invalid!</font>" % text)
            # self.line_edit.clear()


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    form = Form()
    form.show()
    sys.exit(app.exec_())

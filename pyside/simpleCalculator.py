from __future__ import division
import sys

from PySide.QtGui import *


class Form(QDialog):

    """The Calculate Application Main class"""

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)

        # CREATING WIDGETS
        self.browser = QTextBrowser()
        self.line_edit = QLineEdit()

        # SET PROPERTIES
        # self.line_edit.selectAll()
        self.line_edit.setPlaceholderText("Type an expression and press Enter")
        self.line_edit.setFocus()

        # LAYOUT WIDGETS
        layout = QVBoxLayout(self)  # new style of setLayout
        layout.addWidget(self.browser)
        layout.addWidget(self.line_edit)

        # SIGNALS
        self.line_edit.returnPressed.connect(self.update_ui)

        # SET CLASS PROPERTIES
        # self.setLayout(layout) 	# old style of setLayout
        self.setWindowTitle("Calculate")

    # SLOTS
    def update_ui(self):
        try:
            text = unicode(self.line_edit.text())
            self.browser.append("%s = <b>%s</b>" % (text, eval(text)))
            # self.line_edit.clear()
        except:
            self.browser.append("<font color=red>%s is invalid!</font>" % text)
            # self.line_edit.clear()


# RUNNING PROGRAM
if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = Form()
    form.show()
    sys.exit(app.exec_())

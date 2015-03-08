import sys

from PySide import QtGui


class Form(QtGui.QDialog):
    """"""

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)

        principal_lbl = QtGui.QLabel("Principal:")
        rate_lbl = QtGui.QLabel("Rate:")
        years_lbl = QtGui.QLabel("Years:")
        amount_lbl = QtGui.QLabel("Amount:")
        self.result_lbl = QtGui.QLabel("$ 0.00")

        self.principal_spin = QtGui.QDoubleSpinBox()
        self.principal_spin.setRange(1.00, 1000000.00)
        self.principal_spin.setValue(1.00)
        self.principal_spin.setPrefix('$ ')

        self.rate_spin = QtGui.QDoubleSpinBox()
        self.rate_spin.setRange(0.00, 100.00)
        self.rate_spin.setValue(1.00)
        self.rate_spin.setSuffix(' %')

        self.years_comb = QtGui.QComboBox()
        self.years_comb.addItems(['1 Year', '2 Years', '3 Years'])

        grid = QtGui.QGridLayout(self)
        grid.addWidget(principal_lbl, 0, 0)
        grid.addWidget(self.principal_spin, 0, 1)
        grid.addWidget(rate_lbl, 1, 0)
        grid.addWidget(self.rate_spin, 1, 1)
        grid.addWidget(years_lbl, 2, 0)
        grid.addWidget(self.years_comb, 2, 1)
        grid.addWidget(amount_lbl, 3, 0)
        grid.addWidget(self.result_lbl, 3, 1)

        self.principal_spin.valueChanged.connect(self.updateUi)
        self.rate_spin.valueChanged.connect(self.updateUi)
        self.years_comb.currentIndexChanged.connect(self.updateUi)

        self.setWindowTitle('Interest')

    def updateUi(self):
        principal = self.principal_spin.value()
        rate = self.rate_spin.value()
        years = self.years_comb.currentIndex() + 1

        amount = principal * ((1 + (rate / 100.0)) ** years)

        self.result_lbl.setText('$ %s' % unicode(amount))


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    form = Form()
    form.show()
    sys.exit(app.exec_())

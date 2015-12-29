import sys

from PySide.QtGui import *


class Form(QDialog):

    """"""

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)

        # WIDGETS
        principal_lbl = QLabel("Principal:")
        rate_lbl = QLabel("Rate:")
        years_lbl = QLabel("Years:")
        amount_lbl = QLabel("Amount:")
        self.result_lbl = QLabel("$ 0.00")

        self.principal_spin = QDoubleSpinBox()
        self.rate_spin = QDoubleSpinBox()
        self.years_comb = QComboBox()

        # SET WIDGETS PROPERTIES
        self.principal_spin.setRange(1.00, 1000000.00)
        self.principal_spin.setValue(1.00)
        self.principal_spin.setPrefix('$ ')
        self.rate_spin.setRange(0.00, 100.00)
        self.rate_spin.setValue(1.00)
        self.rate_spin.setSuffix(' %')
        self.years_comb.addItems(['1 Year', '2 Years', '3 Years'])

        # LAYOUT
        grid = QGridLayout(self)
        grid.addWidget(principal_lbl, 0, 0)
        grid.addWidget(self.principal_spin, 0, 1)
        grid.addWidget(rate_lbl, 1, 0)
        grid.addWidget(self.rate_spin, 1, 1)
        grid.addWidget(years_lbl, 2, 0)
        grid.addWidget(self.years_comb, 2, 1)
        grid.addWidget(amount_lbl, 3, 0)
        grid.addWidget(self.result_lbl, 3, 1)

        # SIGNALS
        self.principal_spin.valueChanged.connect(self.updateUi)
        self.rate_spin.valueChanged.connect(self.updateUi)
        self.years_comb.currentIndexChanged.connect(self.updateUi)

        self.setWindowTitle('Interest')

    # SLOTS
    def updateUi(self):
        principal = self.principal_spin.value()
        rate = self.rate_spin.value()
        years = self.years_comb.currentIndex() + 1

        amount = principal * ((1 + (rate / 100.0)) ** years)

        self.result_lbl.setText('$ %s' % unicode(amount))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = Form()
    form.show()
    sys.exit(app.exec_())

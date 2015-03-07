import sys
import urllib2

from PySide import QtCore, QtGui


class Form(QtGui.QDialog):
    """The Currency Application base class"""

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)

        date = self.get_data()
        rates = sorted(self.rates.keys())

        # WIDGETS
        date_label = QtGui.QLabel(date)
        self.from_cmb = QtGui.QComboBox()
        self.from_cmb.addItems(rates)
        self.from_spb = QtGui.QDoubleSpinBox()
        self.from_spb.setRange(0.01, 10000000.00)
        self.from_spb.setValue(1.00)
        self.to_cmb = QtGui.QComboBox()
        self.to_cmb.addItems(rates)
        self.to_label = QtGui.QLabel("1.00")

        # LAYING OUT
        grid = QtGui.QGridLayout(self)
        grid.addWidget(date_label, 0, 0)
        grid.addWidget(self.from_cmb, 1, 0)
        grid.addWidget(self.from_spb, 1, 1)
        grid.addWidget(self.to_cmb, 2, 0)
        grid.addWidget(self.to_label, 2, 1)

        # SIGNALS
        self.from_cmb.currentIndexChanged.connect(self.update_ui)
        self.to_cmb.currentIndexChanged.connect(self.update_ui)
        self.from_spb.valueChanged.connect(self.update_ui)

    def get_data(self):
        self.rates = {}
        try:
            date = "Unknown"
            fh = urllib2.urlopen("http://www.bankofcanada.ca/en/markets/csv/exchange_eng.csv")
            for line in fh:
                if not line or line.startswith(('#', 'Closing')):
                    continue
                fields = line.split(',')
                if line.startswith("Date"):
                    date = fields[-1]
                else:
                    try:
                        value = float(fields[-1])
                        self.rates[unicode(fields[0])] = value
                    except ValueError:
                        pass
            return "Exchange rate date: " + date
        except Exception, e:
            return "Failed to download:\n%s" % e


    def update_ui(self):
        to = unicode(self.to_cmb.currentText())
        from_ = unicode(self.from_cmb.currentText())
        amount = (self.rates[from_] / self.rates[to]) * self.from_spb.value()
        self.to_label.setText("%0.2f" % amount)



if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    form = Form()
    form.show()
    sys.exit(app.exec_())

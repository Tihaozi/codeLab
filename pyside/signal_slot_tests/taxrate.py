from PySide.QtCore import *


class TaxRate(QObject):

    # CUSTOM SIGNAL
    rateChanged = Signal(float)

    def __init__(self):
        super(TaxRate, self).__init__()
        self.__rate = 17.5

    def rate(self):
        return self.__rate

    def setRate(self, rate):
        if rate != self.__rate:
            self.__rate = rate
            self.rateChanged.emit(self.__rate)


def rateChanged_slot(value):
    print "TaxRate changed to %.2f%%" % value


if __name__ == "__main__":
    vat = TaxRate()
    vat.rateChanged.connect(rateChanged_slot)
    vat.setRate(17.5)
    print vat.rate()
    vat.setRate(18.5)
    print vat.rate()

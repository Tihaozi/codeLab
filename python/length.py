from __future__ import division


class Length(object):

    convert = dict(mi=621.371e-6, miles=621.371e-6, mile=621.371e-6,
                   yd=1.094, yards=1.094, yard=1.094,
                   ft=3.281, feet=3.281, foot=3.281,
                   inches=39.37, inch=39.37,
                   mm=1000, millimeter=1000, millimeters=1000,
                   millimetre=1000, millimetres=1000,
                   cm=100, centimeter=100, centimeters=100,
                   centimetre=100, centimetres=100,
                   m=1.0, meter=1.0, meters=1.0, metre=1.0, metres=1.0,
                   km=0.001, kilometer=0.001, kilometers=0.001,
                   kilometre=0.001, kilometres=0.001)
    convert["in"] = 39.37
    numbers = frozenset("0123456789.eE")

    def __init__(self, length=None):
        if length is None:
            self.__amount = 0.0
        else:
            digits = ""
            for i, char in enumerate(length):
                if char in Length.numbers:
                    digits += char
                else:
                    self.__amount = float(digits)
                    unit = length[i:].strip().lower()
                    break
            else:
                raise ValueError, "need an amount and a unit"
            self.__amount /= Length.convert[unit]

    def set(self, length):
        self.__init__(length)

    def to(self, unit):
        return self.__amount * Length.convert[unit]

    def copy(self):
        other = Length()
        other.__amount = self.__amount
        return other
    """
    def copy(self): # Alternative #1
        import copy
        return copy.copy(self)

    def copy(self): # Alternative #2
        return eval(repr(self))
    """

    @staticmethod
    def units():
        return Length.convert.keys()

    def __cmp__(self, other):
        return cmp(self.__amount, other.__amount)

    def __repr__(self):
        return "Length('%.6fm')" % self.__amount

    def __str__(self):
        return "%.3fm" % self.__amount

    def __add__(self, other):
        return Length("%fm" % (self.__amount + other.__amount))

    def __iadd__(self, other):
        self.__amount += other.__amount
        return self

    def __mul__(self, other):
        if isinstance(other, Length):
            raise ValueError, \
                "Length * Length produces an area not a Length"
        return Length("%fm" % (self.__amount * other))

    def __rmul__(self, other):
        return Length("%fm" % (other * self.__amount))

    def __imul__(self, other):
        self.__amount *= other
        return self

    def __truediv__(self, other):
        return Length("%fm" % (self.__amount / other))

    def __itruediv__(self, other):
        self.__amount /= other
        return self

    def __float__(self):
        return self.__amount

    def __int__(self):
        return int(round(self.__amount))


if __name__ == "__main__":
    distance = Length("120 miles")
    km = distance.to("km")
    print km

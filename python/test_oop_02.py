class Rectangle(object):

    """Another OOP Test"""

    def __init__(self, width, height):
        super(Rectangle, self).__init__()
        self._width = width
        self._height = height

    def get_width(self):
        return self._width

    def set_width(self, width):
        self._width = width

    def get_height(self):
        return self._height

    def set_height(self, height):
        self._height = height

    def area(self):
        return self._width * self._height


r = Rectangle(4, 6)
print r.area()
r.set_width(5)
print r.area()

print "-" * 30
# ----------------------------------------------------------------------------------


class Rectangle2(object):

    """..."""

    def __init__(self, width, height):
        super(Rectangle2, self).__init__()
        self._width = width
        self._height = height

    def _area(self):
        return self._width * self._height

    area = property(fget=_area)


r2 = Rectangle2(10, 11)
print r2.area


print "-" * 30
# ----------------------------------------------------------------------------------


class Rectangle3(object):

    """..."""

    def __init__(self, width, height):
        super(Rectangle3, self).__init__()
        self._width = width
        self._height = height

    def _get_width(self):
        return self._width

    def _set_width(self, width):
        self._width = width

    def _area(self):
        return self._width * self._height

    area = property(fget=_area)
    width = property(fget=_get_width, fset=_set_width)


r3 = Rectangle3(12, 5)
print r3.area
print r3.width
r3.width = 14
print r3.area
print r3.width


print "-" * 30
# ----------------------------------------------------------------------------------


class Rectangle4(object):

    """..."""

    def __init__(self, width, height):
        super(Rectangle4, self).__init__()
        self._width = width
        self._height = height

    @property
    def w_a(self):
        return self._width

    @w_a.setter
    def w_a(self, width):
        self._width = width

    # area = property(fget=area)
    @property
    def area(self):
        return self._width * self._height


r4 = Rectangle4(12, 5)
print r4.area
print r4.w_a
r4.w_a = 14
print r4.area
print r4.w_a


print "-" * 30
# ----------------------------------------------------------------------------------

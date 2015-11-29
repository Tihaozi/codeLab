# create interface
class Dimension(object):

    def area(self):
        raise NotImplementedError, "Dimension.area()"


d = Dimension()
d.area()

# create interface
# you should derive a class from Dimention class then 
# implement area method then call it
#  it is not possible to create instance from interface classes

class Dimension(object):

    def area(self):
        raise NotImplementedError, "Dimension.area()"


d = Dimension()
d.area()

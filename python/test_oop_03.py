"""About Special Methods"""


class TestSpecialMethods(object):

    """docstring for TestSpecialMethods"""

    def __init__(self, *args):
        super(TestSpecialMethods, self).__init__()
        self.args = args
        print "Here is initializer special method"

    def __call__(self, *args):
        print "here is callable special method"

    def __repr__(self):
        return "here is repr special method"

    # def __str__(self):
    #     return "here is str special method"


# calling __init__
tsm1 = TestSpecialMethods()

# calling __call__
tsm1()

# calling __repr__
# repr(tsm1)

# calling __str__
# if __str__ is not exists __repr__ will be called
print tsm1

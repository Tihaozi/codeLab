class Test(object):

    """docstring for Test"""

    def __init__(self):
        super(Test, self).__init__()

    def test1(self, msg):
        print msg

    def _test2(self, msg):
        print msg

    def __test3(self, msg):
        print msg

    def callme(self):
        self.__test3("calling very private method")

    def __str__(self):
        return "Here is __str__"


t = Test()
t.test1("public")
t._test2("private")  # don't call this method
# t.__test3("very private")  # don't call this method
t.callme()

print t  # __str__ method is called

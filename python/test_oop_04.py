# This is class test for static data, static methods and decorators


class Student(object):

    """..."""

    all_students = 0  # static data

    def __init__(self):
        super(Student, self).__init__()
        Student.all_students += 1

    @staticmethod
    def count():
        return Student.all_students


# s1 = Student()
# s2 = Student()
# s3 = Student()
# print Student.count()

# print "-" * 30 + "\n"

class TestDec(object):

    """..."""

    def __init__(self):
        super(TestDec, self).__init__()

    def logger(self, *fn):
        def wrapped():
            return "here is logger" + fn()
        return wrapped

    @logger
    def count(self):
        print "here is count method"

td = TestDec()
td.count()

# ----------------------------------
# sample for using decorator
# important for Decorators
def makebold(fn):
    def wrapped():
        return "<b>" + fn() + "</b>"
    return wrapped


def makeitalic(fn):
    def wrapped():
        return "<i>" + fn() + "</i>"
    return wrapped


@makebold
@makeitalic
def hello():
    return "hello world"

# print hello()  # returns <b><i>hello world</i></b>
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



class TestDec(object):

    """..."""

    def __init__(self):
        super(TestDec, self).__init__()

    def logger(self):
        print "here we are\n"

    @logger
    def count(self):
        print "here is count method"

td = TestDec()
td.count()
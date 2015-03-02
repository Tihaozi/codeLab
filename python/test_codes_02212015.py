#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
This Codes is related to Rapid GUI Programming Book First 3 chapters.
"""


print "Hello World!"

x = 71
y = 'Dove'
z = None    # the variable has no value

print x, ':', type(x), '\n', y, ':', type(y)
print id(x), '\n', id(y)

print x == y    # Value Comparison
print x is y    # Identity Comparison

# print x + y     # Give error

var1 = 'hello'
print var1[0]

g = 'Green'
t = 'Trees'
print g + ' ' + t

euro = unichr(8364)
# print euro

# print ord(euro)

# euro = u"\N{euro sign}"           # \N{name} Unicode character name
# print euro

phrase = "The red balloon"
phrase[:3]      # from 0 to 2
phrase[-3:]     # from -3 to end
phrase[4:7]     # 4, 5, 6

p = "pad"
# p[1] = "o" # WRONG

p = "pad"
p = p[:1] + "o" + p[2:]
print p     # 'pod'

p = "pad"
p = "o".join((p[:1], p[2:]))
print p     # 'pod'

print "........................................"


'''
Python makes a distinction between lists and tuples.
Lists are written as [1, 2, 3], are mutable, and cannot be used as the keys of dictionaries 
(dictionary keys must be immutable in Python).
Tuples are written as (1, 2, 3), are immutable and thus can be used as the keys of dictionaries,
 provided all elements of the tuple are immutable.
'''
# .......   Tuples   ............
empty = ()
print type(empty)

one = ("Canary")
print type(one)
one = ("Canary",)
print type(one)

things = ("Parrot", 3.5, u"\u20AC")
print type(things)

items = "Dog", 99, "Cow", 28
print type(items)

names = ("Albert", "Brenda", "Cecil", "Donna")
print names[:3]

pets = (("Dog", 2), ("Cat", 3), ("Hamster", 14))

print len(pets)

print pets[2][1]
print pets[1][0:2]

print tuple("some text")
print "........................................"
# .......   Lists    ............

fruits = ["Apple", "Hawthorn", "Loquat", "Medlar", "Pear", "Quince"]
print type(fruits)
print fruits[:2]
print fruits[-1]

fruits.insert(4, "Rowan")       # equal to fruit[4:4] = ["Rowan"]
print fruits
del fruits[3]                   # equal to fruit[4:5] = []
print fruits

f1 = fruits.pop()
print f1
print fruits

# Copy Lists
# shallow copying
fruits1 = ["Apple", "Hawthorn", "Loquat"]
fruits2 = fruits1

fruits2[2] = "Orange"
print fruits1, fruits2

# deep copying
fruits1 = ["Apple", "Hawthorn", "Loquat"]
fruits2 = fruits1[:]

fruits2[2] = "Orange"
print fruits1, fruits2

print "........................................"
# .......   Dictionaries     ............
# A dictionary holds a set of unordered key–value pairs and provides
# very fast key lookup. Keys are unique and must be of an immutable type,
# such as a Python string, a number, or a tuple
# the value can be of any type including collection
# types, so it is possible to create arbitrarily nested data structures

dict1 = dict(a=1, b=2, c=3)
dict2 = {"a": 1, "b": 2, "c": 3}

print dict1 == dict2
print dict1 is dict2
print dict1
print dict2

insects = {"Dragonfly": 5000, "Praying Mantis": 2000,
           "Fly": 120000, "Beetle": 350000}
print insects

print insects["Dragonfly"]      # is equal to insects.get("Dragonfly")
insects["Grasshooper"] = 20000
print insects

del insects["Fly"]

insects.pop("Beetle")
print insects

print len(insects)
print insects.keys()
print insects.values()
print insects.items()

points3d = {(3, 7, -2): "Green", (4, -1, 11): "Blue",
            (8, 15, 6): "Yellow"}
print points3d
print points3d[(8, 15, 6)]

print "........................................"
# .......   Sets   ............
# Every item in a set is unique
L = [1, 2, 3, 4, 5, 1, 3, 6, 5]
print L
S = list(set(L))
print S

unicorns = set(("Narwhal", "Oryx", "Eland"))
print "Mutant Goat" in unicorns
print "Oryx" in unicorns

unicorns.add("Mutant Goat")
unicorns.remove("Narwhal")

print unicorns

print "........................................"
# .......   Built-in Functions   ............
# help(str)
print max(insects)
print sum(S)

# print dir("a")
# print dir(dict2)
# print dir(L)

# Math
print divmod(10, 3)
print pow(2, 6)

import math
# dir(math)
print math.pi

print math.sin(math.pi)

# ................      Control Structures      .......................
from PyQt4.QtCore import *
now = QDate.currentDate()
never = QDate()
print bool(now), bool(never)  # Prints "True False"

x = 10
print "x is zero or positive" if x >= 0 else "x is negative"


count = 10
while count != 0:
    print count,
    count -= 1


while True:
    item = getNextItem()
    if not item:
        break
    processItem(item)


i = 0
while i < len(mylist):
    if mylist[i] == item:
        print "Found the item"
        break
        i += 1
    else:
        print "Didn't find the item"

for char in "aeiou":
    print "%s=%d" % (char, ord(char)),

for i in range(10):
    print i,


presidents = dict(Washington=(1789, 1797), Adams=(1797, 1801),
                  Jefferson=(1801, 1809), Madison=(1809, 1817))
for key in presidents.keys():
    if key == "Adams":
        del presidents[key]
    else:
        print president, presidents[key]


keys = presidents.keys()  # Or: keys = list(presidents)
keys.sort()
for key in keys:
    print "%s: %d-%d" % (key, presidents[key][0], presidents[key][1])


# list comprehensions
fives = [x for x in range(50) if x % 5 == 0]
# generator
fives = (x for x in range(50) if x % 5 == 0)


# Functions
def functionName(optional_parameters):
    suite


def greeting():
    print "Welcome to Python"


def frange(start, stop, inc):
    result = []
    while start < stop:
        result.append(start)
        start += inc
    return result


# implementin frange like range()
def frange(arg0, arg1=None, arg2=None):
    """Returns a list of floats using range-like syntax
    frange(start, stop, inc) # start = arg0 stop = arg1 inc = arg2
    frange(start, stop) # start = arg0 stop = arg1 inc = 1.0
    frange(stop) # start = 0.0 stop = arg0 inc = 1.0
    """
    start = 0.0
    inc = 1.0
    if arg2 is not None:     # 3 arguments given
        start = arg0
        stop = arg1
        inc = arg2
    elif arg1 is not None:   # 2 arguments given
        start = arg0
        stop = arg1
    else:                    # 1 argument given
        stop = arg0
    # Build and return a list
    result = []
    while start < (stop - (inc / 2.0)):
        result.append(start)
        start += inc
    return result

# We could have compared to None using the syntax
# arg2 != None, but using is not is more efficient and better Python style.

# Changing function to generator
# Return each value on demand


def frange(arg0, arg1=None, arg2=None):
    """Returns a list of floats using range-like syntax
    frange(start, stop, inc) # start = arg0 stop = arg1 inc = arg2
    frange(start, stop) # start = arg0 stop = arg1 inc = 1.0
    frange(stop) # start = 0.0 stop = arg0 inc = 1.0
    """
    start = 0.0
    inc = 1.0
    if arg2 is not None:     # 3 arguments given
        start = arg0
        stop = arg1
        inc = arg2
    elif arg1 is not None:   # 2 arguments given
        start = arg0
        stop = arg1
    else:                    # 1 argument given
        stop = arg0
    while start < (stop - (inc / 2.0)):
        yield start
        start += inc

# if we want to import frange function from IDLE
# we should do this: (if this file name is frange)
import sys
sys.path.append("Address of this file")
import frange
frange.frange(3, 10, 2.5)


# New function
def simplify(text, space=" \t\r\n\f", delete=""):
    result = []
    word = ""
    for char in text:
        if char in delete:
            continue
        elif char in space:
            if word:
                result.append(word)
                word = ""
        else:
            word += char
    if word:
        result.append(word)
    return " ".join(result)

"""
The code we have used for simplify() is not as Pythonic as it could be. For
example, we should really store word as a list of characters rather than as a
string, and we don’t need the space parameter since we could use the string
object’s isspace() method instead.
"""


# Lambda
cube = lambda x: pow(x, 3)


# Dynamic Function Creation
#!/usr/bin/env python
def hello():
    print "Hello"


def world():
    print "World"


def main():
    hello()
    world()
main()


# Partial Function Application      "currying"
def hello(who):
    print "Hello", who


def goodbye(who):
    print "Goodbye", who
funclist = [hello, goodbye]
# Some time later
for func in funclist:
    func("Me")


# ..
def action(button):
    print "You pressed button", button

import functools
buttonOneFunc = functools.partial(action, "One")
buttonTwoFunc = functools.partial(action, "Two")

buttonOneFunc()     # action("One")
buttonTwoFunc()     # action("Two")


# or
def partial(func, arg):
    def callme():
        return func(arg)
    return callme

# or
import sys
if sys.version_info[:2] < (2, 5):
    def partial(func, arg):
        def callme():
            return func(arg)
        return callme
else:
    from functools import partial


# Exception Handling
try:
    suite1
except exceptions:
    suite2
else:
    suite3

try:
    pass
except IndexError:
    pass
except ValueError, e:
    pass
except (IOError, OSError), e:
    pass
except:         # should not be used
    pass

try:
    process()
except IndexError, e:
    print "Error: %s" % e
except LookupError, e:
    print "Error: %s" % e

# Comparison .........................

# Testing for errors
result = ""
i = text.find("<")
if i > -1:
    j = text.find(">", i + 1)
    if j > -1:
        result = text[i:j + 1]
print result

# Exception handling
try:
    i = text.index("<")
    j = text.index(">", i + 1)
    result = text[i:j + 1]
except ValueError:
    result = ""
print result
# Comparison .........................


def simplify(text, space=" \t\r\n\f", delete=""):
    if not space and not delete:
        raise Exception, "Nothing to skip or delete"


class SimplifyError(Exception):
    pass


def simplify(text, space=" \t\r\n\f", delete=""):
    if not space and not delete:
        raise SimplifyError, "Nothing to skip or delete"

# or
def simplify(text, space=" \t\r\n\f", delete=""):
    assert space or delete     #raise an AssertionError

# Comparison .........................    
found = False
for x in range(len(grid)):
    for y in range(len(grid[x])):
        for z in range(len(grid[x][y])):
            if grid[x][y][z] == target:
                found = True
                break
        if found:
            break
    if found:
        break
if found:
    print "Found at (%d, %d, %d)" % (x, y, z)
else:
    print "Not found"

# or
class FoundException(Exception): pass
try:
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            for z in range(len(grid[x][y])):
                if grid[x][y][z] == target:
                    raise FoundException
except FoundException:
    print "Found at (%d, %d, %d)" % (x, y, z)
else:
    print "Not found"

# Comparison .........................    
filehandle = open(filename)
try:
    for line in filehandle:
        process(line)
finally:
    filehandle.close()

fh = None
try:
    try:
        fh = open(fname)
        process(fh)
    except IOError, e:
        print "I/O error: %s" % e
finally:
    if fh:
        fh.close()

# or
fh = None
try:
    fh = open(fname)
    process(fh)
except IOError, e:
    print "I/O error: %s" % e
finally:
    if fh:
        fh.close()


# Classes and Modules
class ClassName(base_classes):
    suite


class TestClass(object):
    pass


tc = TestClass()


class Chair(object):
    """This class represents chairs."""

    def __init__(self, name, legs=4):
        self.name = name
        self.legs = legs


chair1 = Chair("Barcelona")
chair2 = Chair("Bar Stool", 1)


class Rectangle(object):

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def getWidth(self):
        return self.width

    def setWidth(self, width):
        self.width = width

    def getHeight(self):
        return self.height

    def setHeight(self, height):
        self.height = height

    def area(self):
        return self.getWidth() * self.getHeight()


rect = Rectangle(50, 10)
print rect.area()    # Prints "500"
rect.setWidth(20)


#Second Verison of Rectangle
class Rectangle(object):

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def _area(self):
        return self.width * self.height

    area = property(fget=_area)


rect = Rectangle(5, 4)
print rect.width, rect.height, rect.area     # Prints (5, 4, 20)
rect.width = 6


# property()
def _width(self):
    return self.__width


def _setWidth(self, width):
    # Perform some computation
    self.__width = width

width = property(fget=_width, fset=_setWidth)


# reimplementing __cmp__() method for Comparison
def __cmp__(self, other):
    if (self.width != other.width):
        return cmp(self.width, other.width)
    return cmp(self.height, other.height)


# bool(rectA), or if rectB:
def __nonzero__(self):
    return self.width or self.height


# eval()
def __repr__(self):
    return "Rectangle(%d, %d)" % (self.width, self.height)


# Static Data, and Static Methods and Decorators
class Balloon(object):

    unique_colors = set()

    def __init__(self, color):
        self.color = color
        Balloon.unique_colors.add(color)

    @staticmethod
    def uniqueColorCount():
        return len(Balloon.unique_colors)

    @staticmethod
    def uniqueColors():
        return Balloon.unique_colors.copy()

"""
def staticmethod(fn):
    def wrapped():
        pass
    return wrapped
"""


# .......................................................
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

print hello()  # returns <b><i>hello world</i></b>
# .......................................................

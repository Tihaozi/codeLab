######################################### Built-in Functions #########################################
abs(x) 			# Return the absolute value of a number
# .........................................
all(iterable)	# Return True if all elements of the iterable are true 
# equivalent to:
def all(iterable):
    for element in iterable:
        if not element:
            return False
    return True
# .........................................
any(iterable) 	# Return True if any element of the iterable is true

def any(iterable):
    for element in iterable:
        if element:
            return True
    return False
# .........................................
basestring() 	# This abstract type is the superclass for str and unicode
obj = 'hello'
isinstance(obj, basestring)  # Return True
# .........................................
bin(x) 		# Convert an integer number to a binary string
# .........................................
bool([x]) 	# Convert a value to a Boolean, using the standard truth testing procedure
# .........................................
bytearray([source[, encoding[, errors]]]) 	# Return a new array of bytes
# .........................................
callable(object) 	# Return True if the object argument appears callable, False if not
def test():
	pass
callable(test)		# Return True
class A:
	pass
a = A()
callable(A)			# Return True
callable(a)			# Return False

class B:
	def __call__(self):
		pass
b = B()
callable(B)			# Return True
callable(b)			# Return True
# .........................................
chr(i) 		# Return a string of one character whose ASCII code is the integer i
# .........................................
classmethod(function) 		# Return a class method for function.
class C(object):
    @classmethod
    def f(cls, arg1, arg2, ...):
        ...
# The @classmethod form is a function decorator
# It can be called either on the class (such as C.f()) or on an instance (such as C().f()). 
# The instance is ignored except for its class. If a class method is called for a derived class, the derived class object is passed as the implied first argument.
# .........................................
cmp(x, y) 	# Compare the two objects x and y and return an integer according to the outcome
# .........................................
compile(source, filename, mode[, flags[, dont_inherit]]) 		# Compile the source into a code or AST object
# .........................................
complex([real[, imag]]) 		# Create a complex number with the value real + imag*j or convert a string or number to a complex number
# .........................................
delattr(object, name) 		# This is a relative of setattr(). The arguments are an object and a string
# .........................................
dict(**kwarg) 
dict(mapping, **kwarg) 
dict(iterable, **kwarg) 		# Create a new dictionary. The dict object is the dictionary class
# .........................................
dir([object]) 		# Without arguments, return the list of names in the current local scope
class Shape(object):
    def __dir__(self):
        return ['area', 'perimeter', 'location']
s = Shape()
dir(s)			# ['area', 'perimeter', 'location']
# .........................................
divmod(a, b) 	# Take two (non complex) numbers as arguments and return a pair of numbers consisting of their quotient and remainder when using long division
# .........................................
enumerate(sequence, start=0) 	# Return an enumerate object. sequence must be a sequence, an iterator, or some other object which supports iteration
seasons = ['Spring', 'Summer', 'Fall', 'Winter']
list(enumerate(seasons))	# [(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
list(enumerate(seasons, start=1))	# [(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]

# Equivalent to:
def enumerate(sequence, start=0):
    n = start
    for elem in sequence:
        yield n, elem
        n += 1
# .........................................
eval(expression[, globals[, locals]]) 	# The arguments are a Unicode or Latin-1 encoded string and optional globals and locals. If provided, globals must be a dictionary. If provided, locals can be any mapping object.
# .........................................
execfile(filename[, globals[, locals]]) 	# This function is similar to the exec statement, but parses a file instead of a string
# .........................................
file(name[, mode[, buffering]]) 	# Constructor function for the file type, described further in section File Objects
isinstance(f, file)
# .........................................
filter(function, iterable) 	# Construct a list from those elements of iterable for which function returns true
# Note that filter(function, iterable) is equivalent to [item for item in iterable if function(item)]
# .........................................
float([x]) 	# Convert a string or a number to floating point
# .........................................
format(value[, format_spec]) 	# Convert a value to a “formatted” representation, as controlled by format_spec
# .........................................
frozenset([iterable]) 	# Return a new frozenset object, optionally with elements taken from iterable
# .........................................
getattr(object, name[, default]) 	# Return the value of the named attribute of object
# .........................................
globals() 	# Return a dictionary representing the current global symbol table
# .........................................
hasattr(object, name) 	# The arguments are an object and a string
# .........................................
hash(object) 	# Return the hash value of the object (if it has one). Hash values are integers
# .........................................
help([object]) 	# Invoke the built-in help system
# .........................................
hex(x) 	# Convert an integer number (of any size) to a hexadecimal string
# .........................................
id(object) 	# Return the “identity” of an object
# .........................................
input([prompt]) 	# Equivalent to eval(raw_input(prompt)).
# .........................................
int(x=0) 
int(x, base=10) 	# Convert a number or string x to an integer, or return 0 if no arguments are given
# .........................................
isinstance(object, classinfo) 	# Return true if the object argument is an instance of the classinfo argument
# .........................................
issubclass(class, classinfo) 	# Return true if class is a subclass (direct, indirect or virtual) of classinfo
# .........................................
iter(o[, sentinel]) 	# Return an iterator object
with open('mydata.txt') as fp:
    for line in iter(fp.readline, ''):
        process_line(line)
# .........................................
len(s)		# Return the length (the number of items) of an object
# .........................................
list([iterable]) 	# Return a list whose items are the same and in the same order as iterable‘s items
# .........................................
locals() 	# Update and return a dictionary representing the current local symbol table
# .........................................
long(x=0) 
long(x, base=10) 	# Convert a string or number to a long integer.
# .........................................
map(function, iterable, ...) 	# Apply function to every item of iterable and return a list of the results

def adder(a, b):
    return a + b

numbers1 = [2, 4, 6, 8, 1, 10, 8, 9]
numbers2 = [4, 6, 8, 1, 10, 8, 9, 1]
mapper = map(adder, numbers1, numbers2)   # Result: [6, 10, 14, 9, 11, 18, 17, 10] #
# .........................................
max(iterable[, key]) 
max(arg1, arg2, *args[, key]) 	# Return the largest item in an iterable or the largest of two or more arguments.
# .........................................
memoryview(obj) 	# Return a “memory view” object created from the given argument
# .........................................
min(iterable[, key]) 
min(arg1, arg2, *args[, key]) 	# Return the smallest item in an iterable or the smallest of two or more arguments.
# .........................................
next(iterator[, default]) 	# Retrieve the next item from the iterator by calling its next() method
# .........................................
object() 	# Return a new featureless object
# .........................................
oct(x) 	# Convert an integer number (of any size) to an octal string
# .........................................
open(name[, mode[, buffering]]) 	# Open a file, returning an object of the file type described in section File Objects. If the file cannot be opened, IOError is raised
# .........................................
ord(c) 	# Given a string of length one, return an integer representing the Unicode code point of the character when the argument is a unicode object
# .........................................
pow(x, y[, z]) 	# Return x to the power y 	# pow(x, y) is equivalent to using the power operator: x**y
# To disable the statement and use the print() function, use this future statement at the top of your module:
from __future__ import print_function
# .........................................
property([fget[, fset[, fdel[, doc]]]]) 	# Return a property attribute for new-style classes (classes that derive from object).
class C(object):
    def __init__(self):
        self._x = None

    def getx(self):
        return self._x
    def setx(self, value):
        self._x = value
    def delx(self):
        del self._x
    x = property(getx, setx, delx, "I'm the 'x' property.")

# If then c is an instance of C, c.x will invoke the getter, c.x = value will invoke the setter and del c.x the deleter.
class Parrot(object):
    def __init__(self):
        self._voltage = 100000

    @property
    def voltage(self):
        """Get the current voltage."""
        return self._voltage
# turns the voltage() method into a “getter” for a read-only attribute with the same name
class C(object):
    def __init__(self):
        self._x = None

    @property
    def x(self):
        """I'm the 'x' property."""
        return self._x

    @x.setter
    def x(self, value):
        self._x = value

    @x.deleter
    def x(self):
        del self._x

# .........................................
range(stop) 
range(start, stop[, step]) 	# This is a versatile function to create lists containing arithmetic progressions
range(10)
range(1, 11)
range(0, 30, 5)
range(0, 10, 3)
range(0, -10, -1)
range(0)
range(1, 0)
# .........................................
raw_input([prompt]) 	# If the prompt argument is present, it is written to standard output without a trailing newline
s = raw_input('--> ')
# --> 
# .........................................
reduce(function, iterable[, initializer]) 	# Apply function of two arguments cumulatively to the items of iterable, from left to right, so as to reduce the iterable to a single value
def reduce(function, iterable, initializer=None):
    it = iter(iterable)
    if initializer is None:
        try:
            initializer = next(it)
        except StopIteration:
            raise TypeError('reduce() of empty sequence with no initial value')
    accum_value = initializer
    for x in it:
        accum_value = function(accum_value, x)
    return accum_value

# .........................................
reload(module) 	# Reload a previously imported module
# .........................................
repr(object) 	# Return a string containing a printable representation of an object. This is the same value yielded by conversions
# A class can control what this function returns for its instances by defining a __repr__() method.
# .........................................
reversed(seq) 	# Return a reverse iterator.
# .........................................
round(number[, ndigits]) 	# Return the floating point value number rounded to ndigits digits after the decimal point
# .........................................
set([iterable]) 	# Return a new set object, optionally with elements taken from iterable
# .........................................
setattr(object, name, value) 	# This is the counterpart of getattr(). The arguments are an object, a string and an arbitrary value
# For example, setattr(x, 'foobar', 123) is equivalent to x.foobar = 123.
# .........................................
slice(stop) 
slice(start, stop[, step]) 	# Return a slice object representing the set of indices specified by range(start, stop, step)
# .........................................
sorted(iterable[, cmp[, key[, reverse]]]) 	# Return a new sorted list from the items in iterable.
cmp=lambda x,y: cmp(x.lower(), y.lower())
# .........................................
staticmethod(function) 	# Return a static method for function.
class C(object):
    @staticmethod
    def f(arg1, arg2, ...):
        ...
# It can be called either on the class (such as C.f()) or on an instance (such as C().f()). 
# .........................................
str(object='') 	# Return a string containing a nicely printable representation of an object.
# .........................................
sum(iterable[, start]) 	# Sums start and the items of an iterable from left to right and returns the total
# .........................................
super(type[, object-or-type]) 	# Return a proxy object that delegates method calls to a parent or sibling class of type
# Note: super() only works for new-style classes.
class C(B):
    def method(self, arg):
        super(C, self).method(arg)

# .........................................
tuple([iterable]) 	# Return a tuple whose items are the same and in the same order as iterable‘s items
# .........................................
type(object) 	# With one argument, return the type of an object. The return value is a type object
type(name, bases, dict) 	# With three arguments, return a new type object 	# This is essentially a dynamic form of the class statement.
class X(object):
	a = 1

X = type('X', (object,), dict(a=1))

# .........................................
unichr(i) 	# Return the Unicode string of one character whose Unicode code is the integer i
# .........................................
unicode(object='') 
unicode(object[, encoding[, errors]]) 	# Return the Unicode string version of object
# .........................................
vars([object]) 	# Return the __dict__ attribute for a module, class, instance, or any other object with a __dict__ attribute.
# Without an argument, vars() acts like locals(). 
# .........................................
xrange(stop) 
xrange(start, stop[, step]) 	# This function is very similar to range(), but returns an xrange object instead of a list
# .........................................
zip([iterable, ...]) 	# This function returns a list of tuples, where the i-th tuple contains the i-th element from each of the argument sequences or iterables
# zip() is similar to map() with an initial argument of None
x = [1, 2, 3]
y = [4, 5, 6]
zipped = zip(x, y)
zipped # [(1, 4), (2, 5), (3, 6)]
x2, y2 = zip(*zipped)
x == list(x2) and y == list(y2) # True
# .........................................
__import__(name[, globals[, locals[, fromlist[, level]]]]) 
# Note: This is an advanced function that is not needed in everyday Python programming
# This function is invoked by the import statement

# .........................................
# .........................................
# .........................................






#!/usr/bin/env python
# -*- coding: utf-8 -*-

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
L = [1, 2, 3, 4 ,5 ,1, 3, 6, 5]
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

print hello() ## returns <b><i>hello world</i></b>
# .......................................................
#!/usr/bin/env python

print "Hello World!"

x = 71
y = 'Dove'
z = None    # the variable has no value

print x, ':', type(x), '\n', y, ':', type(y)
print id(x), '\n', id(y)

print x == y    # Value Comparison
print x is y    # Identity Comparison

#print x + y     # Give error

var1 = 'hello'
print var1[0]



'''
Python makes a distinction between lists and tuples.
Lists are written as [1, 2, 3], are mutable, and cannot be used as the keys of dictionaries 
(dictionary keys must be immutable in Python).
Tuples are written as (1, 2, 3), are immutable and thus can be used as the keys of dictionaries,
 provided all elements of the tuple are immutable.
'''
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

g = 'Green'
t = 'Trees'
print g + ' ' + t

euro = unichr(8364)
print euro

print ord(euro)

euro = u"\N{euro sign}"			# \N{name} Unicode character name
print euro

phrase = "The red balloon"
phrase[:3]		# from 0 to 2
phrase[-3:] 	# from -3 to end
phrase[4:7] 	# 4, 5, 6

p = "pad"
p[1] = "o" # WRONG

p = "pad"
p = p[:1] + "o" + p[2:]
print p 	# 'pod'

p = "pad"
p = "o".join((p[:1], p[2:]))
print p 	# 'pod'
















'''
Python makes a distinction between lists and tuples.
Lists are written as [1, 2, 3], are mutable, and cannot be used as the keys of dictionaries 
(dictionary keys must be immutable in Python).
Tuples are written as (1, 2, 3), are immutable and thus can be used as the keys of dictionaries,
 provided all elements of the tuple are immutable.
'''
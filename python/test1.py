# import sys

# for i in sys.argv:
#   print i

# sys.exit()
# ............................
# def printDict(**op):
#   print op

# opts = {'name':3, 'objectSpace':1, 'absolute':6}  

# printDict(**opts)


# print sorted(opts)
# print sorted(opts.keys())
# print sorted(opts.values())
# ..........................................
# import maya.cmds as cmds

# def get_instances():
#   return cmds.ls(sl=True)

# test = ('aaa', 1.3)

# print test[1]
##############################################
# _name = "madoodia"
# @property
# def name():
#     def fget(): return _name
#     def fset(value): _name = value
#     return locals()

# # name = property(**name())

# print name
##############################################
t = ('a', 'b', 'a')
l = list(t)
s = list(set(l))
print t
print l
print s
##############################################
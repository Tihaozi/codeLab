# -------------------------------------------------- #

# In TDD we don't want to catch errors and pass them
# we want to find them and fix them in main code
# unit testin is a concept that can be implement in any ways

# -------------------------------------------------- #


import mainProgram

x = 1
try:
    assert mainProgram.some_method(x)
except:
    print "unit test failed"
else:
    print "No problem"

a = 7
b = 6
assert a < b, "There is a problem"
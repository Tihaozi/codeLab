############################## Simple statements ############################## 
# Simple statements are comprised within a single logical line. Several simple statements may occur on a single line separated by semicolons.

##########      Expression statements      ##########
# Expression statements are used (mostly interactively) to compute and write a value, or (usually) to call a procedure 
# The syntax for an expression statement is:
# expression_stmt ::=  expression_list

##########      Assignment statements      ##########
# Assignment statements are used to (re)bind names to values and to modify attributes or items of mutable objects:

# assignment_stmt ::=  (target_list "=")+ (expression_list | yield_expression)
# target_list     ::=  target ("," target)* [","]
# target          ::=  identifier
#                      | "(" target_list ")"
#                      | "[" target_list "]"
#                      | attributeref
#                      | subscription
#                      | slicing

##########      Augmented assignment statements      ##########
# Augmented assignment is the combination, in a single statement, of a binary operation and an assignment statement:

# augmented_assignment_stmt ::=  augtarget augop (expression_list | yield_expression)
# augtarget                 ::=  identifier | attributeref | subscription | slicing
# augop                     ::=  "+=" | "-=" | "*=" | "/=" | "//=" | "%=" | "**="
#                                | ">>=" | "<<=" | "&=" | "^=" | "|="

##########      The assert statement      ##########
# Assert statements are a convenient way to insert debugging assertions into a program:

# assert_stmt ::=  "assert" expression ["," expression]

##########      The pass statement      ##########
# pass_stmt ::=  "pass"
# pass is a null operation — when it is executed, nothing happens. It is useful as a placeholder when a statement is required syntactically, 
# but no code needs to be executed
def f(arg): pass    # a function that does nothing (yet)
class C: pass       # a class with no methods (yet)

##########      The del statement      ##########
# del_stmt ::=  "del" target_list
# Deletion of a name removes the binding of that name from the local or global namespace, 
# depending on whether the name occurs in a global statement in the same code block. 
# If the name is unbound, a NameError exception will be raised.

##########      The print statement      ##########
# print_stmt ::=  "print" ([expression ("," expression)* [","]]
#                 | ">>" expression [("," expression)+ [","]])
# print evaluates each expression in turn and writes the resulting object to standard output
# A '\n' character is written at the end, unless the print statement ends with a comma. 
# This is the only action if the statement contains just the keyword print.

##########      The return statement      ##########
# return_stmt ::=  "return" [expression_list]
# return may only occur syntactically nested in a function definition, not within a nested class definition.

##########      The yield statement     ##########
# yield_stmt ::=  yield_expression
# The yield statement is only used when defining a generator function, 
# and is only used in the body of the generator function. 
# Using a yield statement in a function definition is sufficient to cause that definition to create a generator function instead of a normal function.

# Generator functions:  (available since 2.3) are coded as normal def statements, but
# use yield statements to return results one at a time, suspending and resuming their
# state between each.

# Example: Defineing Generator Function
def gensquares(N):
	for i in xrange(N):
		yield i ** 2 # Resume here later

# Using:
for i in gensquares(5): 	# Resume the function
	print i, ':',			# Print last yielded value

x = gensquares(5)
next(x)

# Second Way:
def buildsquares(n):
	res = []
	for i in range(n): res.append(i ** 2)
		return res
for x in buildsquares(5): 
	print(x, end=' : ')

# But generators can be better in terms of both memory use and performance in larger programs.

# Exmaple 2: 
def gen():
	for i in range(10):
		X = yield i
		print(X)

G = gen()
next(G) # Must call next() first, to start generator
# 0
G.send(77) # Advance, and send value to yield expression
# 77
# 1
G.send(88)
# 88
# 2
next(G) # next() and X.__next__() send None
# None
# 3

##########      The raise statement      ##########
# raise_stmt ::=  "raise" [expression ["," expression ["," expression]]]
# If no expressions are present, raise re-raises the last exception that was active in the current scope. 
# If no exception is active in the current scope, a TypeError exception is raised indicating that this is an error


##########      The break statement      ##########
# break_stmt ::=  "break"
# break may only occur syntactically nested in a for or while loop, but not nested in a function or class definition within that loop.
# It terminates the nearest enclosing loop, skipping the optional else clause if the loop has one.


##########      The continue statement      ##########
# continue_stmt ::=  "continue"
# continue may only occur syntactically nested in a for or while loop, 
# but not nested in a function or class definition or finally clause within that loop. 
# It continues with the next cycle of the nearest enclosing loop.

##########      The import statement      ##########
# import_stmt     ::=  "import" module ["as" name] ( "," module ["as" name] )*
#                      | "from" relative_module "import" identifier ["as" name]
#                      ( "," identifier ["as" name] )*
#                      | "from" relative_module "import" "(" identifier ["as" name]
#                      ( "," identifier ["as" name] )* [","] ")"
#                      | "from" module "import" "*"
# module          ::=  (identifier ".")* identifier
# relative_module ::=  "."* module | "."+
# name            ::=  identifier

# Import statements are executed in two steps: 
# (1) find a module, and initialize it if necessary; 
# (2) define a name or names in the local namespace (of the scope where the import statement occurs). 

# Once the name of the module is known (unless otherwise specified, the term “module” will refer to both packages and modules), 
# searching for the module or package can begin. The first place checked is sys.modules, 
# the cache of all modules that have been imported previously. 
# If the module is found there then it is used in step (2) of import.

# If the module is not found in the cache, then sys.meta_path is searched

# If none of the finders on sys.meta_path are able to find the module then some implicitly defined finders are queried. 

##########      Future statements      ##########
# A future statement is a directive to the compiler that a particular module should be compiled using syntax or semantics that will be available in a specified future release of Python. 
# The future statement is intended to ease migration to future versions of Python that introduce incompatible changes to the language. 
# It allows use of the new features on a per-module basis before the release in which the feature becomes standard.

# future_statement ::=  "from" "__future__" "import" feature ["as" name]
#                       ("," feature ["as" name])*
#                       | "from" "__future__" "import" "(" feature ["as" name]
#                       ("," feature ["as" name])* [","] ")"
# feature          ::=  identifier
# name             ::=  identifier

# A future statement must appear near the top of the module. The only lines that can appear before a future statement are:
# 	the module docstring (if any), 
# 	comments, 
# 	blank lines, and 
# 	other future statements. 

# For any given release, the compiler knows which feature names have been defined, 
# and raises a compile-time error if a future statement contains a feature not known to it.

##########      The global statement      ##########
# global_stmt ::=  "global" identifier ("," identifier)*
# The global statement is a declaration which holds for the entire current code block. 
# It means that the listed identifiers are to be interpreted as globals. 
# It would be impossible to assign to a global variable without global, although free variables may refer to globals without being declared global.


##########      The exec statement      ##########
# exec_stmt ::=  "exec" or_expr ["in" expression ["," expression]]
# This statement supports dynamic execution of Python code. 
# The first expression should evaluate to either a Unicode string, a Latin-1 encoded string, an open file object, a code object, or a tuple

########################	math	########################
import math

################# Number-theoretic and representation functions #################
math.ceil(x) 	# Return the ceiling of x as a float, the smallest integer value greater than or equal to x.
math.copysign(x, y) 	# Return x with the sign of y. On a platform that supports signed zeros, copysign(1.0, -0.0) returns -1.0.
math.fabs(x) 	# Return the absolute value of x.
math.factorial(x) 	# Return x factorial. Raises ValueError if x is not integral or is negative.
math.floor(x) 	# Return the floor of x as a float, the largest integer value less than or equal to x.
math.fmod(x, y) 	# Return fmod(x, y), as defined by the platform C library. Note that the Python expression x % y may not return the same result
math.frexp(x) 	# Return the mantissa and exponent of x as the pair (m, e). m is a float and e is an integer such that x == m * 2**e exactly	#
math.fsum(iterable) #  Return an accurate floating point sum of values in the iterable
math.isinf(x) 	# Check if the float x is positive or negative infinity.
math.isnan(x) 	# Check if the float x is a NaN (not a number). 
math.ldexp(x, i) 	# Return x * (2**i). This is essentially the inverse of function frexp().
math.modf(x) 	# Return the fractional and integer parts of x. Both results carry the sign of x and are floats.
math.trunc(x) 	# Return the Real value x truncated to an Integral (usually a long integer). Uses the __trunc__ method.

################# Power and logarithmic functions #################
math.exp(x) 	# Return e**x.
math.expm1(x) 	# Return e**x - 1.
math.log(x[, base]) 
# With one argument, return the natural logarithm of x (to base e).
# With two arguments, return the logarithm of x to the given base, calculated as log(x)/log(base).
math.log10(x) 	# Return the base-10 logarithm of x. This is usually more accurate than log(x, 10).
math.pow(x, y) 	# Return x raised to the power y
math.sqrt(x) 	# Return the square root of x.

################# Trigonometric functions #################
math.acos(x) 	# Return the arc cosine of x, in radians.
math.asin(x) 	# Return the arc sine of x, in radians.
math.atan(x) 	# Return the arc tangent of x, in radians.
math.atan2(y, x) 	# Return atan(y / x), in radians
math.cos(x) 	# Return the cosine of x radians.
math.hypot(x, y) 	# Return the Euclidean norm, sqrt(x*x + y*y). This is the length of the vector from the origin to point (x, y).
math.sin(x) 	# Return the sine of x radians.
math.tan(x) 	# Return the tangent of x radians.
math.degrees(x) 	# Converts angle x from radians to degrees.
math.radians(x) 	# Converts angle x from degrees to radians.

################# Hyperbolic functions #################
math.acosh(x) 	# Return the inverse hyperbolic cosine of x.
math.asinh(x) 	# Return the inverse hyperbolic sine of x.
math.atanh(x) 	# Return the inverse hyperbolic tangent of x.
math.cosh(x) 	# Return the hyperbolic cosine of x.
math.sinh(x) 	# Return the hyperbolic sine of x.
math.tanh(x) 	# Return the hyperbolic tangent of x.

################# Special functions #################
math.erf(x) 	# Return the error function at x.
math.erfc(x) 	# Return the complementary error function at x.
math.gamma(x) 	# Return the Gamma function at x.
math.lgamma(x) 	# Return the natural logarithm of the absolute value of the Gamma function at x.

################# Constants #################
math.pi 	# The mathematical constant π = 3.141592..., to available precision.
math.e 		# The mathematical constant e = 2.718281..., to available precision.




# Example

import math
import time

def calculate_fact(no):
    start = time.time()
    math.factorial(no)
    end = time.time()
    print 'Time: ', end - start
    
calculate_fact(1000)

# -------- Result (second) ----------- #

# calculate_fact(10)
# Time:  0.0
# calculate_fact(100)
# Time:  0.0
# calculate_fact(1000)
# Time:  0.0
# calculate_fact(10000)
# Time:  0.0379998683929
# calculate_fact(100000)
# Time:  4.27500009537
# calculate_fact(1000000)
# Time:  876.078000069         =      14.60130000115 min
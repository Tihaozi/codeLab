# Prime Palindrome Challenge
# Solution 03: Using Trial Division (SQRT method in prime finding)
# num = 100000        # 0.7 sec


if __name__ == "__main__":
    import math
    num = 1000
    primes = []

    # 1. Prime number
    def prime(num):
        for i in range(2, int(math.sqrt(num))+1):
            if num % i == 0:
                return False
        return True

    # 2. Palindromic Number
    def palindromic(primes):
        palindroms = []
        for p in primes:
            if str(p) == str(p)[::-1]:
                palindroms.append(p)
        return palindroms

    for i in range(2, num + 1):
        if prime(i):
            primes.append(i)

    print palindromic(primes)[-1]

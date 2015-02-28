# Prime Palindrome Challenge
# Solution 04: Using Sieve of Eratosthenes (Refinement 1 applied p ** 2 < n) (Refinement 2 applied odd numbers)
# num = 100000        # 65.7 sec


if __name__ == "__main__":
    import math
    num = 1000
    primes = []

    # 1. Prime number
    def prime(num, primes):
        numbers = []

        for i in range(3, num + 1, 2):      # create list of odd numbers
            numbers.append(i)

        # print numbers

        while numbers != []:
            # print numbers[0]
            if (numbers[0] ** 2) < num:
                primes.append(numbers[0])
                for x in range(numbers[0], num + 1, numbers[0]):
                    if x in numbers:
                        numbers.remove(x)
            else:
                primes += numbers
                numbers = []

        # print numbers
        # print primes

    # 2. Palindromic Number
    def palindromic(primes):
        palindroms = []
        for p in primes:
            if str(p) == str(p)[::-1]:
                palindroms.append(p)
        return palindroms

    prime(num, primes)

    # print primes
    print palindromic(primes)[-1]

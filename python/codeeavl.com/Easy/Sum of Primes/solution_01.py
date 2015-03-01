# Sum of Primes Challenge
# Solution 01: Using Trial Division for checking prime nimber


if __name__ == "__main__":
    import math
    num = 2
    primes = []

    # 1. Prime number
    def prime(num):
        for i in range(2, int(math.sqrt(num))+1):
            if num % i == 0:
                return False
        return True

    while len(primes) < 1000:
        if prime(num):
            primes.append(num)
        num += 1

    print sum(primes)

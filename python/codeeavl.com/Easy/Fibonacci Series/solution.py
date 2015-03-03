# Fibonacci Series Challenge

if __name__ == "__main__":
    import sys
    def fibonacci(n):
        if n == 0:
            return 0
        elif n == 1:
            return 1
        else:
            return fibonacci(n-1) + fibonacci(n-2)

        return n

    with open(sys.argv[1]) as f:
        for line_no, line in enumerate(f.readlines()):
            num = int(line)
            n = fibonacci(num)
            print n

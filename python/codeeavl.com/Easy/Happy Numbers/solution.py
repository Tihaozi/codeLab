# Happy Numbers Challenge


if __name__ == "__main__":
    import sys
    import math

    def happy(sep):
        res = 0
        for i in sep:
            res += math.pow(i, 2)
        return int(res)

    def count(n):
        sep = []
        while n / 10 != 0:
            sep.append(n % 10)
            n = n / 10
        sep.append(n)
        return sep

    with open(sys.argv[1]) as f:
        for line in f.readlines():
            c = 0
            base = int(line.strip())
            num = int(line.strip())
            while num != 1 and c < 10:
                sep = count(num)
                num = happy(sep)
                c += 1
            if num == 1:
                print 1
            else:
                print 0

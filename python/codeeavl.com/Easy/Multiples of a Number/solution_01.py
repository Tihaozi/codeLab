# Multiples of a Number Challenge


if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line_no, line in enumerate(f.readlines()):
            mul = 1
            result = 0
            num = line.split(",")
            x = int(num[0])
            y = int(num[1])
            while x > (mul * y):
                mul += 1
            result = y * mul
            print str(result).strip()

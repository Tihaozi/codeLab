# Sum of Digits Challenge

if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            result = 0
            num = list(str(line.strip()))
            for i in num:
                result += int(i)
            print result
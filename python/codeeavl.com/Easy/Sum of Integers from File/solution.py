# Sum of Integers from File Challenge

if __name__ == "__main__":
    import sys
    result = 0
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            num = int(line.strip())
            result += num
        print result
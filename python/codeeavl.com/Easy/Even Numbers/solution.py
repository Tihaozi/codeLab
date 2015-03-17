# Even Numbers Challenge


if __name__ == "__main__":
    import sys

    with open(sys.argv[1]) as f:
        for line in f.readlines():
            num = int(line.strip())
            if num % 2 == 0:
                print 1
            else:
                print 0

# Happy Numbers Challenge


if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            str1 = line.strip().split(',')[0]
            t = line.strip().split(',')[1]
            print str1.rfind(t)

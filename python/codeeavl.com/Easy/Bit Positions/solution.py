# Bit Positions Challenge

if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            num = line.split(",")
            n = int(num[0])
            p1 = int(num[1])
            p2 = int(num[2])
            binary = list(bin(n))[::-1][:-2]
            if binary[p1-1] == binary[p2-1]:
                print "true"
            else:
                print "false"

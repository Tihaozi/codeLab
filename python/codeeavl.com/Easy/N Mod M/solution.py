# N Mod M Challenge


if __name__ == "__main__":
    import sys

    with open(sys.argv[1]) as f:
        for line in f.readlines():
            num1 = int(line.strip().split(',')[0])
            num2 = int(line.strip().split(',')[1])
            c = 1
            if num2 != 0:
                if num1 >= num2:
                    while ((num2 * c) + num2) <= num1:
                        c += 1
                    print num1 - (num2 * c)
                else:
                    print num1
            else:
                print 0
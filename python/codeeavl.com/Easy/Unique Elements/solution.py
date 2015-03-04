# Unique Elements Challenge


if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            result = ""
            temp = []
            # num = sorted(set(line.strip().split(',')))
            num = list(line.strip().split(','))
            for i in num:
                if i not in temp:
                    temp.append(i)
            for i in temp:
                result += "%s," % i
            print result.strip(",")

# Set Intersection Challenge

# str.sort() is different than sorted(List)


if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            result = ""
            intersect = []
            lists = line.strip().split(";")
            for s1 in lists[0].split(","):
                for s2 in lists[1].split(","):
                    if s1 == s2:
                        intersect.append(s1)
            intersect = sorted([int(i) for i in intersect])
            for i in intersect:
                result += "%s," % str(i)
            print result.strip(",")

# Set Intersection Challenge

# str.sort() is different than sorted(List)


if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            result = ""
            sep1 = set(line.split(";")[0].split(","))
            sep2 = set(line.split(";")[1].split(","))
            intersect = sorted([int(i) for i in sep1.intersection(sep2)])  # a list of sorted integers
            for i in intersect:
                result += "%s," % str(i)
            print result.strip(",")

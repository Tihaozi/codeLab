# Reverse Words Challenge
# Solution 01: Using Trial Division for checking prime nimber


if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line in f.readlines():
            if line is not None:
                result = line.split(" ")
                for i in result[::-1]:
                    print i.strip(),
                print ""

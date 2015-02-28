# Fizz Buzz Challenge

if __name__ == "__main__":
    import sys
    with open(sys.argv[1]) as f:
        for line_no, line in enumerate(f.readlines()):
            result = ""
            num = line.split(" ")
            x = int(num[0])
            y = int(num[1])
            n = int(num[2])
            for i in range(1, n+1):
                if i % x == 0 and i % y == 0:
                    r = "FB "
                elif i % x == 0:
                    r = "F "
                elif i % y == 0:
                    r = "B "
                else:
                    r = (str(i) + " ")
                result += r
            print result.strip()
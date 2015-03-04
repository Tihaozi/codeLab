# File Size Challenge

if __name__ == "__main__":
    import sys, os
    path = sys.argv[1]
    print os.path.getsize(path)
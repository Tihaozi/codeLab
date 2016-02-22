# import os

# dir = r'E:\Madoodia\_GitHub\codeLab\nuke_sdk\python\learning_python_in_nuke'
# newdir = r'E:\Madoodia\_GitHub\codeLab\nuke_sdk\python\newDirectory'
# print os.path.isdir(dir)
# print os.path.isfile(dir)

# print os.path.dirname(dir)
# print os.path.basename(dir)

# print os.getcwd()

# try:
#     os.stat(newdir)
# except:
#     os.mkdir(newdir)

# try:
#     os.stat(newdir)
# except:
#     os.makedirs(newdir + '/testFolder1/testFolder2')

# os.rmdir(newdir)

# os.rename('fileName', 'newName')

# print os.listdir(dir)


# path = r'D:\CompoTool_project\nuke'
# print path.replace('\\', '/')

# -----------------------------------------------
# fibonacci
n1 = 1
n2 = 1
r = 0
c = 1
max = 10

def fibo(a, b):
    r = a + b
    c = c + 1
    if c != max:
        n1 = n2
        n2 = r
        print r,
        fibo(n1, n2)

fibo(n1, n2)

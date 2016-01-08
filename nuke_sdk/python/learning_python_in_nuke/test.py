import os

dir = r'E:\Madoodia\_GitHub\codeLab\nuke_sdk\python\learning_python_in_nuke'
newdir = r'E:\Madoodia\_GitHub\codeLab\nuke_sdk\python\newDirectory'
print os.path.isdir(dir)
print os.path.isfile(dir)

print os.path.dirname(dir)
print os.path.basename(dir)

print os.getcwd()

try:
    os.stat(newdir)
except:
    os.mkdir(newdir)

try:
    os.stat(newdir)
except:
    os.makedirs(newdir + '/testFolder1/testFolder2')

os.rmdir(newdir)

os.rename('fileName', 'newName')

print os.listdir(dir)

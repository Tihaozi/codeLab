
from PySide import QtCore, QtGui
import subprocess

if __name__ == '__main__':
    import sys

    app = QtGui.QApplication(sys.argv)
    bar = QtGui.QProgressBar()
    bar.setRange(0, 100)
    bar.setValue(0)
    bar.show()

    #SUB PROCESS Render.exe
    proc = subprocess.Popen(['C:/Program Files/Autodesk/Maya2014/bin/Render.exe',
                        'C:/Users/madoodia/Documents/maya/projects/default/scenes/testPyblish_01.ma'],
                        shell=True,
                        stdout=subprocess.PIPE)

    #UPDATE QProgressBar
    for i in range(2000):
        output = proc.stdout.readline()

        if "%" in output:
            #Split the entire string into a list where % occurs and get the first element (since that's where our numbers lie)
            outputSplit = output.split("%")[0]

            #Get the length - 1 (lists are 0 index based)
            lenSplit = len(outputSplit)-1

            #We know that the last 2 elements are the decimal and the point. Example: 71.6
            #So we get the 7 and the 1 and concatenate into a string
            value = outputSplit[lenSplit-3] + outputSplit[lenSplit-2]

            #cast to int and set QProgressBars value
            bar.setValue(int(value))

        #Since we are looping 2000 times (we don't know for how long the render might be outputting for,
        #we have to do an early break if rendering is done and that happens when the exe closes and we can't get
        #any more information from it
        if output is "":
            print "RENDER IS DONE!"
            break

    sys.exit(app.exec_())
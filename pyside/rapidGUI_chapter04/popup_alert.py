import sys
import time

from PySide import QtCore, QtGui


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)

    try:
        due = QtCore.QTime.currentTime()
        message = "Alert!"
        if len(sys.argv) < 2:
            raise ValueError
        hours, mins = sys.argv[1].split(":")
        due = QtCore.QTime(int(hours), int(mins))
        if not due.isValid():
            raise ValueError
        if len(sys.argv) > 2:
            message = " ".join(sys.argv[2:])
    except ValueError:
        # 24hr clock
        message = "Usage: popup_alert.py HH:MM [Optional message]"

    while QtCore.QTime.currentTime() < due:
        time.sleep(5)   # 2 SEC

    label = QtGui.QLabel("<font color=red size=72><b>" + message + "</b></font>")
    label.setWindowFlags(QtCore.Qt.SplashScreen)
    label.show()
    QtCore.QTimer.singleShot(10000, app.quit)   # 10 SEC
    sys.exit(app.exec_())

# app.exec_() start Event Loop
# Event Loop is like this:

# while True:
#     event = getNextEvent()
#     if event:
#         if event == Terminate:
#             break
#         processEvent(event)

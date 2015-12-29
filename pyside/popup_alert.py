import sys
import time

from PySide.QtCore import *
from PySide.QtGui import *


if __name__ == "__main__":
    app = QApplication(sys.argv)

    try:
        due = QTime.currentTime()
        message = "Alert!"
        if len(sys.argv) < 2:
            raise ValueError
        hours, mins = sys.argv[1].split(":")
        due = QTime(int(hours), int(mins))
        if not due.isValid():
            raise ValueError
        if len(sys.argv) > 2:
            message = " ".join(sys.argv[2:])
    except ValueError:
        # 24hr clock
        message = "Usage: popup_alert.py HH:MM [Optional message]"

    while QTime.currentTime() < due:
        time.sleep(5)   # 5 SEC

    label = QLabel("<font color=red size=72><b>" + message + "</b></font>")
    label.setWindowFlags(Qt.SplashScreen)
    label.show()
    QTimer.singleShot(10000, app.quit)   # 10 SEC
    sys.exit(app.exec_())

# app.exec_() start Event Loop
# Event Loop is like this:

# while True:
#     event = getNextEvent()
#     if event:
#         if event == Terminate:
#             break
#         processEvent(event)

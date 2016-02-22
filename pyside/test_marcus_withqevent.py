from __future__ import absolute_import

from PySide import QtCore, QtGui


class Item(QtGui.QPushButton):
    """"""

    def __init__(self, *args, **kwarge):
        super(Item, self).__init__(*args, **kwarge)
        self.pressed.connect(self.locations_event)

    def locations_event(self):

        # for PySide we cand send int directly to postEvent
        # so we should create an QEvent instance in this way

        # id = QtCore.QEvent.registerEventType()
        id = 1234
        typ = QtCore.QEvent.Type(id)
        event = QtCore.QEvent(typ)

        # This works, as it's posted in direct reference to
        # the receiver.
        QtGui.QApplication.postEvent(self.window(), event)

        # This uses our QApplication subclass, and doesn't work
        # for some reason.
        # QApplication.postEvent(self, event)

        # This uses another method, also doesn't work, but here we
        # can see that all events are being accepted by their immediate
        # parent (for some reason), and thus not propagated further.
        # manual_propagate(self, event)


class List(QtGui.QWidget):
    """"""

    def __init__(self, name, parent=None):
        super(List, self).__init__(parent)

        header = QtGui.QWidget()
        label = QtGui.QLabel(name)
        layout = QtGui.QHBoxLayout(header)
        layout.addWidget(label)

        body = QtGui.QWidget()
        layout = QtGui.QVBoxLayout(body)

        for x in range(10):
            name = "Item%i" % x
            item = Item(name)
            item.setObjectName(name)
            layout.addWidget(item)

        layout = QtGui.QVBoxLayout(self)
        layout.addWidget(header)
        layout.addWidget(body)


class Top(QtGui.QWidget):
    """"""

    def __init__(self, *args, **kwarge):
        super(Top, self).__init__(*args, **kwarge)

        self.setObjectName('Main')

        body = QtGui.QWidget()
        layout = QtGui.QHBoxLayout(body)

        for x in range(3):
            name = "List%i" % x
            lis = List(name)
            lis.setObjectName(name)
            layout.addWidget(lis)

        layout = QtGui.QVBoxLayout(self)
        layout.addWidget(body)

    def event(self, event):
        if event.type() >= QtCore.QEvent.User:
            self.locations_event('Success')
        return True

    def locations_event(self, path):
        print "%s was recieved from Top" % path


def manual_propagate(target, event):
    app = QtGui.QApplication.instance()
    while target:
        app.sendEvent(target, event)
        if not event.isAccepted():
            if hasattr(target, 'parent'):
                target = target.parent()
        else:
            target = None
    return event.isAccepted()


class QApplication(QtGui.QApplication):
    """"""

    def notify(self, receiver, event):
        if event.type() >= QtCore.QEvent.User:
            w = receiver
            while w:
                # Note that this calls `event` method directly thus bypassing
                # calling qApplications and receivers event filters
                res = w.event(event)
                if res and event.isAccepted():
                    return res
                w = w.parent
        return super(QApplication, self).notify(receiver, event)


if __name__ == "__main__":
    import sys
    # app = QtGui.QApplication(sys.argv)

    # Custom Application
    app = QApplication(sys.argv)

    win = Top()
    win.show()

    sys.exit(app.exec_())
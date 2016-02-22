import sys
import urllib
import contextlib

import pyblish.api
import pyblish.util

from PySide import QtGui, QtCore


class Window(QtGui.QWidget):

    def __init__(self, parent=None):
        super(Window, self).__init__(parent)
        self.setWindowTitle("Pyblish")
        self.setObjectName("Window")
        self.resize(400, 400)

        header = QtGui.QWidget()
        filler = QtGui.QWidget()

        # Load logo from URL
        pixmap = QtGui.QPixmap()
        pixmap.load("/icons/pyblish-white.png")
        # pixmap.loadFromData(urllib.urlopen(
        #     "https://gist.githubusercontent.com/mottosso"
        #     "/1443b177e15710ee36e4/raw/07e2db113ab0b438c"
        #     "d586f8b6dcf418491f2c528/pyblish-white.png").read())

        logo = QtGui.QLabel()
        logo.setPixmap(pixmap)

        layout = QtGui.QHBoxLayout(header)
        layout.addWidget(logo)
        layout.addWidget(filler)
        layout.setContentsMargins(0, 0, 0, 0)

        body = QtGui.QWidget()

        instance_list = QtGui.QListWidget()
        plugin_list = QtGui.QListWidget()

        layout = QtGui.QHBoxLayout(body)
        layout.addWidget(instance_list)
        layout.addWidget(plugin_list)
        layout.setContentsMargins(0, 0, 0, 0)

        footer = QtGui.QWidget()
        filler = QtGui.QWidget()
        publish = QtGui.QPushButton(">")
        refresh = QtGui.QPushButton("R")
        publish.setMaximumWidth(30)
        refresh.setMaximumWidth(30)

        layout = QtGui.QHBoxLayout(footer)
        layout.addWidget(filler)
        layout.addWidget(refresh)
        layout.addWidget(publish)
        layout.setContentsMargins(0, 0, 0, 0)

        # Main layout
        layout = QtGui.QVBoxLayout(self)
        layout.addWidget(header)
        layout.addWidget(body)
        layout.addWidget(footer)

        self.instance_list = instance_list
        self.plugin_list = plugin_list

        publish.pressed.connect(self.on_publish_pressed)
        refresh.pressed.connect(self.on_refresh_pressed)

    def refresh(self):
        self.plugin_list.clear()
        self.instance_list.clear()

        for plugin in pyblish.api.discover():
            item = QtGui.QListWidgetItem(plugin.__name__)
            self.plugin_list.addItem(item)

        for instance in pyblish.util.collect():
            item = QtGui.QListWidgetItem(instance.data["name"])
            self.instance_list.addItem(item)

    def on_publish_pressed(self):
        print("Publishing..")
        failed = False
        for result in pyblish.util.publish().data["results"]:
            if result["error"] is not None:
                failed = True

            for record in result["records"]:
                print(record.msg)

        if failed:
            self.signal_failure()
            print("Failed..")
        else:
            self.signal_success()
            print("Success!")

    def on_refresh_pressed(self):
        print("Refreshing")
        self.refresh()

    def signal_success(self):
        self.setStyleSheet("""
            #Window {
                background-color: green;
            }
        """)
        QtCore.QTimer.singleShot(300, self.reset_signal)

    def signal_failure(self):
        self.setStyleSheet("""
            #Window {
                background-color: red;
            }
        """)
        QtCore.QTimer.singleShot(300, self.reset_signal)

    def reset_signal(self):
        self.setStyleSheet("")


@contextlib.contextmanager
def application():
    """Enable running from within and outside host"""
    if not QtGui.qApp:
        app = QtGui.QApplication(sys.argv)
        yield
        app.exec_()
    else:
        yield


if __name__ == '__main__':
    class CollectFakeInstances(pyblish.api.Collector):

        def process(self, context):
            for name in ("Bob01", "Truck05", "Paperpen11"):
                instance = context.create_instance(name)
                instance.data["fake"] = True
                self.log.info("Adding %s" % name)

    class ValidateFakeInstances(pyblish.api.Validator):

        def process(self, instance):
            import random
            self.log.info("Asserting %s randomly" % instance)
            assert random.random() > 0.25

    pyblish.api.deregister_all_plugins()
    for plugin in (CollectFakeInstances, ValidateFakeInstances):
        pyblish.api.register_plugin(plugin)

    with application():
        window = Window()
        window.refresh()
        window.show()

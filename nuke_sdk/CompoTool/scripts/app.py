import os
from functools import partial

from PySide import QtGui

import nuke
import nukescripts

import colors


class CompoToolGUI(QtGui.QDialog):

    """The main Window of Pyblish GUI [is not Singleton]"""

    singleton = None
    _path = ""

    assets_dir = ""

    def __init__(self, parent=None):
        super(CompoToolGUI, self).__init__(parent)

        assets_dir = self._path + r'/assets'

        self.project_path_txt = QtGui.QLineEdit(r'D:\CompoTool_project\nuke')
        self.project_path_btn = QtGui.QPushButton('Set')
        self.apply_btn = QtGui.QPushButton('Setup')
        self.apply_btn.setMinimumSize(120, 20)
        self.plan_lst = QtGui.QListWidget()
        self.plan_lst.setSelectionMode(QtGui.QAbstractItemView.ExtendedSelection)

        # set_project_widg = QtGui.QWidget()
        setup_widg = QtGui.QWidget()
        # body_widg = QtGui.QWidget()

        layout = QtGui.QVBoxLayout(setup_widg)
        layout.addWidget(self.apply_btn)
        layout.addStretch()
        layout.setContentsMargins(0, 0, 0, 0)

        setup_gbox = QtGui.QGroupBox("Setup Plans")
        setup_lay = QtGui.QHBoxLayout(setup_gbox)
        setup_lay.addWidget(self.plan_lst)
        setup_lay.addWidget(setup_widg)
        setup_lay.setContentsMargins(5, 5, 5, 5)

        set_gbox = QtGui.QGroupBox("Set Project")
        set_lay = QtGui.QHBoxLayout(set_gbox)
        set_lay.addWidget(self.project_path_txt)
        set_lay.addWidget(self.project_path_btn)
        set_lay.setContentsMargins(5, 5, 5, 5)


        main_layout = QtGui.QVBoxLayout(self)
        main_layout.addWidget(set_gbox)
        main_layout.addWidget(setup_gbox)
        main_layout.setContentsMargins(3, 3, 3, 3)

        self.project_path_btn.clicked.connect(self.set_path)
        # self.apply_btn.clicked.connect(self.temp_setup)
        self.apply_btn.clicked.connect(self.create_assets)


        self.resize(370, 300)
        self.setWindowTitle("CompoTool")

    def temp_setup(self):
        plan_items = self.plan_lst.selectedItems()
        for plan in plan_items:
            self.plan_lst.removeItemWidget(plan)
            print plan.text()

    def closeEvent(self, event):
        self.close()

    def print_path(self):
        print self.project_path_txt.text()

    def set_path(self):
        self._path = self.project_path_txt.text()
        self._path = self._path.replace('\\', '/')
        # path = nuke.script_directory()
        # nuke.root().knob('project_directory').setValue('')
        nuke.root().knob('project_directory').setValue(self._path + '/comps')
        nuke.root().knob('fps').setValue(25)
        nuke.root().knob('format').setValue('HD_720')

        self.fill_plans_list()

    def fill_plans_list(self):
        self.assets_dir = self._path + r'/assets'

    # def refresh_plans_list(self):
        self.plan_lst.clear()
        try:
            plans = os.listdir(self.assets_dir)
            for plan in plans:
                item = QtGui.QListWidgetItem(plan)
                self.plan_lst.addItem(item)
            self.plan_lst.setCurrentRow(0)
        except:
            print "Set a correct path"



    def create_assets(self):
        # plan_dir = self.assets_dir + r'/S03_P17'
        # plans = os.listdir(self.assets_dir)
        plan_items = self.plan_lst.selectedItems()
        for plan in plan_items:
            _frames = 0
            layers = ""
            names = ""
            persons = ""
            aovs = ""
            # print plan
            plan_dir = self.assets_dir + r'/' + plan.text()
            layers = os.listdir(plan_dir)

            for layer in layers:
                read_nodes_list = []
                bd_color = 0xffffff11
                new_nodes = []
                backdrop_nodes = []
                # print "\t" + layer
                name_dir = plan_dir + r'/' + layer
                names = os.listdir(name_dir)

                if layer == 'Characters' or layer == 'Environment' or layer == 'Props':
                    if layer == 'Characters':
                        for name in names:
                            # print "\t\t" + name
                            persons_dir = name_dir + r'/' + name
                            persons = os.listdir(persons_dir)

                            for person in persons:
                                # print "\t\t\t" + person
                                aovs_dir = persons_dir + r'/' + person
                                aovs = os.listdir(aovs_dir)
                                if _frames == 0:
                                    _frames = len(aovs)

                                # import files as read file
                                file_path = aovs_dir + r'/' + \
                                    aovs[0].replace('0000', '####')
                                readed_file = nuke.createNode('Read')
                                readed_file.knob('file').setValue(file_path)
                                readed_file.knob('origfirst').setValue(0)
                                readed_file.knob(
                                    'origlast').setValue(_frames - 1)
                                readed_file.knob('first').setValue(0)
                                readed_file.knob('last').setValue(_frames - 1)
                                readed_file.knob('format').setValue('HD_720')
                                file_name = layer + '_' + name + '_' + person
                                readed_file.knob('name').setValue(file_name)
                                read_nodes_list.append(
                                    readed_file.knob('name').getValue())
                                bd_color = colors.colors_dict[name.lower()]
                    else:
                        for name in names:
                            # print "\t\t" + name
                            aovs_dir = name_dir + r'/' + name
                            aovs = os.listdir(aovs_dir)

                            if _frames == 0:
                                _frames = len(aovs)

                            # import files as read file
                            file_path = aovs_dir + r'/' + \
                                aovs[0].replace('0000', '####')
                            readed_file = nuke.createNode('Read')
                            readed_file.knob('file').setValue(file_path)
                            readed_file.knob('origfirst').setValue(0)
                            readed_file.knob('origlast').setValue(_frames - 1)
                            readed_file.knob('first').setValue(0)
                            readed_file.knob('last').setValue(_frames - 1)
                            readed_file.knob('format').setValue('HD_720')
                            file_name = layer + '_' + name
                            readed_file.knob('name').setValue(file_name)
                            read_nodes_list.append(
                                readed_file.knob('name').getValue())
                            bd_color = colors.colors_dict[layer.lower()]
                else:
                    aovs = os.listdir(name_dir)

                    if _frames == 0:
                        _frames = len(aovs)

                    # import files as read file
                    file_path = name_dir + r'/' + \
                        aovs[0].replace('0000', '####')
                    readed_file = nuke.createNode('Read')
                    readed_file.knob('file').setValue(file_path)
                    readed_file.knob('origfirst').setValue(0)
                    readed_file.knob('origlast').setValue(_frames - 1)
                    readed_file.knob('first').setValue(0)
                    readed_file.knob('last').setValue(_frames - 1)
                    readed_file.knob('format').setValue('HD_720')
                    file_name = layer
                    readed_file.knob('name').setValue(file_name)
                    read_nodes_list.append(readed_file.knob('name').getValue())
                    bd_color = colors.colors_dict[layer.lower()]

                # create merge nodes and connect them
                for node in read_nodes_list:
                    backdrop_nodes.append(node)
                    if node.find('beauty') != -1:
                        continue
                    else:
                        new_nodes.append(node)

                if len(new_nodes) > 1:
                    for i in range(1, len(new_nodes)):
                        m = nuke.createNode('Merge2')
                        m.knob('name').setValue('MERGE_' + layer + '_' + str(i))
                        m.knob('operation').setValue('plus')
                        backdrop_nodes.append(m.knob('name').getValue())

                    for i in range(len(new_nodes)):
                        if i == 0:
                            n1 = nuke.toNode(new_nodes[i])
                            n2 = nuke.toNode(new_nodes[i + 1])
                            m = nuke.toNode('MERGE_' + layer + '_' + str(i + 1))
                            m.setInput(0, n1)
                            m.setInput(1, n2)
                        elif i >= 2:
                            n = nuke.toNode(new_nodes[i])
                            m = nuke.toNode('MERGE_' + layer + '_' + str(i))
                            m.setInput(0, n)

                # print '-' * 30
                # n = nuke.toNode("Props_direct_specular")
                # n.knob('selected').setValue(True)
                # nuke.selectConnectedNodes()
                # print backdrop_nodes
                for bn in backdrop_nodes:
                    n = nuke.toNode(bn)
                    n.knob('selected').setValue(True)
                    nuke.autoplace(n)
                bd = nukescripts.autoBackdrop()
                bd.knob('name').setValue('BD_' + layer)
                bd.knob('label').setValue('layer: ' + layer)
                bd.knob('note_font_size').setValue(13)
                # 0xRRGGBB00
                bd.knob('tile_color').setValue(bd_color)

            self.plan_lst.removeItemWidget(plan)
        '''
        plans
            layers
                characters
                    chatName
                        aov
                            files
                props
                    aov
                        files
                env
                    aov
                        files
                others
                    files
        '''

    def save_comps(self):
        comps_dir = self._path + r'/comps'


def getMainWindow():
    mainWindow = QtGui.QApplication.activeWindow()
    while True:
        lastWin = mainWindow.parent()
        if lastWin:
            mainWindow = lastWin
        else:
            break
    return mainWindow


def show():
    if CompoToolGUI.singleton is not None:
        CompoToolGUI.singleton.pos()
        CompoToolGUI.singleton.show()
    else:
        win = CompoToolGUI(parent=getMainWindow())
        CompoToolGUI.singleton = win
        win.show()


def aboutUs():
    print "(C) 2016 madoodia.com"

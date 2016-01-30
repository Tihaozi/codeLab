# madoodia@gmail.com

# This tool created for using in composite, for Hossein Bayat

import os
import nuke

# add our paths to the plugins path of nuke
current_dir = os.path.dirname(os.path.abspath(__file__))

icons_path = current_dir + r"\icons"
nuke.pluginAddPath(icons_path)

gizmos_path = current_dir + r"\gizmos"
nuke.pluginAddPath(gizmos_path)

scripts_path = current_dir + r"\scripts"
nuke.pluginAddPath(scripts_path)

import app

# adding HB menu
nuke.menu('Nuke').addCommand('--HB--/CompoTool', 'app.show()', 'ctrl+alt+n', icon='target_d.png')
nuke.menu('Nuke').addCommand('--HB--/About', 'app.aboutUs()', 'ctrl+alt+m')


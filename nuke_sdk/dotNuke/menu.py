# madoodia@gmail.com

###### This is where you put your graphic user interface (GUI) customisati


# import Python scripts and/or Python Modules - i.e.:    import myPythonScript
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


# from python import madoodia_Toolset
import outside_scripts



# add format resolutions presets - i.e.:    nuke.addFormat('1920 797 0 0 1920 797 1.0 FullHD_Widescreen')
nuke.addFormat('1920 797 0 0 1920 797 1.0 FullHD_Widescreen')
nuke.addFormat('1920 1080 0 0 1920 1080 1.0 FullHD')

# add LUT to the Root - i.e.:
# nuke.root().knob('luts').addCurve('nameOfTheLUT', 'formula')    # sLOG
# formula example: '{pow(10.0, ((t - 0.616596 - 0.03) /0.432699)) - 0.037584}'
nuke.root().knob('luts').addCurve('pLuts', '{pow(10.0, ((t - 0.616596 - 0.03) /0.432699)) - 0.037584}')
nuke.root().knob('luts').addCurve('sineLuts', '{sin(t * 2) * 0.5 + 0}')
nuke.root().knob('luts').editCurve('sineLuts', '{sin(t * 2) * 2 + 0}')


# customise menu items from Nodes toolbar - i.e. Shuffle hotkey 'J':    nuke.menu('Nodes').addCommand('Channel/Shuffle', 'nuke.createNode("Shuffle")', 'j', icon='Shuffle.png')
# set hotkey for an existing menu item - i.e. Shuffle hotkey 'J':
# nuke.menu('Nodes').findItem('Channel').findItem('Shuffle').setShortcut('j')

# nuke.menu('Nodes').findItem('Channel/Shuffle').setShortcut('ctrl+shift+alt+j')
# nuke.menu('Nodes').findItem('Channel/Shuffle').setIcon('shuffle_d.png')
nuke.menu('Nodes').addCommand('Channel/Shuffle', 'nuke.createNode("Shuffle")', 'ctrl+shift+alt+j', icon='shuffle_d.png')


nuke.menu('Nodes').addCommand('Channel/Voice', 'print "This is A Voice!"', 'ctrl+shift+alt+v', icon='voice_d.png')
# nuke.menu('Nodes').findItem('Channel/Voice').setIcon('voice_d.png')

# customise node default value - i.e.:
# nuke.knobDefault('myNode.myKnob', 'myDefaultValue' )
nuke.knobDefault('Blur.size', '100' )


# add menu item to existing Nuke menu - i.e.:    nodeMenu = nuke.menu('Nuke').findItem('Edit/Node').addCommand('myMenuElement',
											  # 'myPythonScript.myFunction()', 'myHotkey')    
											  # Modifiers: Shift= shift+, Alt/Option = alt+, Control/Command = ctrl+
nuke.menu('Nuke').findItem('Edit/Node').addCommand('myMenuElement', 'print "This is a command from Main Menu"', 'ctrl+alt+m', icon='target_d.png')
nuke.menu('Nuke').addCommand('madoodia/Print Me', 'print "This is a command from Main Menu"', 'ctrl+alt+n', icon='target_d.png')
nuke.menu('Nuke').addCommand('madoodia/Print From Outside', 'outside_scripts.print_words()')

# Create a custom menu - i.e.:
# you need a gizmo to be placed in your '.nuke' folder structure
# toolbar = nuke.menu('Nodes')
# myMenu = toolbar.addMenu('myMenuElement', icon='myMenuIcon.png')
# myMenu.addCommand('myElement', 'nuke.createNode("myGizmo")',
# icon='myGizmoIcon.png', index=0) #the index argument (optional)
# indicates the position of the item within the menu

# Add new toolbar button with submenu
toolbar = nuke.menu('Nodes')
my_menu = toolbar.addMenu('madoodia', icon='target_d.png')

# EdgeMatte is a gizmo command in gizmos folder that appended to path
command = my_menu.addCommand('Edge Matte', 'nuke.createNode("EdgeMatte")', icon='world_d.png')
command = my_menu.addCommand('Test Giz', 'nuke.createNode("TestGiz")', icon='target_d.png')



# ------------------------------------------------------------- #
import renders
nuke.knobDefault('Write.afterRender', 'renders.finish()')



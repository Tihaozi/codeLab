# madoodia@gmail.com

# Learning python scripting in nuke
# ===================================================
import nuke
import os
print "Hello Nuke!"
# -----------------------------------
# Session 01
# Session 02
# Session 03

print nuke.selectedNode()
print nuke.selectedNode().knob('name')
print nuke.selectedNode().knob('name').value()
print nuke.selectedNode().knob('name').setValue('madoodia')

print nuke.selectedNode().knob('label').setValue('[value size]')

node1 = nuke.selectedNode()
knob1 = node1.knob('name')
value1 = knob1.value()
print value1
print nuke.selectedNode().knob('name').setValue('madoodia')

print nuke.toNode('Blur1').knob('fringe').value()

nodes = nuke.selectedNodes()
for i, each in enumerate(nodes):
    each.knob('size').setValue(i * 2)

all = nuke.allNodes()
for i, n in enumerate(all):
    if n.knob('size'):
        n.knob('name').setValue('blurrry_' + str(i))
    else:
        n.knob('name').setValue('grade_' + str(i))

all = nuke.allNodes()
for i in all:
    try:
        print i.knob('size').value()
    except:
        pass

# can write this code in a custom knob on a node
nuke.thisNode().knob('name').value()

# -----------------------------------
# Session 04
nuke.selectedNode().knob('size').setValue(12)
nuke.selectedNode().knob('size').getValue()

master = nuke.toNode('Blur1').knob('size').value()
nuke.toNode('Blur2').knob('size').setValue(master)

nuke.toNode('Blur4').knob('size').setExpression('Blur3.size')


nuke.toNode('Blur4').knob('label').value()

# [value Blur1.size]
# [knob Blur3.size]
# size: [knob Blur3.size]

nodes = nuke.selectedNodes()
for node in nodes:
    print node.knob('name').value()

nodes = nuke.selectedNodes('Merge2')
for node in nodes:
    print node.knob('name').value()


nuke.createNode('Blur')
nuke.createNode('Blur').knob('size').setValue(12)
  
n = nuke.createNode('Blur')
n.knob('size').setValue(120)
n.knob('label').setValue('My Label')

# deleting a node
n = nuke.selectedNode()
nuke.delete(n)

nuke.delete(nuke.toNode('Blur1'))

nukescripts.node_delete()  	# delete selected node


# this line will create a complete group
# with inout and output
nuke.collapseToGroup()

# this line create an empty group
group = nuke.createNode('Group')
# this line will create an input
nuke.createNode('Input')


# create a full group
group = nuke.createNode('Group')
group.begin()
nuke.createNode('Input')
nuke.createNode('Output')
group.end()

group = nuke.createNode('Group')
group.begin()
nuke.createNode('Input').knob('name').setValue('Hello')
nuke.createNode('Blur')
nuke.createNode('Grade')
nuke.createNode('Merge2')
nuke.createNode('Output')
group.end()

# connect nodes
b1 = nuke.toNode('Blur1')
b2 = nuke.toNode('Blur2')

b2.setInput(0, b1)


b1 = nuke.createNode('Blur')
g1 = nuke.createNode('Grade')
m1 = nuke.createNode('Merge2')

# first disconnect then connect
g1.setInput(0, None)
m1.setInput(1, None)
m1.setInput(1, b1)
m1.setInput(0, g1)



# -----------------------------------
# Session 05

# working on menu.py at .nuke folder to customize Nuke preferences

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


# customizing root.format (related to Project Settings)
nuke.root().knob('format').setValue('FullHD')

# modify luts from root
nuke.root().knob('luts').addCurve('pLuts', '{pow(10.0, ((t - 0.616596 - 0.03) /0.432699)) - 0.037584}')
# sine: sin(frequency * frequencyMultiplier) * amplitude + offset
nuke.root().knob('luts').addCurve('sineLuts', '{sin(t * 1) * 1 + 0}')
nuke.root().knob('luts').addCurve('sineLuts', '{sin(t * 2) * 5 + 0}')
nuke.root().knob('luts').editCurve('sineLuts', '{sin(t * 2) * 0.5 + 0}')
nuke.root().knob('luts').editCurve('sineLuts', '{sin(t * 0.5) * 2 + 0}')

# work with menus:
# side menu (Toolbars) ('Nodes')
# m = nuke.menu('Nodes')
# fi = m.findItem('menu/elementName')
# fi.addCommand('name', 'function', 'hotkey', icon='icons/fileName.png', index=positioNumber)
# in menu.py:
nuke.menu('Nodes').findItem('Channel/Shuffle').setShortcut('ctrl+shift+alt+j')

nuke.menu('Nodes').addCommand('Channel/Shuffle', 'nuke.createNode("Shuffle")', 'ctrl+shift+alt+j', icon='shuffle_d.png')
# nuke.menu('Nodes').findItem('Channel').findItem('Shuffle').setIcon(shuffleIcon_file)

# voiceIcon_file = current_dir + r"\icons\voice_d.png"
nuke.menu('Nodes').addCommand('Channel/Voice', 'print "This is A Voice!"', 'ctrl+shift+alt+v', icon='voice_d.png')
# nuke.menu('Nodes').findItem('Channel/Voice').setIcon(voiceIcon_file)


# for finding class related to a command
# should run that command in nuke like this:
# nuke.menu('Nodes').findItem('Channel/Shuffle')
# Result: <MenuItem object at 0x000000005162DB28>
# then it give you class of the object
# then you can find it in python sdk of nuke and access to its methods

# work with menus:
# main menu ('Nuke')

nuke.menu('Nuke').findItem('Edit/Node').addCommand('myMenuElement', 'print "This is a command from Main Menu"', 'ctrl+alt+m')
nuke.menu('Nuke').addCommand('madoodia/Print Me', 'print "This is a command from Main Menu"', 'ctrl+alt+n')
nuke.menu('Nuke').addCommand('madoodia/Print From Outside', 'outside_scripts.print_words()')

# Add new toolbar button with submenu
toolbar = nuke.menu('Nodes')
my_menu = toolbar.addMenu('madoodia')
madoodiaIcon_file = current_dir + r"\icons\target_l.png"
my_menu.setIcon(madoodiaIcon_file)


command = my_menu.addCommand('EdgeMatte', 'nuke.createNode("EdgeMatte")', icon='world_d.png')


# -----------------------------------
# -----------------------------------
# -----------------------------------
# -----------------------------------

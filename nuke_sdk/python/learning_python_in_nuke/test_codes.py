# Learning python scripting in nuke
# Session 01
# Session 02
# Session 03

import nuke
# ===================================================
print "Hello Nuke!"
# -----------------------------------
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

# Learning python scripting in nuke
# ===================================================
import nuke

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
# -----------------------------------
# -----------------------------------
# -----------------------------------
# -----------------------------------

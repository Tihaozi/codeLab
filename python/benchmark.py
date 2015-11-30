# based on justin israel tutorials about comparing maya cmds, maya API and PyMel
import sys
import time
import random

import maya.cmds as cmds
import pymel.core as pm
import maya.OpenMaya as OpenMaya

HELIX_OPTS = dict(ch=True, o=True, c=20, h=30, w=4, r=3, sa=20, sco=50)

RAND = random.Random(0)
LOW = -4
HIGH = 4

# HELIX_OPTS['sa'] = 2


def testPyCmds():
    start = time.time()

    helix = cmds.polyHelix(**HELIX_OPTS)
    pHelix = helix[0]

    size = cmds.polyEvaluate(v=True)
    for i in xrange(size):
        x = RAND.uniform(LOW, HIGH)
        attrib = "%s.vtx[%s]" % (pHelix, i)
        cmds.move(x, attrib, x=True)
        # print i

    cmds.delete(pHelix)

    end = time.time()
    return end - start


def testPyApi():
    start = time.time()

    helix = cmds.polyHelix(**HELIX_OPTS)
    pHelix = helix[0]

    sel = OpenMaya.MSelectionList()
    node = OpenMaya.MObject()

    sel.add(pHelix)
    # C++ style calling method
    sel.getDependNode(0, node)  # this is equal to: node = sel.getDependNode(0)

    vector = OpenMaya.MVector()

    #C++ style
    iter = OpenMaya.MItMeshVertex(node)

    while not iter.isDone():
        vector.x = RAND.uniform(LOW, HIGH)
        iter.translateBy(vector)
        iter.next()

    OpenMaya.MGlobal.deleteNode(node)

    end = time.time()
    return end - start


def testPyMel():
    start = time.time()

    helix = pm.polyHelix(**HELIX_OPTS)
    pHelix = helix[0]

    for v in pHelix.vtx:
        vector = pm.dt.Vector(x=RAND.uniform(LOW, HIGH))
        v.translateBy(vector)

    pm.delete(pHelix)

    end = time.time()
    return end - start


def testAll():
    results = []

    sys.stdout.write("Testing testPyCmds()\n")
    sys.stdout.flush()
    r = testPyCmds()
    results.append((r, "PyCmds"))

    sys.stdout.write("Testing testPyMel()\n")
    sys.stdout.flush()
    r = testPyMel()
    results.append((r, "PyMel"))

    sys.stdout.write("Testing testPyApi()\n")
    sys.stdout.flush()
    r = testPyApi()
    results.append((r, "PyApi"))

    results.sort()
    fastest = results.pop(0)

    print "\nResults from fastest to slowest..."
    print "%s:\t%0.4f sec" % (fastest[1], fastest[0])

    for r in results:
        diff = r[0] / fastest[0]
        print "%s:\t%0.4f sec (%0.2fx slower than %s)" % (r[1], r[0], diff, fastest[1])

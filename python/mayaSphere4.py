import maya.cmds as cmds
from mayaGeom import MayaGeom


class MayaSphere(MayaGeom):

    def __init__(self, name='Sphere', **kwargs):
        MayaGeom.__init__(self)
        kwargs['name'] = name
        kwargs['object'] = True

        self._create(kwargs)

    def __del__(self):
        self.delete()

    def __str__(self):
        return self.name

    def _create(self, opts={}):
        parts = cmds.sphere(**opts)
        self.name = parts[0]

    def delete(self):
        if self.exists():
            cmds.delete(self.name)

    def exists(self):
        return cmds.objExists(self.name)

    def setTranslation(self, x=None, y=None, z=None):
        self._doTransform(cmds.move, x, y, z)

    def getRotation(self):
        return cmds.xform(self.name, query=True, rotation=True)

    def setRotation(self, x=None, y=None, z=None):
        self._doTransform(cmds.rotate, x, y, z)

    def getScale(self):
        return cmds.xform(self.name, query=True, scale=True)

    def setScale(self, x=None, y=None, z=None):
        self._doTransform(cmds.scale, x, y, z)

    def _doTransform(self, func, x, y, z):
        for name in ('x', 'y', 'z'):
            val = locals()[name]
            if val is not None:
                opts = {name: True, 'objectSpace': True, 'absolute': True}
                func(val, self.name, **opts)


class PolySphere(MayaSphere):
    def __init__(self, name="PolySphere", **kwargs):
        MayaSphere.__init__(self, name, **kwargs)
        # Automatically call _create method of PolySphere clss
        # Not _create mthod from MayaSphere class

    def _create(self, opts={}):
        parts = cmds.polySphere(**opts)
        self.name = parts[0]

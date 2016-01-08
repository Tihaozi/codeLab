# -------------------------------------------------- #
# Callbacks in BEFOR RENDERING part
# create a renders.py file
import nuke

def finish():
    nuke.message('your render has finished')

# now in menu.py this should be set 
# import renders
# nuke.knobDefault('Write.afterRender', 'renders.finish()')

# -------------------------------------------------- #
# ===============================================
# MODULE STUDY: platform
import platform

################################ Cross Platform ################################

platform.architecture()     # Returns a tuple (bits, linkage)

platform.machine()          # Returns the machine type, e.g. 'i386'

platform.node()             # Returns the computer’s network name 

platform.platform()         # Returns a single string identifying the underlying platform with as much useful information as possible.

platform.processor()        # Returns the (real) processor name, e.g. 'amdk6'.

platform.python_build()     # Returns a tuple (buildno, builddate) stating the Python build number and date as strings.

platform.python_compiler()  # Returns a string identifying the compiler used for compiling Python.

platform.python_branch()    # Returns a string identifying the Python implementation SCM branch.

platform.python_implementation()    # Returns a string identifying the Python implementation

platform.python_revision()  # Returns a string identifying the Python implementation SCM revision.

platform.python_version()   # Returns the Python version as string 'major.minor.patchlevel'

platform.python_version_tuple()     # Returns the Python version as tuple (major, minor, patchlevel) of strings.

platform.release()          # Returns the system’s release, e.g. '2.2.0' or 'NT'

platform.system()           # Returns the system/OS name, e.g. 'Linux', 'Windows', or 'Java'

platform.version()          # Returns the system’s release version

platform.uname()            # Fairly portable uname interface. 
                            # Returns a tuple of strings (system, node, release, version, machine, processor) identifying the underlying platform.

platform.win32_ver()        # Availability: windows






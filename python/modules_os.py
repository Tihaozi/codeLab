# ===============================================
# MODULE STUDY: os
import os
reload(os)

print '*----------------------------------------*'
path = 'C:/'    # nt
path = '/'      # linux
print os.stat(path)

print '*----------------------------------------*'
print os.error    # <type 'exceptions.OSError'>
print os.error()  # OSError()

print '*----------------------------------------*'
print os.name     # 'posix', 'nt', 'os2', 'ce', 'java', 'riscos' 
# you can see platform module too and sys.platform

################################ Process Parameters ################################
print '*----------------------------------------*'
print os.environ  # A mapping object representing the string environment
print sorted(os.environ)
print os.environ['HOMEPATH']
print os.environ['PATH']
print os.environ['WINDIR']
print os.environ['USER']
print os.environ['NUMBER_OF_PROCESSORS']
print os.environ['MAYA_LOCATION']
print os.environ['PROCESSOR_ARCHITECTURE']
print os.environ['HOME']
print os.environ['USERNAME']
print os.environ['PYTHONPATH']
print os.environ['HOMEDRIVE']
print os.environ['MAYA_PLUG_IN_PATH']
print os.environ['OS']

for e in os.environ.keys():
    print e, ":", os.environ[e]
# we can access too many information of OS with os.environ

print '*----------------------------------------*'
print os.getcwd()   # E:\Madoodia\_Python\_learning_python
new_path = 'D:/'
os.chdir(new_path)
print os.getcwd()   # D:/

print os.getpid()           # Return the current process id.
print os.getenv('USERNAME')     # Return the value of the environment variable varname if it exists
print os.getenv('NOT_EXISTS')
os.putenv(varname, value)       # Set the environment variable named varname to the string value
os.strerror(code)               # Return the error message corresponding to the error code in code

os.umask(mask)                  # Set the current numeric umask and return the previous umask.
os.uname()      # Availability: Unix
os.unsetenv(varname)            # Unset (delete) the environment variable named varname

################################ File Object Creation ################################
os.fdopen(fd[, mode[, bufsize]]) 
os.popen(command[, mode[, bufsize]])    # Deprecated since version 2.6: This function is obsolete. Use the subprocess module
os.tmpfile()                            # Deprecated since version 2.6: All of the popen*() functions are obsolete. Use the subprocess module
os.popen2(cmd[, mode[, bufsize]])       # Deprecated since version 2.6: This function is obsolete. Use the subprocess module
os.popen3(cmd[, mode[, bufsize]])       # Deprecated since version 2.6: This function is obsolete. Use the subprocess module
os.popen4(cmd[, mode[, bufsize]])       # Deprecated since version 2.6: This function is obsolete. Use the subprocess module

################################ File Descriptor Operations ################################
os.close(fd)        # Close file descriptor fd.
os.closerange(fd_low, fd_high)      # Close all file descriptors from fd_low (inclusive) to fd_high (exclusive), ignoring errors
os.dup(fd)          # Return a duplicate of file descriptor fd.
os.dup2(fd, fd2)    # Duplicate file descriptor fd to fd2
os.fstat(fd)        # Return status for file descriptor fd, like stat().
os.fsync(fd)        # Force write of file with filedescriptor fd to disk
os.isatty(fd)       # Return True if the file descriptor fd is open and connected to a tty(-like) device, else False.
os.lseek(fd, pos, how)  # Set the current position of file descriptor fd to position pos, modified by how: SEEK_SET or 0
os.open(file, flags[, mode])    # Open the file file and set various flags according to flags
os.pipe()           # Create a pipe. Return a pair of file descriptors (r, w)
os.read(fd, n)      # Read at most n bytes from file descriptor fd
os.write(fd, str)   # Write the string str to file descriptor fd

################################ Files and Directories ################################

os.access(path, mode)       # Use the real uid/gid to test for access to path
os.chdir(path)              # Change the current working directory to path.
os.getcwd()                 # Return a string representing the current working directory.
os.getcwdu()                # Return a Unicode object representing the current working directory.
os.chmod(path, mode)        # Change the mode of path to the numeric mode
os.listdir(path)            # Return a list containing the names of the entries in the directory given by path
os.lstat(path)              # Perform the equivalent of an lstat() system call on the given path
os.mkdir(path[, mode])      # Create a directory named path with numeric mode mode
os.makedirs(path[, mode])   # Recursive directory creation function.
                            # Like mkdir(), but makes all intermediate-level directories needed to contain the leaf directory
os.remove(path)             # Remove (delete) the file path. If path is a directory, OSError is raised; see rmdir() below to remove a directory
os.removedirs(path)         # Remove directories recursively. Works like rmdir() except that, if the leaf directory is successfully removed
os.rename(src, dst)         # Rename the file or directory src to dst. If dst is a directory, OSError will be raised
os.renames(old, new)        # Recursive directory or file renaming function
os.rmdir(path)              # Remove (delete) the directory path. Only works when the directory is empty, otherwise, OSError is raised
os.stat(path)               # Perform the equivalent of a stat() system call on the given path
os.utime(path, times)       # Set the access and modified times of the file specified by path

# Generate the file names in a directory tree by walking the tree either top-down or bottom-up
os.walk(top, topdown=True, onerror=None, followlinks=False) 

################################ Process Management ################################
os.abort()          # Generate a SIGABRT signal to the current process
os._exit(n)         # Exit the process with status n    # The standard way to exit is sys.exit(n)
os.startfile(path[, operation])     # Start a file with its associated application.

# The subprocess module provides more powerful facilities for spawning new processes and retrieving their results
os.system(command)         # Execute the command (a string) in a subshell

os.times()      # Return a 5-tuple of floating point numbers indicating accumulated (processor or other) times, in seconds

################################ Miscellaneous System Information ################################
os.curdir       # The constant string used by the operating system to refer to the current directory
os.pardir       # The constant string used by the operating system to refer to the parent directory
os.sep          # The character used by the operating system to separate pathname components
os.altsep       # An alternative character used by the operating system to separate pathname components
os.extsep       # The character which separates the base filename from the extension
os.pathsep      # The character conventionally used by the operating system to separate search path components 
os.defpath      # The default search path used by exec*p* and spawn*p* if the environment doesn’t have a 'PATH' key
os.linesep      # The string used to separate (or, rather, terminate) lines on the current platform.

################################ Miscellaneous Functions ################################
os.urandom(n)       # Return a string of n random bytes suitable for cryptographic use

# ******************************************   os.path   *********************************************** #
# This module implements some useful functions on pathnames.
# To read or write files see open(), and for accessing the filesystem see the os module.
path = 'C:/Python27/Lib/site-packages/sip.pyd'
os.path.abspath(path)   # Return a normalized absolutized version of the pathname path
os.path.basename(path)  # Return the base name of pathname path
os.path.commonprefix(list)  # Return the longest path prefix that is a prefix of all paths in list
os.path.dirname(path)   # Return the directory name of pathname path
os.path.exists(path)    # Return True if path refers to an existing path
os.path.lexists(path)   # Return True if path refers to an existing path
os.path.expanduser(path)    # On Unix and Windows, return the argument with an initial component of ~ or ~user replaced by that user‘s home directory.
os.path.expandvars(path)    # Return the argument with environment variables expanded.
os.path.getatime(path)      # Return the time of last access of path
os.path.getmtime(path)      # Return the time of last modification of path
os.path.getctime(path)      # Return the system’s ctime which, on some systems (like Unix) is the time of the last metadata change, and, on others (like Windows), is the creation time for path
os.path.getsize(path)       # Return the size, in bytes, of path
os.path.isabs(path)         # Return True if path is an absolute pathname
os.path.isfile(path)        # Return True if path is an existing regular file
os.path.isdir(path)         # Return True if path is an existing directory
os.path.islink(path)        # Return True if path refers to a directory entry that is a symbolic link
os.path.join(path1[, path2[, ...]])     # Join one or more path components intelligently
os.path.normcase(path)      # Normalize the case of a pathname
os.path.normpath(path)      # Normalize a pathname by collapsing redundant separators and up-level references
os.path.realpath(path)      # Return the canonical path of the specified filename
os.path.relpath(path[, start])      # Return a relative filepath to path either from the current directory or from an optional start directory.
os.path.samefile(path1, path2)      # Return True if both pathname arguments refer to the same file or directory
os.path.split(path)     # Split the pathname path into a pair, (head, tail) where tail is the last pathname component and head is everything leading up to that
os.path.splitdrive(path)    # Split the pathname path into a pair (drive, tail) where drive is either a drive specification or the empty string.
os.path.splitext(path)      # Split the pathname path into a pair (root, ext) such that root + ext == path
os.path.splitunc(path)      # Split the pathname path into a pair (unc, rest) so that unc is the UNC mount point (such as r'\\host\mount'), 
os.path.walk(path, visit, arg)      # Calls the function visit with arguments (arg, dirname, names) for each directory in the directory tree rooted at path

#==============================================================================
# object_ppties makefile
#
# (c) 2010 Next Limit Technologies
#
#===============================================================================


CC = g++

CFLAGS = -pipe -fPIC -O3 -D_LINUX -w -c

INCLUDE = -I../../include \
	-I../../include/private_sdk

object_ppties.so: object_ppties.o
	$(CC) -fPIC -shared -o $@ $<

object_ppties.o: ./src/object_ppties.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

install:
	cp -f object_ppties.so ../../../plugins/objects


clean:
	rm -f object_ppties.o object_ppties.so

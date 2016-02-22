#==============================================================================
# graviton makefile
#
# (c) 2010 Next Limit Technologies
#
#===============================================================================


CC = g++

CFLAGS = -pipe -fPIC -O3 -D_LINUX -w -c

INCLUDE = -I../../include \
	-I../../include/private_sdk

graviton.so: graviton.o
	$(CC) -fPIC -shared -o $@ $<

graviton.o: ./src/graviton.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

install:
	cp -f graviton.so ../../../plugins/daemons/

clean:
	rm -f graviton.o graviton.so

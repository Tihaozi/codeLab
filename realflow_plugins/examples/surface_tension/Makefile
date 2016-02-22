#==============================================================================
# surface_tension makefile
#
# (c) 2010 Next Limit Technologies
#
#===============================================================================


CC = g++

CFLAGS = -pipe -fPIC -O3 -D_LINUX  -w -c

INCLUDE = -I../../include \
	-I../../include/private_sdk

surface_tension.so: surface_tension.o
	$(CC) -fPIC -shared -o $@ $<

surface_tension.o: ./src/surface_tension.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

install:
	cp -f surface_tension.so ../../../plugins/particles

clean:
	rm -f surface_tension.o surface_tension.so

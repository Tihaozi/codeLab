#==============================================================================
# gerstner_wave makefile
#
# (c) 2010 Next Limit Technologies
#
#===============================================================================


CC = g++

CFLAGS = -pipe -fPIC -O1 -g -D_LINUX -w -c

INCLUDE = -I../../include \
	-I../../include/private_sdk

gerstner_wave.so: gerstner_wave.o
	$(CC) -fPIC -shared -o $@ $<

gerstner_wave.o: ./src/gerstner_wave.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

install:
	cp -f gerstner_wave.so ../../../plugins/waves

clean:
	rm -f gerstner_wave.o gerstner_wave.so

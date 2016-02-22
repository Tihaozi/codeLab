#==============================================================================
# cmd_create_geometry makefile
#
# (c) 2014 Next Limit Technologies
#
#===============================================================================


CC = g++

CFLAGS = -pipe -fPIC -O3 -D_LINUX -w -c

INCLUDE = -I../../include \
	-I../../include/private_sdk

cmd_show_msg_n_times.so: cmd_create_geometry.o
	$(CC) -fPIC -shared -o $@ $<

cmd_show_msg_n_times.o: ./src/cmd_create_geometry.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

install:
	cp -f cmd_create_geometry.so ../../../plugins/cmds

clean:
	rm -f cmd_create_geometry.o cmd_create_geometry.so

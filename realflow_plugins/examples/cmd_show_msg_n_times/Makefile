#==============================================================================
# cmd_show_msg_n_times makefile
#
# (c) 2010 Next Limit Technologies
#
#===============================================================================


CC = g++

CFLAGS = -pipe -fPIC -O3 -D_LINUX -w -c

INCLUDE = -I../../include \
	-I../../include/private_sdk

cmd_show_msg_n_times.so: cmd_show_msg_n_times.o
	$(CC) -fPIC -shared -o $@ $<

cmd_show_msg_n_times.o: ./src/cmd_msg_n_times.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

install:
	cp -f cmd_show_msg_n_times.so ../../../plugins/cmds

clean:
	rm -f cmd_show_msg_n_times.o cmd_show_msg_n_times.so

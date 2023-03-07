#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS	:= -Wall -Wextra -g  

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =

# define source directory
SRC		:= src

# define include directory
INCLUDE	:= include

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS)  -o syscpy.o src/syscpy.c

.PHONY: clean
clean:
	$(RM) *.o
#	cd src
#	//rm -r *.dSYM
#	cd ..
	$(CC) $(CFLAGS) -o sshell.o src/sshell.c
	@echo Cleanup complete!

run:
	chmod +x sshell.o
	./sshell.o
	@echo Executing 'run: all' complete!
CC = gcc
CFLAGS = -Wall # COmpiler flags

#List of source files
SRCS = SFJ.c RR.c

# list of execitables

EXECUTABLES = SJF RR

# Define targets 
all: $(EXECUTABLES)

# Rule to build each executable
$(EXECUTABLES): %: %.c
	$(CC) $(CFLAGS) $< -o $@

# Phony target to clean the executables
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
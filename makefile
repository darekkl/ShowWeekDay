# C++ compiler
CC = g++

# C++ compiler flags
CFLAGS = -Wall -g

# Source files
SRCS = main.cpp ShowWeekDay.cpp

# Executable file 
MAIN = ShowWeekDay

all: $(MAIN)
	@echo $(MAIN) has been compiled

$(MAIN): $(SRCS) 
	$(CC) $(CFLAGS) -o build/$(MAIN) $(SRCS)	


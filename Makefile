CC := gcc # base compiler

# sourcefiles
FOOTBALL_SOURCES := football.c football_main.c
TEMPERATURE_SOURCES := temperature.c temperature_main.c

# object files from sourcefiles
FOOTBALL_OBJECTS := $(FOOTBALL_SOURCES:.c=.o)
TEMPERATURE_OBJECTS := $(TEMPERATURE_SOURCES:.c=.o)

# outputs
EXECUTABLES := football.exe temperature.exe

# compile football.exe...
football.exe: $(FOOTBALL_OBJECTS)
	$(CC) -o $@ $^

# compile temperature.exe..
temperature.exe: $(TEMPERATURE_OBJECTS)
	$(CC) -o $@ $^

# create object files from .C and header files.
%.o: %.c %.h
	$(CC) -c $< -o $@

# clean object files and executables from project
clean:
	rm -f $(EXECUTABLES) $(FOOTBALL_OBJECTS) $(TEMPERATURE_OBJECTS)

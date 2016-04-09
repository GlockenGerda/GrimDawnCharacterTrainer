TARGETNAME=myapp

CC = g++

CFLAGS_DLL = -Wall -O0 -g -shared -Wl,--subsystem,windows -DDLL

# Leave symbols, turn off optimisation, and send output to console
debug: $(TARGETNAME).c
        $(CC) -o $(TARGETNAME)_dbg $(CFLAGS_DEBUG) $^ $(LIBS)

# No debug symbols, debug statements removed, subsystem windows means we won't pop a window
$(TARGETNAME): $(TARGETNAME).c
        $(CC) -o $@ $(CFLAGS) $^ $(LIBS)

$(TARGETNAME).dll: $(TARGETNAME).c
        $(CC) -o $@ $(CFLAGS_DLL) $^ $(LIBS)

release: $(TARGETNAME)
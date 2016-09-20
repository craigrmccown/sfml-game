# commands
CC = g++
RM = rm -rf
MKDIR = mkdir -p
CP = cp -r

# options
CFLAGS = -std=c++11
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# directories
SDIR = src
IDIR = include
ODIR = obj
BDIR = build
ADIR = assets

# build
_OBJS = game_object.o grass_tile.o main.o map.o map_tile.o game_state.o map_game_state.o event_bus.o player.o texture_manager.o
OBJS = $(_OBJS:%.o=$(ODIR)/%.o)
_ASSETS = tile_grass.png player.png
ASSETS = $(_ASSETS:%=$(BDIR)/$(ADIR)/%)
DEPS = $(OBJS:%.o=%.d)
TARGET = $(BDIR)/game

all: $(TARGET) $(ASSETS)

$(TARGET): $(OBJS)
	$(MKDIR) $(BDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

-include $(DEPS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(MKDIR) $(ODIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(BDIR)/$(ADIR)/%: $(ADIR)/%
	$(MKDIR) $(BDIR)/$(ADIR)
	$(CP) $(ADIR)/$* $(BDIR)/$(ADIR)/$*

.PHONY: clean

clean:
	$(RM) $(ODIR)
	$(RM) $(BDIR)

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
ODIR = obj
BDIR = build
ADIR = assets

# build
_OBJS = animation.o game_object.o grass_tile.o main.o map.o sprite_sheet.o water_tile.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))
_ASSETS = tile_grass.png tile_water.png
ASSETS = $(patsubst %,$(ADIR)/%,$(_ASSETS))
TARGET = $(BDIR)/game

all: $(ODIR) $(BDIR) $(BDIR)/$(ADIR)/% $(TARGET)

$(ODIR):
	$(MKDIR) $@

$(BDIR):
	$(MKDIR) $@

$(BDIR)/$(ADIR)/%: $(ASSETS)
	$(CP) $(ADIR) $(BDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $? -o $@ $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c $? -o $@

.PHONY: clean
clean:
	$(RM) $(ODIR)
	$(RM) $(BDIR)

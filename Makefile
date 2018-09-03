# Makefile for Library
CXXFLAGS = -w -std=c++11
LDFLAGS = -L/usr/local/lib -lXext -lm -Wl,-Bsymbolic-functions -lfltk_images -lfltk -lX11

all: gui

debug: CXXFLAGS += -g
debug: gui

rebuild: clean gui

gui: main.cpp robot_part.h robot_part.cpp part_holder.cpp part_holder.h gui.cpp gui.h
	$(CXX) $(CXXFLAGS) $(fltk-config --use-images --cxxflags) -o run_main main.cpp robot_part.cpp part_holder.cpp gui.cpp $(LDFLAGS)



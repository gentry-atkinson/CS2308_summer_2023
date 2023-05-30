# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++ 
CFLAGS = -Wall 
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Robot.o RoboList.o
    $(CC) $(CFLAGS) -o main main.o Robot.o Robolist.o
 
# The main.o target can be written more simply
 
main.o: main.cpp Robot.h RoboList.h
    $(CC) $(CFLAGS) -c main.cpp
 
Robot.o: Robot.h
 
RoboList.o: RoboList.h Robo.h

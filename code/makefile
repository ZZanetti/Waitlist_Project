# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o deque.o waitlist.o
	$(CXX) $(CXXFLAGS) -o main main.o deque.o waitlist.o

# The main.o target can be written more simply

main.o: main.cpp waitlist.h deque.h
	$(CXX) $(CXXFLAGS) -c main.cpp

deque.o: deque.h

waitlist.o: waitlist.h deque.h


#use rm main *.o 
#removes old exe files
#make main to see if up to date

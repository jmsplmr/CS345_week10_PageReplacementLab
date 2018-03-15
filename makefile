###############################################################
# Program:
#     Lab 10, Page Replacement Lab
#     Brother Ball, CS345
# Author:
#     James Palmer
# Summary:
#     Pageframe algorithms for choosing which frame to replace
# Time:
#     2:30
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab10.o pr.o prFIFO.o prLRU.o prSecond.o
	g++ -o a.out lab10.o pr.o prFIFO.o prLRU.o prSecond.o
	tar -cf lab10.tar makefile *.cpp *.h

##############################################################
# The individual components
##############################################################
lab10.o: lab10.cpp pr.h
	g++ -c lab10.cpp

pr.o: pr.cpp pr.h
	g++ -c pr.cpp

prFIFO.o: prFIFO.cpp prFIFO.h
	g++ -c prFIFO.cpp

prLRU.o: prLRU.h prLRU.cpp 
	g++ -c prLRU.cpp

prSecond.o: prSecond.cpp prSecond.h
	g++ -c prSecond.cpp

clean:
	rm *.o a.out

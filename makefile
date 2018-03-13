###############################################################
# Program:
#     Lab 10, Page Replacement Lab
#     Brother Ball, CS345
# Author:
#     James Palmer
# Summary:
#     
# Time:
#     
###############################################################

##############################################################
# The main rule
##############################################################
a.out: lab10.o pr.o
	g++ -o a.out lab10.o pr.o
	tar -cf lab10.tar makefile *.cpp *.h

##############################################################
# The individual components
##############################################################
lab10.o: lab10.cpp pr.h
	g++ -c lab10.cpp

pr.o: pr*.h pr.cpp pr.h
	g++ -c pr.cpp

clean:
	rm *.o a.out

/***********************************************************************
* Program:
*    Lab 10: Page Replacement Lab
*    Brother Ball, CS 345
* Author:
*    James Palmer
* Summary:
*    This is the driver program to exercise the page replacement algorithm
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>
#include <list>
#include "pr.h"

/*****************************************************************
 * MENU
 * Present the user with a menu from which he/she will select
 * the scheduling algorithm to use
 *****************************************************************/
PageReplacementType menu ()
{
   // present a list of options
   std::cout << "Please select one of the following page replacement algorithms:\n";
   std::cout << "  1. Basic Page Replacement\n";
   std::cout << "  2. First-In-First-Out\n";
   std::cout << "  3. Least Recently Used\n";
   std::cout << "  4. Second Chance\n";

   // prompt the user for a selection
   assert (std::cin.good ());
   int input = 1;
   std::cout << "> ";
   std::cin >> input;
   while (std::cin.fail () || input < 1 || input > 4)
   {
      std::cout << "Error, invalid input. "
         << "Please select a number between 1 and 4: ";
      std::cin >> input;
   }

   // return the type
   PageReplacementType array[] =
   { // 0    1      2      3     4
      BASIC, BASIC, FIFO,  LRU,  SECOND
   };
   assert (input >= 1 && input < sizeof (array) / sizeof (array[1]));
   return array[input];
}

/*********************************************************************
 * READ REFERENCE STRING
 * Prompt the user for a filename containing the reference string.
 * This string is just a list of page numbers
 * Example:
 *     1 0 2 2  1 7 6 7  0 1 2 0  3 0 4 5  1 5 2 4  5 6 7 6  7 2 4 2  7 3 3 2
 *********************************************************************/
std::list <int> readReferenceString ()
{
   std::list <int> output;

   // prompt for filename
   char fileName[256];
   std::cout << "What is the filename of the process file? ";
   std::cin >> fileName;

   // open the file
   std::ifstream fin (fileName);
   if (fin.fail ())
   {
      std::cout << "Unable to open file '"
         << fileName
         << "', exiting.\n";
      return output;
   }

   // actually read the data from the file
   int page;
   while (fin >> page)
      output.push_back (page);

   // close the file
   fin.close ();
   return output;
}

/**********************************************************************
 * MAIN
 * This is where it all begins
 ***********************************************************************/
int main ()
{
   // determine the number of pages in each frame
   int numSlots = 3;
   std::cout << "How many slots: ";
   std::cin >> numSlots;

   // read the process info from a file
   std::list <int> referenceString = readReferenceString ();
   if (referenceString.empty ())
      return 1;

   // select the page replacement algorithm
   PageReplacementAlgorithm * p = prFactory (menu (), numSlots);

   // run the simulation
   std::list <int> ::iterator it;
   for (it = referenceString.begin (); it != referenceString.end (); ++it)
      p->run (*it);

   // display the results
   std::cout << *p;

   // make like a tree
   delete p;
   return 0;
}
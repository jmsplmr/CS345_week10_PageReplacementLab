#include "prSecond.h"
#include <algorithm>

PageReplacementSecond::PageReplacementSecond (int numSlots)
   : PageReplacementAlgorithm(numSlots)
{
   //////////////////// YOUR CODE HERE //////////////////////
   pageReference = 0;
   history = std::vector<int> (numSlots);
}

void PageReplacementSecond::run (int pageNumber)
{
   /////////////// YOUR CODE HERE ////////////////////
   // is pageNumber currently being used?
   for (int i = 0; i < getNumSlots (); i++)
      if (pageFrame.at(i) == pageNumber)
      {
         history.at(i) = 1; //Gives the current slot a second chance
         record (pageNumber, false /*no fault*/);
         return;
      }
   
   while (history.at(pageReference) == 1)
   {
      history.at(pageReference) = 0;
      pageReference = (pageReference + 1) % getNumSlots ();
   }

   pageFrame.at(pageReference) = pageNumber;
   history.at(pageReference) = 1;
   pageReference = (pageReference + 1) % getNumSlots ();

   record (pageNumber, true /*page fault*/);
}

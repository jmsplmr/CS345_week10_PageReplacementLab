#include "prFIFO.h"

PageReplacementFIFO::PageReplacementFIFO (int numSlots)
   : PageReplacementAlgorithm (numSlots)
{
   //////////////// YOUR CODE HERE ////////////////////
   iNextVictim = 0;
}

bool PageReplacementFIFO::ifPageInFrame (int pageNumber)
{
   for (int i = 0; i < getNumSlots (); ++i)
   {
      if (pageFrame[i] == pageNumber)
      {
         record (pageNumber, false /*no fault*/);
         return true;
      }
   }
   return false;
}

void PageReplacementFIFO::addMissingPageToFrame (int pageNumber)
{
   pageFrame[iNextVictim] = pageNumber;
   iNextVictim = (iNextVictim + 1) % getNumSlots ();
}

void PageReplacementFIFO::run (int pageNumber)
{
   /////////////// YOUR CODE HERE ////////////////////
   if (ifPageInFrame (pageNumber))
      return;

   addMissingPageToFrame (pageNumber);

   record (pageNumber, true /*page fault*/);
}
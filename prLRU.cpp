
#include "prLRU.h"
#include <vector>
#include <algorithm>

PageReplacementLRU::PageReplacementLRU (int numSlots)
   : PageReplacementAlgorithm (numSlots)
{
   //////////////// YOUR CODE HERE ////////////////////
   numFrames = 0;
}

void PageReplacementLRU::run (int pageNumber)
{
   /////////////// YOUR CODE HERE ////////////////////
   addPageToStack_noDuplicates (pageNumber);

   moveReferencePageToBack (pageNumber);

   if (pageNumberInFrame (pageNumber))
      return;

   addMissingPageToFrame (pageNumber);

   // for a page fault
   record (pageNumber, true);
}

void PageReplacementLRU::replacePageInFullFrame (int pageNumber)
{
   for (std::vector<int>::iterator it = pageStack.begin (); it != pageStack.end (); ++it)
      for (int i = 0; i < getNumSlots (); i++)
         if (pageFrame[i] == *it)
         {
            pageFrame[i] = pageNumber;
            return;
         }
}

bool PageReplacementLRU::pageNumberInFrame (int pageNumber)
{
   for (int i = 0; i < getNumSlots (); i++)
      if (pageFrame[i] == pageNumber)
      {
         record (pageNumber, false /*no fault*/);
         return true;
      }
   return false;
}

void PageReplacementLRU::moveReferencePageToBack (int pageNumber)
{
   for (std::vector<int>::iterator it = pageStack.begin (); it != pageStack.end (); ++
      it)
      if (*it == pageNumber)
      {
         pageStack.erase (it);
         pageStack.push_back (pageNumber);
         break;
      }
}

void PageReplacementLRU::addPageToStack_noDuplicates (int pageNumber)
{
   if (find (pageStack.begin (), pageStack.end (), pageNumber)
      == pageStack.end ())
      pageStack.push_back (pageNumber);
}

void PageReplacementLRU::addMissingPageToFrame (int pageNumber)
{
   if (numFrames >= getNumSlots ())
      replacePageInFullFrame (pageNumber);
   else
      pageFrame[numFrames++] = pageNumber;
}
#include "prSecond.h"
#include <algorithm>

PageReference::PageReference (const int page, const int references)
   : page(page),
     references(references)
{}

PageReplacementSecond::PageReplacementSecond (int numSlots)
   : PageReplacementAlgorithm(numSlots)
{
   //////////////////// YOUR CODE HERE //////////////////////
   iNextVictim = 0;
   nextFrame = 0;
   numFrames = 0;
}

void PageReplacementSecond::run (int pageNumber)
{
   /////////////// YOUR CODE HERE ////////////////////
   addPageToStack_noDuplicates(pageNumber);

   addReferenceToPage(pageNumber);

   if (pageNumberInFrame(pageNumber))
      return;

   addMissingPageToFrame(pageNumber);

   // for a page fault
   record(pageNumber, true /*page fault*/);
}

bool PageReplacementSecond::advanceQueue ()
{
   return nextFrame = (nextFrame + 1) % getNumSlots();
}

void PageReplacementSecond::replacePageInFullFrame (int pageNumber)
{
   do
      if (pageStackReferences[nextFrame].references == 0)
      {
         for (int i = 0; i < getNumSlots(); ++i)
            if (pageFrame[i] == iNextVictim)
            {
               pageFrame[i] = pageNumber;
               return;
            }
      }
      else
         pageStackReferences[nextFrame].references = 0;
   while (advanceQueue());
}

void PageReplacementSecond::addMissingPageToFrame (int pageNumber)
{
   if (numFrames >= getNumSlots())
   {
      replacePageInFullFrame(pageNumber);
   }
   else
   {
      pageFrame[numFrames++] = pageNumber;
      nextFrame = (nextFrame + 1) % getNumSlots();
   }
}

void PageReplacementSecond::addReferenceToPage (int pageNumber)
{
   std::find(pageStackReferences.begin(),
             pageStackReferences.end(),
             pageNumber)->references += 1;
}

bool PageReplacementSecond::pageNumberInFrame (int pageNumber)
{
   for (int i = 0; i < getNumSlots(); i++)
      if (pageFrame[i] == pageNumber)
      {
         record(pageNumber, false);
         return true;
      }
   return false;
}

void PageReplacementSecond::addPageToStack_noDuplicates (int pageNumber)
{
   if (std::find(pageStackReferences.begin(),
                 pageStackReferences.end(),
                 pageNumber)
       == pageStackReferences.end())
      pageStackReferences.push_back(PageReference(pageNumber, 0));
}

bool operator== (const PageReference & lhs, int rhs)
{
   return lhs.page == rhs;
}

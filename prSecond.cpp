#include "prSecond.h"

PageReplacementSecond::PageReplacementSecond (int numSlots)
   : PageReplacementAlgorithm(numSlots)
{
   //////////////////// YOUR CODE HERE //////////////////////
   page = 0;
   references = std::vector<int>(numSlots);
}

void PageReplacementSecond::advancePageRefSlot ()
{
   page = (page + 1) % getNumSlots();
}

void PageReplacementSecond::addReferenceToPage (int page)
{
   references.at(page) = 1;
}

void PageReplacementSecond::clearReferenceToSlot ()
{
   references.at(page) = 0;
}

bool PageReplacementSecond::pagesHaveReferences ()
{
   return references.at(page) == 1;
}

bool PageReplacementSecond::isPageInFrame (int pageNumber, int i)
{
   return pageFrame.at(i) == pageNumber;
}

void PageReplacementSecond::findVictim ()
{
   while (pagesHaveReferences())
   {
      clearReferenceToSlot();
      advancePageRefSlot();
   }
}

bool PageReplacementSecond::pageInFrameAndReferenced (int pageNumber)
{
   for (int p = 0; p < getNumSlots(); p++)
      if (isPageInFrame(pageNumber, p))
      {
         addReferenceToPage(p);
         record(pageNumber, false);
         return true;
      }
   return false;
}

void PageReplacementSecond::setPageInPageFrame (int pageNumber)
{
   pageFrame.at(page) = pageNumber;
}

void PageReplacementSecond::run (int pageNumber)
{
   /////////////// YOUR CODE HERE ////////////////////
   if (pageInFrameAndReferenced(pageNumber))
      return;
   findVictim();

   addReferenceToPage(page);
   setPageInPageFrame(pageNumber);
   advancePageRefSlot();

   record(pageNumber, true);
}

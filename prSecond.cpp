#include "prSecond.h"
#include <algorithm>

//PageReference::PageReference (const int page, const int references)
//   : page(page),
//     references(references)
//{}

PageReplacementSecond::PageReplacementSecond (int numSlots)
   : PageReplacementAlgorithm(numSlots)
{
   //////////////////// YOUR CODE HERE //////////////////////
   pageReference = 0;
   this->numSlots = 0;
   history = new int[numSlots];
   for (int i = 0; i < numSlots; i++)
      history[i] = 0;
}

void PageReplacementSecond::run (int pageNumber)
{
   /////////////// YOUR CODE HERE ////////////////////
   // is pageNumber currently being used?
   for (int i = 0; i < getNumSlots (); i++)
      if (pageFrame[i] == pageNumber)
      {
         history[i] = 1; //Gives the current slot a second chance
         PageReplacementAlgorithm::record (pageNumber, false /*no fault*/);
         return;
      }
   //Checks if this slot was recently read or written to
   while (history[pageReference] == 1)
   {
      history[pageReference] = 0;
      pageReference++;
      pageReference %= getNumSlots ();
   }

   pageFrame[pageReference] = pageNumber;
   history[pageReference] = 1;
   if (pageReference + 1 == getNumSlots ())
      pageReference = 0;
   else
      pageReference++;

   record (pageNumber, true /*page fault*/);
}
//
//bool PageReplacementSecond::advanceQueue ()
//{
//   return nextFrame = (nextFrame + 1) % getNumSlots();
//}
//
//void PageReplacementSecond::replacePageInFullFrame (int pageNumber)
//{
//   do
//      if (pageStackReferences[nextFrame].references == 0)
//      {
//         for (int i = 0; i < getNumSlots(); ++i)
//            if (pageFrame[i] == iNextVictim)
//            {
//               pageFrame[i] = pageNumber;
//               return;
//            }
//      }
//      else
//         pageStackReferences[nextFrame].references = 0;
//   while (advanceQueue());
//}
//
//void PageReplacementSecond::addMissingPageToFrame (int pageNumber)
//{
//   if (numFrames >= getNumSlots())
//   {
//      replacePageInFullFrame(pageNumber);
//   }
//   else
//   {
//      pageFrame[numFrames++] = pageNumber;
//      nextFrame = (nextFrame + 1) % getNumSlots();
//   }
//}
//
//void PageReplacementSecond::addReferenceToPage (int pageNumber)
//{
//   std::find(pageStackReferences.begin(),
//             pageStackReferences.end(),
//             pageNumber)->references += 1;
//}
//
//bool PageReplacementSecond::pageNumberInFrame (int pageNumber)
//{
//   for (int i = 0; i < getNumSlots(); i++)
//      if (pageFrame[i] == pageNumber)
//      {
//         record(pageNumber, false);
//         return true;
//      }
//   return false;
//}
//
//void PageReplacementSecond::addPageToStack_noDuplicates (int pageNumber)
//{
//   if (std::find(pageStackReferences.begin(),
//                 pageStackReferences.end(),
//                 pageNumber)
//       == pageStackReferences.end())
//      pageStackReferences.push_back(PageReference(pageNumber, 0));
//}
//
//bool operator== (const PageReference & lhs, int rhs)
//{
//   return lhs.page == rhs;
//}

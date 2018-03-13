/***********************************************************************
* Component:
*    Page Replacement LRU
* Author:
*    James Palmer
* Summary: 
*    This is the DERRIVED class to implement LRU
************************************************************************/

#ifndef PR_LRU
#define PR_LRU

#include <iostream>
#include <algorithm>
using namespace std;

/****************************************************
 * SRL
 * The least-recently-used page replacement algorithm
 ***************************************************/
class PageReplacementLRU: public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to LRU
    *****************************************************/
   PageReplacementLRU(int numSlots) : PageReplacementAlgorithm(numSlots)
   {
      //////////////// YOUR CODE HERE ////////////////////  
      iNextVictim = 0;
      numFrames = 0;
   }

   void replacePageInFullFrame (int pageNumber)
   {
      for (vector<int>::iterator it = pageStack.begin ();
           it != pageStack.end (); ++it)
         for (int i = 0; i < getNumSlots (); i++)
            if (pageFrame[i] == *it) 
            {
               pageFrame[i] = pageNumber;
               return;
            }
   }

   bool pageNumberInFrame (int pageNumber)
   {
      for (int i = 0; i < getNumSlots (); i++)
         if (pageFrame[i] == pageNumber)
         {
            record (pageNumber, false /*no fault*/);
            return true;
         }
      return false;
   }

   void moveReferencePageToBack (int pageNumber)
   {
      for (vector<int>::iterator it = pageStack.begin(); it != pageStack.end(); ++it )
         if (*it == pageNumber)
         {
            pageStack.erase (it);
            pageStack.push_back (pageNumber);
            break;
         }
   }

   void addPageToStack_noDuplicates (int pageNumber)
   {
      if (find(pageStack.begin(), pageStack.end(), pageNumber) 
          == pageStack.end())
         pageStack.push_back (pageNumber);
   }

   void addMissingPageToFrame (int pageNumber)
   {
      if (numFrames >= getNumSlots ())
         replacePageInFullFrame(pageNumber);
      else
         pageFrame[numFrames++] = pageNumber;
   }

   /****************************************************
    * RUN
    * Implement the LRU algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run(int pageNumber)
   {
      /////////////// YOUR CODE HERE ////////////////////
      addPageToStack_noDuplicates(pageNumber);

      moveReferencePageToBack(pageNumber);

      if (pageNumberInFrame(pageNumber)) return;

      addMissingPageToFrame(pageNumber);
      
      // for a page fault
      record(pageNumber, true /*page fault*/);
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   vector<int> pageStack;
   int iNextVictim;
   int numFrames;
};

#endif // PR_LRU

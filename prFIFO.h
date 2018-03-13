/***********************************************************************
* Component:
*    Page Replacement FIFO
* Author:
*    James Palmer
* Summary: 
*    This is the DERRIVED class to implement the FIFO algorithm
************************************************************************/

#ifndef PR_FIFO
#define PR_FIFO

#include "pr.h"   // for the PageReplacementAlgorithm base-class

#include <iostream>
#include <queue>
using namespace std;

/****************************************************
 * FIFO
 * The first-in, first-out page replacement algorithm
 ***************************************************/
class PageReplacementFIFO : public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to FIFO
    *****************************************************/
   PageReplacementFIFO(int numSlots) : PageReplacementAlgorithm(numSlots)
   {
      //////////////// YOUR CODE HERE ////////////////////
      iNextVictim = 0;
   }

   bool ifPageInFrame (int pageNumber)
   {
      for (int i = 0; i < getNumSlots(); ++i)
      {
         if (pageFrame[i] == pageNumber)
         {
            record (pageNumber, false /*no fault*/);
            return true;
         }
      }
      return false;
   }

   void addMissingPageToFrame (int pageNumber)
   {
      pageFrame[iNextVictim] = pageNumber;
      iNextVictim = (iNextVictim + 1) % getNumSlots();
   }

   /****************************************************
    * RUN
    * Implement the Basic algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run(int pageNumber)
   {
      /////////////// YOUR CODE HERE ////////////////////
      if (ifPageInFrame(pageNumber)) return;

      addMissingPageToFrame(pageNumber);

      record(pageNumber, true /*page fault*/);
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   int iNextVictim;
};

#endif // PR_BASIC

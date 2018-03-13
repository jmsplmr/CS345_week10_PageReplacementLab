/***********************************************************************
* Component:
*    Page Replacement Second Chance
* Author:
*    James Palmer
* Summary: 
*    This is the DERRIVED class to implement Second
************************************************************************/

#ifndef PR_SECOND
#define PR_SECOND

#include "pr.h"   // for the PageReplacementAlgorithm base-class

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct PageReference
{
   PageReference (const int page, const int references)
      : page(page),
        references(references)
   {}
   int page, references;

   friend bool operator== (const PageReference & lhs, int rhs)
   {
      return lhs.page == rhs;
   }

   friend bool operator!= (const PageReference & lhs, int rhs)
   {
      return !(lhs == rhs);
   }
};

/****************************************************
 * Second Chance
 * The least-recently-used Approximation page replacement
 * algorithm known as Second Chance
 ***************************************************/
class PageReplacementSecond : public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to Second
    *****************************************************/
   PageReplacementSecond(int numSlots) : PageReplacementAlgorithm(numSlots)
   {
      //////////////////// YOUR CODE HERE //////////////////////
      iNextVictim = 0;
      numFrames = 0;
   }

   void addPageToStack_noDuplicates (int pageNumber)
   {

      if (find (pageStackReferences.begin (), pageStackReferences.end (), pageNumber)
         == pageStackReferences.end ())
         pageStackReferences.push_back(PageReference(pageNumber, 1));
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
      addPageToStack_noDuplicates (pageNumber);
      
      // to place "pageNumber" in page 0
      pageFrame[0] = pageNumber;

      // for no page fault
      // PageReplacementAlgorithm::record(pageNumber, false /*no fault*/);

      // for a page fault
      record(pageNumber, true /*page fault*/);
   }

private:
   //////////////////// YOUR CODE HERE //////////////////////
   vector<PageReference> pageStackReferences;
   int iNextVictim;
   int numFrames;
};

#endif // PR_SECOND

/***********************************************************************
* Component:
*    Page Replacement Basic
* Author:
*    Br. Helfrich
* Summary:
*    This is the DERRIVED class to implement a basic page replacement algorithm
************************************************************************/
#pragma once

#include <cstdlib>    // for RAND() and SRAND()
#include <ctime>     // for TIME()
#include "pr.h"

#include <iostream>

/****************************************************
 * BASIC
 * The simplest page replacement algorithm.
 ***************************************************/
class PageReplacementBasic : public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to BASIC
    *****************************************************/
   PageReplacementBasic (int);

   /****************************************************
    * RUN
    * Implement the Basic algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run (int);

private:
   // which frame is selected to be next?
   int iNextVictim;
};

inline PageReplacementBasic::PageReplacementBasic (int numSlots)
   : PageReplacementAlgorithm (numSlots)
{
   // seed the random number generator
   srand (time (NULL));
}

inline void PageReplacementBasic::run (int pageNumber)
{
   std::cerr << "Find page\n";
   // is pageNumber currently being used?
   for (int i = 0; i < getNumSlots (); i++)
      if (pageFrame[i] == pageNumber)
      {
         record (pageNumber, false /*no fault*/);
         return;
      }

   // select the next victim
   int iNextVictim = rand () % getNumSlots ();
   pageFrame[iNextVictim] = pageNumber;

   // call the record method so everything can be reported
   record (pageNumber, true /*page fault*/);
}

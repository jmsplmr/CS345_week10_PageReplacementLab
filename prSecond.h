/***********************************************************************
* Component:
*    Page Replacement Second Chance
* Author:
*    James Palmer
* Summary:
*    This is the DERRIVED class to implement Second
************************************************************************/
#pragma once

#include "pr.h"   // for the PageReplacementAlgorithm base-class

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
   PageReplacementSecond (int);

   /****************************************************
    * RUN
    * Implement the LRU algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run (int);

private:
   //////////////////// YOUR CODE HERE //////////////////////
   std::vector<int> references;
   int page;

   void findVictim ();
   bool pageInFrameAndReferenced (int);
   void setPageInPageFrame (int);

   void advancePageRefSlot ();
   void addReferenceToPage (int);
   void clearReferenceToSlot ();
   bool pagesHaveReferences ();
   bool isPageInFrame (int, int);
};

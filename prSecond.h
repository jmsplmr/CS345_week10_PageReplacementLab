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

//struct PageReference
//{
//   int page, references;
//
//   PageReference (int, int);
//
//   friend bool operator== (const PageReference &, int);
//};

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
   PageReplacementSecond (int numSlots);
   

   /****************************************************
    * RUN
    * Implement the LRU algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run (int pageNumber);

   private:
   //////////////////// YOUR CODE HERE //////////////////////
      std::vector<int> history;
      int pageReference;
};

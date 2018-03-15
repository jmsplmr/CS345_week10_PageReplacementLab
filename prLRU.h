/***********************************************************************
* Component:
*    Page Replacement LRU
* Author:
*    James Palmer
* Summary:
*    This is the DERRIVED class to implement LRU
************************************************************************/
#pragma once

#include <vector>
#include "pr.h"

/****************************************************
 * SRL
 * The least-recently-used page replacement algorithm
 ***************************************************/
class PageReplacementLRU : public PageReplacementAlgorithm
{
public:
   /*****************************************************
    * CONSTRUCTOR
    * initialize the data structures specific to LRU
    *****************************************************/
   PageReplacementLRU (int);

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
   std::vector<int> pageStack;
   int numFrames;

   void replacePageInFullFrame (int);
   bool pageNumberInFrame (int);
   void moveReferencePageToBack (int);
   void addPageToStack_noDuplicates (int);
   void addMissingPageToFrame (int);
};

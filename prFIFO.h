/***********************************************************************
* Component:
*    Page Replacement FIFO
* Author:
*    James Palmer
* Summary: 
*    This is the DERRIVED class to implement the FIFO algorithm
************************************************************************/

#pragma once

#include "pr.h"   // for the PageReplacementAlgorithm base-class

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
   PageReplacementFIFO (int);

   /****************************************************
    * RUN
    * Implement the Basic algorithm here. Thus function will get
    * called several times, each time requesting "pageNumber"
    * from memory. You are to assign that page to a "pageFrame"
    * and then call the base-class to record the results.
    ***************************************************/
   void run (int);

private:
   //////////////////// YOUR CODE HERE //////////////////////
   int iNextVictim;

   bool ifPageInFrame (int);
   void addMissingPageToFrame (int);
};

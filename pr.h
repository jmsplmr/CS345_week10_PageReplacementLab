/***********************************************************************
* Component:
*    Page Replacement
* Author:
*    Br. Helfrich
* Summary: 
*    This is the base-class that enables various
*    page replacement algorithms
************************************************************************/
#pragma once

#include <string>     // for the name of the process
#include <vector>     // for VECTOR
#include <list>       // for LIST

enum PageReplacementType { BASIC, FIFO, LRU, SECOND };
#define PR_NONE -1

/*****************************************************
 * PageReplacementAlgorithm
 * The base-class for all the page replacement algorithms
 ****************************************************/
class PageReplacementAlgorithm
{
 public:
   // only constructor: how many slots are in the pageFrame/
   PageReplacementAlgorithm (int);

   // this is the function you will implement: what will happen
   // when pageNumber gets selected next?
   virtual void run(int) = 0;

   // record the results
   void record(int, bool);
   
   // display the status of the page frames
   friend std::ostream & operator <<
      (std::ostream & out, const PageReplacementAlgorithm &);

   // how many slots are currently in use?
   int getNumSlots () const;

   // the derived classes have access to and are expected to
   // modify pageFrame directly
protected:
   std::vector <int> pageFrame;              // current page frame

private:
   int numSlots;                             // num memory slots in pageFrame
   std::list <std::vector <int> > historyPF; // a history of the page frames
   std::list <int>                historyRS; // a history of the ref. strings
   std::list <bool>               historyF;  // a history of the page faults
   int numFaults;                            // total number of faults
};

PageReplacementAlgorithm * prFactory(PageReplacementType prt, int numSlots);

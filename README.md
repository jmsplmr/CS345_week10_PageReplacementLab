# PREPARE 10 : PAGE REPLACEMENT LAB

_Due Tuesday night at Midnight MST_

The second prepare activity of this week will be to write a program to implement the page replacment algorithms discussed in the chapter. Recall that there are for parts of the submission process: Code, Post, Review, and Submit.

## 1. Write your code - Due Tuesday

The first step in the coding projects is to write the code.

### A. Start with the provided code

Most of the code for this program is provided. You are only to implement the page replacement algorithms, not the user interface. The code is provided in the following location:

```shell
/home/cs345/week10/
```

Here you will find several files:

* `makefile` : compile the files and create a TAR for submission. This should not need to be changed.
* `lab10.cpp` : defines `main()` and a few user interface functions. This should not need to be changed.
* `lab10.out` : an executable so you can see how it should work. This is mostly provided for testing purposes.
* `pr.h` : defines the `PageReplacementAlgorithm` base-class and should not need to be changed.
* `pr.cpp` : implements the interfaces for `PageReplacementAlgorithm` and does not need to be changed.
* `prBasic.h` : contains an implementation for a simple page replacement algorithm. This code is provided. You might want to use it as a reference when implementing the rest of the other algorithms.
* `prFIFO.h` : a stub for the FIFO algorithm you will have to write. You will have to make changes to this file.
* `prLRU.h` : a stub for the LRU algorithm you will have to write. You will have to make changes to this file.
* `prSecond.h` : a stub for the Second Chance algorithm you will have to write. You will have to make changes to this file.
* `test1.txt ... test3.txt` : test files used for `testBed`
* `test4.txt` : a test file matching the reference string in the textbook

Make sure you update the header in the makefile so it gets submitted to the correct location. The assignment this week will be called Lab 10, Page Replacement Lab

### B. Write the code

Implement four scheduling algorithms as mentioned in the textbooks. These algorithms are:

* FIFO: First-In-First-Out found in section 8.4.2 FIFO Page Replacement on page 387-388
* LRU: Least Recently Used found in section 8.4.4 LRU Page Replacement on page 390-392
* Second: Second-Chance found in section 8.4.5.2 Second-Chance Algorithm on page 392-393

The implementation for a basic page replacement algorithm (random) is provided. Also provided is the code to select the proper page replacement algorithm and to display a report. An example of the output is the following. Consider the following page requests:

```shell
2 3 2 1 5 2 4 5 3 2 5 2
```

All of these are in a file called /home/cs345/week10/test2.txt. If this were to be executed using First-In-First-Out using 2 slots, the following would be the output:

```shell
How many slots: 2
What is the filename of the process file? /home/cs345/week10/test2.txt
Please select one of the following page replacement algorithms:
  1. Basic Page Replacement
  2. First-In-First-Out
  3. Least Recently Used
  4. Second Chance
< 2
2 3 2 1 5 2 4 5 3 2 5 2
+-+-+-+-+-+-+-+-+-+-+-+-+
|2|2|2|1|1|2|2|5|5|2|2|2|
| |3|3|3|5|5|4|4|3|3|5|5|
+-+-+-+-+-+-+-+-+-+-+-+-+
 F F   F F F F F F F F
Hit ratio: 2/12
```

You are to implement the constructor and the `run(int pageNumber)` method for the First-In-First-Out, Least-Recently-Used, and Second-Chance algorithms. This `run()` method will simulate a given page request. At the end it must ensure that the passed parameter is somewhere in the pageFrame vector. It must also call `PageReplacementAlgorithm::record(pageNumber, true /*pageFaultOccurred*/);` so we can display the nifty report you see in the output example above. You may need to provide additional member variables or methods to accomplish this task.

### C. Verify

The testBed for this assignment is:

```shell
testBed cs345/lab10 lab10.tar
```

Please make sure your program runs without error. As a reminder, testBed can accept .cpp, .out, and .tar files.

### D. Style

Your program should be well-commented and free of any style-checker errors.

### E. Submit

You will submit this assignment now. Wednesday morning, you will be able to to post your code on the discussion board for review. You will need to submit it again after you have had your code reviewed on the discussion board.

## 2. Post your code - Due Wednesday

As with previous weeks, post your code for review. A few reminders:

The subject of the post should be your full name.
Post by midnight MST MST.
Copy-Paste your code if it is small
include an attachment if your code is big.
Please only post the relevant code. This means only paste code that you actually wrote. This should be limited to the run() method from your derived classes as well as any member variables or changes to the constructors.

## 3. Review - Due Friday

The details of the review component of the lab are described in [Week 10 : Teach One Another](https://content.byui.edu/file/7a03cd5c-d347-4c2d-9518-96433d35f25f/1/Teach/345.10.Teach-Review.html).

## 4. Submit - Due Saturday

The details of the submit component of the lab are described in [Week 10 : Ponder & Prove](https://content.byui.edu/file/7a03cd5c-d347-4c2d-9518-96433d35f25f/1/Ponder/345.10.Ponder.html).
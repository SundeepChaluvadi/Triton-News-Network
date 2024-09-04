// --------------------------------------------------------------------------
//
// Project P2
// Sundeep Chaluvadi
//
// CS5130 Advanced Algorithms
//
// Sharlee Climer, August 2023
//
// --------------------------------------------------------------------------



#ifndef HELLO_H
#define HELLO_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdbool.h>
#include <vector>

#include "Timer.h"

const bool VERBOSE = 1; // set to '1' for a lot of output to screen, '0' otherwise
const bool QUIET = 0; // set to '1' to minimize output to screen, '0' otherwise 

const int STRING_LENGTH = 100; // number of chars allocated for each string
const bool LOG_FILE = 1; // set to 1 to print out logfile

// Define constants for article types
#define GLOBAL 'G'
#define LOCAL 'L'
#define SCIENCE 'S'
#define ENTERTAINMENT 'E'

int numArticles, numReporters, requiredClicks;

// Structure to represent an article
struct Article {
    char name[10];
    char type;
    int reporter;
    int cost;
    int clicks;
    float costPerClicks;
};

int ctr = 0;
int totalCost;
int minimumCost = 1000000;
int outputClicks = 0;

struct Article articles[2000];
int articleCount[256];
char outputFileName[STRING_LENGTH];
char base[STRING_LENGTH]; 
const char outSuffix[] = ".out"; 
FILE *outputFile; 
int minimum;
int count = 0;
int **output;
int combinationCount;

inline void warning(const char* p) { fprintf(stderr,"Warning: %s \n",p); }
inline void fatal(const char* string) {fprintf(stderr,"\n\nFatal: %s\n\n",string); exit(1); }



#endif

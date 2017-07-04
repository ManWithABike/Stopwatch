# Stopwatch
C++ implementation of a `Stopwatch` class

## Introduction
This repository is home to a tiny C++ implementation of a stopwatch. It aims at providing an easy-to-use stopwatch. Basically, it's just an API to `std::chrono::high_precision_clock`. But googling for "*std chrono duration_cast*", "*std chrono time_point template*" for the 271st time -rough estimation-, finally convinved me that I need to write this code snippet. Here I'm sharing the result.

## Installation
Download the header `Stopwatch.hpp` from the include folder of this repository, include it, and you're ready to go. No dependencies no nothing.

## Usage

### Basics
Suppose you have a loop, a function call or a complete program whose execution time you want to measure.  
The `Stopwatch` class allows you to do this with two lines of code:  
`Stopwatch my_watch;` creates an instance of `Stopwatch` and starts it.   
`uint64_t duration_ms = my_watch.elapsed();` returns the elapsed time since the instantiationin milliseconds.

Here's a minimal executable example:
```cpp
#include <iostream>
#include "Stopwatch.h"

int main(){
  //Namespace alias
  namespace sw = stopwatch;

  //Create and start a stopwatch
  sw::Stopwatch my_watch;
   
  //Do something time-consuming here...
   
  //Take the time
  auto duration_ms = my_watch.elapsed()
  std::cout << "Elapsed: " << duration << " milliseconds." << std::endl;
}
```

### Goodies
Additionally, you can start (actually, re-start) the watch manually at any point by calling `my_watch.start()`.  
Furthermore, you can get the elapsed time formatted as seconds, milliseconds, microseconds or nanoseconds by passing the respective template-argument to the `my_watch.elapsed()` call:

```cpp
#include <iostream>
#include "../include/Stopwatch.h"

int main()
{
   //Namespace alias
   namespace sw = stopwatch;

   //Create and start a stopwatch
   sw::Stopwatch my_watch;
   my_watch.start();

   //Do something time-consuming here...

   //Get elapsed time..
   // .. in nanoseconds
   std::uint64_t elapsed_ns = my_watch.elapsed<sw::ns>();
   // .. in microseconds
   std::uint64_t elapsed_mus = my_watch.elapsed<sw::mus>();
   // .. in milliseconds (default template argument, therefore not needed)
   std::uint64_t elapsed_ms = my_watch.elapsed();
   // .. in seconds
   std::uint64_t elapsed_s = my_watch.elapsed<sw::s>();

   return 0;
}
```

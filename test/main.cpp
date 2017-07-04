// Copyright Ingo Proff 2017.
// https://github.com/CrikeeIP/Stopwatch
// Distributed under the MIT Software License (X11 license).
// (See accompanying file LICENSE)

#include <iostream>
#include "../include/Stopwatch.hpp"


int main()
{
   //Namespace alias
   namespace sw = stopwatch;

   //Create and start a stopwatch
   sw::Stopwatch my_watch;
   my_watch.start();

   //Do something time-consuming
   for(std::size_t i = 0; i <= 500000; i++){
      if( i%10 == 0){
         std::cout << i << std::endl;
      }
   }

   //Get elapsed time..
   // .. in nanoseconds
   std::uint64_t elapsed_ns = my_watch.elapsed<sw::nanoseconds>();
   // .. in microseconds
   std::uint64_t elapsed_mus = my_watch.elapsed<sw::microseconds>();
   // .. in milliseconds (default template argument, therefore not needed)
   std::uint64_t elapsed_ms = my_watch.elapsed();
   // .. in seconds
   std::uint64_t elapsed_s = my_watch.elapsed<sw::seconds>();

   std::cout << "---------------" << std::endl;
   std::cout << elapsed_ns << " ns" << std::endl;
   std::cout << elapsed_mus << " mus" << std::endl;
   std::cout << elapsed_ms << " ms" << std::endl;
   std::cout << elapsed_s << " s" << std::endl;

   return 0;
}

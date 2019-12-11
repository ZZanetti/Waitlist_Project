#include "deque.h"
#include "waitlist.h"
#include <string>
#include <iostream>



int main()
{ 
  std::cout << "Hello and welcome to the waitlist application! A c++ program to build and edit waitlists all from the command line!" << std::endl;
  std::cout << "Please type 'help' for a list of valid commands or 'exit' to exit" << std::endl;
  std::shared_ptr<waitlist> w(new waitlist);
  w->init_list();
  w->interact();
    
  
  return 0;
}

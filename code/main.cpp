#include "deque.h"
#include "waitlist.h"
#include <string>
#include <iostream>

enum string_code {
   help,
   create,
   edit,
   ex,
   none,
};

string_code hashit (std::string const& inString) {
    if (inString == "help") return help;
    if (inString == "create") return create;
    if (inString == "edit") return edit;
    if (inString == "exit") return ex;
    else
    {
      return none;
    }
    
}


int main()
{
  //debug
  /*
  Deque q;
  std::cout << q.return_size() << std::endl;
  std::shared_ptr<node> bob(q.init_node("bob", "bobber@aol.com", "123 duh st"));
  std::cout << bob->stored_string_1 << std::endl;
  std::cout << bob->stored_string_2 << std::endl;
  std::cout << bob->stored_string_3 << std::endl;
  std::shared_ptr<node> bob3(q.init_node("bob3", "bobber2@aol.com", "2 duh st"));
  std::shared_ptr<node> bob4(q.init_node("bob4", "bobber3@aol.com", "3 duh st"));
  std::shared_ptr<node> bob2(q.init_node("bob2", "bobber1@aol.com", "1 duh st"));
  
  q.add_node_deque(bob);
  q.add_node_deque(bob2);
  q.add_node_deque(bob3);
  q.add_node_deque(bob4);
  std::cout << q.return_size() << std::endl;
  std::cout << q.peak_bot()->stored_string_1 << std::endl;
  std::cout << q.peak_top()->stored_string_1 << std::endl;
  std::cout << (q.pop_bot())->stored_string_1 << std::endl;
  std::cout << q.peak_bot()->stored_string_1 << std::endl;
  std::cout << (q.pop_top())->stored_string_1 << std::endl;
  std::cout << q.peak_top()->stored_string_1 << std::endl << std::endl;  
  */
  std::cout<< "waitlist section of debug" << std::endl << std::endl;

  waitlist w;
  w.init_list();
  /*
  w.add_student("bob1", "bobber1@aol.com", "1 duh st");
  w.add_student("bob2", "bobber1@aol.com", "1 duh st");
  w.add_student("bob3", "bobber1@aol.com", "1 duh st");
  w.add_student("bob4", "bobber1@aol.com", "1 duh st");
  w.enroll_student();
  w.enroll_student();
  w.enroll_student();
  w.enroll_student();
  */

  w.add_student("bob1", "b@aol.com", "1 st");
  w.add_student("bob2", "bobber1@aol.com", "1 duh st");
  w.add_student("bob3", "bobber1@aol.com", "1 duh st");
  w.add_student("bob4", "bobber123@aol.com", "1 duh st");
  w.add_student("bob5", "bobber1477@aol.com", "12 duh st");
  w.add_student("bob6", "bobber15@aol.com", "13 duh st");
  w.add_student("bob7", "bobber14@aol.com", "14 duhh st");
  w.add_student("bob8", "bobber13@aol.com", "15 duh st");
  w.add_student("bob9", "bobber12@aol.com", "17 dhhuh st");
  w.add_student("bob10", "bobber11@aol.com", "18 hduh st");
  std::cout << w.get_Size() << std::endl;
  std::cout << "testing write to console....." << std::endl;
  w.print_list_to_console();
  std::cout << "testing reduce size....." << std::endl;
  w.reduce_Size(2);

  std::cout << "testing get size....." << std::endl;
  std::cout << w.get_Size() << std::endl;

  
  std::cout << "testing write....." << std::endl;
  w.write_to_csv("test.csv");
  std::cout << "testing load and print....." << std::endl;
  w.load_list("test.csv");
  w.print_list_to_console();
  w.write_to_csv("test.csv");
  //w.load_list("test.csv");
  //w.print_list_to_console();


  
  //debug
  /*
  std::cout << "Hello and welcome to the waitlist application! A c++ program to build and edit waitlists all from the command line!" << std::endl;
  std::cout << "For a list of commands please type 'help', type 'exit' to exit" << std::endl;
  bool still_there = true;
  std::string com;
  while (still_there)
  {
 
  
  std::cin >> com;

  std::cout << "your input was '" << com << "'" << std::endl;



  switch (hashit(com))
  {
  case help:
    std::cout << "commands are 'help' 'create' 'edit' 'exit'" << std::endl;
    break;
  case create:
    std::cout << "Creating a new list!" << std::endl;
    //this will take you to the waitlist functions, which will have their own switch with commands like add, enroll, shrink_list
    
    break;
  case edit:
    std::cout << "Please enter the name of the CSV file with quotations" << std::endl;
    break;
  case ex:
    std::cout << "Goodbye!" << std::endl;
    still_there = false;
    break;
  
  default:
    std::cout << "You need to enter a valid command" << std::endl;
    break;
  }
  }
  */
  return 0;
}

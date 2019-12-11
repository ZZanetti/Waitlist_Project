#ifndef WAITLIST__H
#define WAITLIST__H

#include "deque.h"
#include <fstream>
#include <string>
#include <iostream>



//enroll_next removes the student at the top of the queue and returns their information

//add_student adds a student

//search for student by given string

#define SEARCH 0
#define REMOVE 1
#define PRIORITIZE 2
//shrink_list(int) removes the last x students from the queue. 


class waitlist
{
private:
    std::string list_name;
    std::shared_ptr<Deque> list;

public:
    waitlist(std::string name_of_list = "");
    ~waitlist();
    void init_list();

    int get_Size();
    //void write list to file
    void write_to_csv(std::string file_name);

    //returns true if list loaded successfully
    bool load_list(std::string file_name);

    //prints list line by line to the console
    void print_list_to_console(int option1 = 0);

    
    //void new list
    
    //void add_student
    void add_student(std::string name, std::string email, std::string address);
    //void find_and_blank_student
    std::shared_ptr<node> find_and_blank_student(std::string keyword, int option2 = SEARCH, std::string semail = ".", std::string saddress = ".");

    //string enroll
    void enroll_student(int option3 = 1);
    

    //removes the last x elements of the list and returns the size
    int reduce_Size(int num_to_rm);
    
};














#endif
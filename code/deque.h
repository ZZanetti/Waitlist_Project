#ifndef DEQUE__H
#define DEQUE__H

#include <iostream>
#include <string>




struct student
{
	std::shared_ptr<student> prev;
	std::shared_ptr<student> next;
	std::string name;
	std::string email;
	std::string address;
};

//ill want a helper function to take these attributes and put them into addstudent add_studenthelper name = studen->name, add_stu(name)
class Deque {
private:
	int size;
	std::shared_ptr<student> head;
	std::shared_ptr<student> tail;
    //private vars
public:
    //public functions
    Deque();
    ~Deque();
	int return_size();
	std::shared_ptr<student> init_stud(std::string name, std::string email, std::string address);
	void add_student_deque(std::shared_ptr<student> student);
	std::shared_ptr<student> pop_top();
	std::shared_ptr<student> peak_top();
	std::shared_ptr<student> pop_bot();
	std::shared_ptr<student> peak_bot();
	void set_head(std::shared_ptr<student> student);
	void set_tail(std::shared_ptr<student> student);
	


	

    
};


#endif
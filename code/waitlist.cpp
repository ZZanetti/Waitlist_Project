#include "waitlist.h"
#include "iostream"

waitlist::waitlist(std::string name_of_list)
{
    list_name = name_of_list;
}

waitlist::~waitlist()
{
    
}

void waitlist::init_list(){
    std::shared_ptr<Deque> q(new Deque);
    list = q;
    return;
}

int waitlist::get_Size(){
    return list->return_size();
}
    //void write list to file
void waitlist::write_to_csv(std::string file_name){}

//returns true if list loaded successfully
bool waitlist::load_list(std::string file_name){}

//prints list line by line to the console
void waitlist::print_list_to_console(int option1){
    std::shared_ptr<student> temp_ptr(list->peak_top());
    while (temp_ptr != nullptr)
    {
        if (option1 == 0)
        {
            std::cout << temp_ptr->name << ", " << temp_ptr->email << 
            ", " << temp_ptr->address << std::endl;
            temp_ptr = temp_ptr->next;
            continue;
        }
        else if (option1 == 1)
        {
            std::cout << temp_ptr->name << ", " << temp_ptr->email << 
            ", " << std::endl;
            temp_ptr = temp_ptr->next;
            continue;
        }
        else
        {
            std::cout << temp_ptr->name << std::endl;
            temp_ptr = temp_ptr->next;
            continue;
        }
        
    }
    return;
}


//void new list

//void add_student
void waitlist::add_student(std::string name, std::string email, std::string address){
    std::shared_ptr<student> new_student(list->init_stud(name, email, address));
    list->add_student_deque(new_student);
}

//void find_and_blank_student
std::shared_ptr<student> waitlist::find_and_blank_student(std::string keyword, int option2, std::string semail, std::string saddress){}
//string enroll
void waitlist::enroll_student(int option3){
    while (option3 > 0)
    {
        std::shared_ptr<student> temp = list->pop_top();
        std::cout << temp->name << ", " << temp->email << std::endl;
        option3--;

    }
    
}

//removes the last x elements of the list and returns the size
int waitlist::reduce_Size(int num_to_rm){
    if (list->peak_bot() == nullptr)
    {
        std::cout << "list is empty" << std::endl;
        return 0;
    }
    
    if ((get_Size() - num_to_rm) < 0)
    {
        init_list();
        return 0;
    }
    
    while (num_to_rm > 0)
    {
        std::cout << "removed " << list->pop_bot()->name << std::endl;
        num_to_rm--;
    }
    return get_Size();
}
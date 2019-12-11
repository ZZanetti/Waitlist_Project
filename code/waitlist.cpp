#include "waitlist.h"




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
void waitlist::write_to_csv(std::string file_name){
    std::ofstream my_File;
    my_File.open(file_name);
    if (my_File.is_open())
    {
 
    
    
    std::shared_ptr<node> temp_ptr = list->peak_top();
    if (temp_ptr->stored_string_1 != "Name")
    {
        my_File << "Name,Email,Address,";
    }
    
    while (temp_ptr != nullptr)
    {
        my_File << temp_ptr->stored_string_1 << ",";
        my_File << temp_ptr->stored_string_2 << ",";
        my_File << temp_ptr->stored_string_3 << ",";
        temp_ptr = temp_ptr->next;

    }
    
    //my_File << "end\n";
    my_File.close();
    }
    return;
    

    
}

//returns true if list loaded successfully
bool waitlist::load_list(std::string file_name){
    init_list();
    std::ifstream file_to_load;
    std::string item;
    std::string name;
    std::string email;
    std::string address;
    int count = 0;
    file_to_load.open(file_name);
    if (file_to_load.is_open())
    {
        while (std::getline(file_to_load, item, ','))
        {
            if (count == 0)
            {
                
                name = item;
                count++;
            }
            else if (count == 1)
            {
                email = item;
                count++;
            }
            else
            {
                address = item;
                count = 0;
                add_student(name, email, address);
            }
            
            
            
        }
        
    }
    
    file_to_load.close();
}

//prints list line by line to the console
void waitlist::print_list_to_console(int option1){
    std::shared_ptr<node> temp_ptr(list->peak_top());
    while (temp_ptr != nullptr)
    {
        if (option1 == 0)
        {
            std::cout << temp_ptr->stored_string_1 << ", " << temp_ptr->stored_string_2 << ", " << temp_ptr->stored_string_3 << std::endl;
            temp_ptr = temp_ptr->next;
            continue;
        }
        else if (option1 == 1)
        {
            std::cout << temp_ptr->stored_string_1 << ", " << temp_ptr->stored_string_2 << 
            ", " << std::endl;
            temp_ptr = temp_ptr->next;
            continue;
        }
        else
        {
            std::cout << temp_ptr->stored_string_1 << std::endl;
            temp_ptr = temp_ptr->next;
            continue;
        }
        
    }
    return;
}




//void add_student
void waitlist::add_student(std::string name, std::string email, std::string address){
    std::shared_ptr<node> new_student(list->init_node(name, email, address));
    list->add_node_deque(new_student);
}

//void find_and_blank_student
void waitlist::interact(){
/*
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
  }}
*/
return;
}



//string enroll
void waitlist::enroll_student(int option3){
    while (option3 > 0)
    {
        std::shared_ptr<node> temp = list->pop_top();
        std::cout << temp->stored_string_1 << ", " << temp->stored_string_2 << std::endl;
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
        std::cout << "removed " << list->pop_bot()->stored_string_1 << std::endl;
        num_to_rm--;
    }
    return get_Size();
}
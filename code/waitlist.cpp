#include "waitlist.h"


enum code {
       create,
       load,
       enroll,
       size,
       shrink,
       search,
       add,
       ex,
       view,
       hel,
       none,
    };

    code hash_it(std::string const& inString) {
        if (inString == "create") return create;
        if (inString == "load") return load;
        if (inString == "enroll") return enroll;
        if (inString == "size") return size;
        if (inString == "shrink") return shrink;
        if (inString == "search") return search;
        if (inString == "add") return add;
        if (inString == "view") return view;
        if (inString == "exit") return ex;
        if (inString == "help") return hel;
        
        else
        {
          return none;
        }

    }

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
    file_to_load.close();
    return true;
    }
    
    return false;
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

    bool still_there = true;
    std::string com;
    
    while (still_there){

    std::cout << "please enter a command" << std::endl;
    std::cin >> com;

    std::cout << "your input was '" << com << "'" << std::endl;

      switch (hash_it(com))
      {
        case create:{
        std::string user_list_name;
        std::cout << "Please enter the name of the list" << std::endl;
        std::cin >> user_list_name;
        list_name = user_list_name;
        //name a new list and return to the menu
        break;
        }

        case load:
        std::cout << "commands are 'help' 'create' 'edit' 'exit'" << std::endl;
        break;

        case enroll:
        std::cout << "the following student has been removed from the top of the list...." << std::endl;
        enroll_student();
        //enrolls a student
        break;

        case size:
        std::cout << "the size of the list is " << size << std::endl;
        //return the size of the current list or 0
        break;

        case shrink:{
        std::string number_to_del;
        std::cout << "Your list is " << size << " students long" << std::endl;
        std::cout << "Please enter the number of students to remove" << std::endl;
        std::cin >> number_to_del;
        
        reduce_Size(std::stoi(number_to_del));
        //reduce the size of the current list by a select amount
        break;}

        case search:
        //find a student and delete if wanted 
        // either prints "not found..." or "found, do you want to delete? Y/N"
        std::cout << "Please enter the name of the CSV file with quotations" << std::endl;
        break;

        case add:{
        std::string name, email, address, optional;
        bool keep_going = true;
        while (keep_going)
            {
            std::cout << "Please enter the name of the student" << std::endl;
            std::cin >> name;
            std::cout << "Please enter the email of the student" << std::endl;
            std::cin >> email;
            std::cout << "Please enter the address of the student" << std::endl;
            std::cin >> address;
            add_student(name, email, address);
            std::cout << "Add another student? ('Y'/'N')" << std::endl;
            std::cin >>optional;
            if (optional == "N")
            {
                keep_going = false;
            }
            }
        break;
        }

        case view:
        print_list_to_console();
        break;

        case ex:
        std::cout << "Goodbye!" << std::endl;
        still_there = false;
        break;

        case hel:
        std::cout << "create, load, enroll, size, shrink, search, add, view, exit, help" << std::endl;
        break;
    
      default:
        std::cout << "You need to enter a valid command. Type 'help' for a list of commands" << std::endl;
        break;
      }

    }
    
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
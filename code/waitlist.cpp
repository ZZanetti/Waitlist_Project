#include "waitlist.h"


enum code {
       save,
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
        if (inString == "save") return save;
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
        std::cout << "Removed " << list->pop_bot()->stored_string_1 << std::endl;
        num_to_rm--;

    }
    return get_Size();
}

std::shared_ptr<node> waitlist::search_list(std::string keyword){
    std::shared_ptr<node> temporary_ptr(list->peak_top());

    while (temporary_ptr != nullptr){
        if (keyword == temporary_ptr->stored_string_1 || keyword == temporary_ptr->stored_string_2 || keyword == temporary_ptr->stored_string_3)
        {
            return temporary_ptr;
        }
        temporary_ptr = temporary_ptr->next;
    }
    return nullptr;
}





void waitlist::interact(){

    bool still_there = true;
    std::string com;
    
    while (still_there){

    std::cout << "Please enter a command! ('help' for help, 'exit' to exit)" << std::endl;
    std::cin >> com;

    std::cout << "Your input was '" << com << "'" << std::endl;

      switch (hash_it(com))
      {
        case save:{
        std::string user_list_name;
        std::cout << "Please enter the name of the list ending in .csv" << std::endl;
        std::cin >> user_list_name;
        list_name = user_list_name;
        write_to_csv(user_list_name);
        std::cout << "Done. Saved " << user_list_name << ".\n" << std::endl;
        break;
        }

        case load:{
        std::string user_list_name2;
        std::cout << "Please enter the name of the list" << std::endl;
        std::cin >> user_list_name2;
        std::cout << "trying to load " << user_list_name2 << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        
        if (load_list(user_list_name2))
        {
            print_list_to_console();
            std::cout << "Done." << "\n" << std::endl;
        }
        else
        {
            std::cout << "Failed to load list...(not found or error)" << "\n" << std::endl;
        }
        
        break;    
        }
        
        

        case enroll:
        std::cout << "the following student has been removed from the top of the list...." << std::endl;
        enroll_student();
        std::cout << "Done." << "\n" << std::endl;
        //enrolls a student
        break;

        case size:
        std::cout << "the size of the list is " << get_Size() << "\n" << std::endl;
        //return the size of the current list or 0
        break;

        case shrink:{
        std::string number_to_del;
        std::cout << "Your list is " << get_Size() << " students long" << std::endl;
        std::cout << "Please enter the number of students to remove" << std::endl;
        std::cin >> number_to_del;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        
        reduce_Size(std::stoi(number_to_del));
        //reduce the size of the current list by a select amount
        std::cout << "the size of the list is now " << get_Size() << std::endl;
        std::cout << "Done." << "\n" << std::endl;
        break;}

        case search:{
            std::string search_term;
            std::cout << "Please enter the name, email, or address of the student (case sensitive)" << std::endl;
            std::cin >> search_term;
            std::cout << "Searching..." << std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(1));
            std::shared_ptr<node> if_found_ptr(search_list(search_term));
            if (if_found_ptr == nullptr)
            {
                std::cout << "Not found, returning to menu. Type 'view' to view the list in the console" << std::endl;
            }
            else
            {
                std::cout << "Record of " << search_term << " found." << std::endl;
                std::cout << "Name: " << if_found_ptr->stored_string_1 << std::endl;
                std::cout << "Email: " << if_found_ptr->stored_string_2 << std::endl;
                std::cout << "Address: " << if_found_ptr->stored_string_3 << std::endl;
                std::string decision;
                std::cout << "Would you like to remove this student from the list? ('Y' or 'N')" << std::endl;
                std::cin >> decision;
                if (decision == "Y")
                {
                    list->remove_node(if_found_ptr);
                    std::cout << "Removed." << std::endl;
                }
                break;
            }
            
            

        break;
        }
        //find a student and delete if wanted 
        // either prints "not found..." or "found, do you want to delete? Y/N"
        

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
            std::cout << "Enter 'y' to keep adding, or type 'no' / 'N' to stop" << std::endl;
            std::cin >>optional;
            if (optional == "N" || optional == "no")
            {
                keep_going = false;
            }
            }
        break;
        }

        case view:
        std::cout << "Printing list to console....\n";
        print_list_to_console();
        std::cout << "\n";
        break;

        case ex:
        std::cout << "Goodbye!" << std::endl;
        still_there = false;
        break;

        case hel:
        std::cout << "type 'load' to load an existing list" << std::endl;
        std::cout << "type 'add' to add student(s) to the list" << std::endl;
        std::cout << "type 'view' to view the current list" << std::endl;
        std::cout << "type 'enroll' to remove the student at the top of the current list" 
                     "and return his or her information" << std::endl;
        std::cout << "type 'size' to return the size of the current list" << std::endl;
        std::cout << "type 'shrink' to shrink the current list by removing students at the end first" << std::endl;
        std::cout << "type 'search' to search for a student" << std::endl;
        std::cout << "type 'save' to write your list to the file and name it" << std::endl;
        
        break;
    
      default:
        std::cout << "You need to enter a valid command. Type 'help' for a list of commands" << std::endl;
        break;
      }

    }
    
    return;
}
#include "deque.h"

Deque::Deque(){
    size = 0;
    head = std::shared_ptr<student>(NULL);
    tail = std::shared_ptr<student>(NULL);

}
Deque::~Deque(){

}

int Deque::return_size(){
    return size;
}

std::shared_ptr<student> Deque::init_stud(std::string name, std::string email, std::string address){
        std::shared_ptr<student> ret(new student);
        ret->prev = std::shared_ptr<student>(NULL);
        ret->next = std::shared_ptr<student>(NULL);
        ret->name = name;
        ret->email = email;
        ret->address = address;
        return ret;


}

void Deque::add_student_deque(std::shared_ptr<student> stud){
    
    if (head == nullptr)
    {
        head = stud;
        size++;
        tail = stud;
        return;
    }
    else
    {
        tail->next = stud;
        stud->prev = tail;
        tail = stud;
        size++;
    }
    
    return;

}

std::shared_ptr<student> Deque::pop_top(){
    if (head == nullptr)
    {
        return nullptr;
    }
    
    std::shared_ptr<student> temp_ptr = head;
    set_head(head->next);
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    
    
    size--;
    return temp_ptr;

}

std::shared_ptr<student> Deque::peak_top(){
    return head;

}

std::shared_ptr<student> Deque::pop_bot(){
    if (tail == nullptr)
    {
        return nullptr;
    }
    
    std::shared_ptr<student> temp_ptr = tail;
    set_tail(tail->prev);
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    
    
    size--;
    return temp_ptr;

}

std::shared_ptr<student> Deque::peak_bot(){
    return tail;

}

void Deque::set_head(std::shared_ptr<student> student){
    head = student;
    return;

}
void Deque::set_tail(std::shared_ptr<student> student){
    tail = student;
    return;
}
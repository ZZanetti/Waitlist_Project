#include "deque.h"


Deque::Deque(){
    size = 0;
    head = std::shared_ptr<node>(NULL);
    tail = std::shared_ptr<node>(NULL);

}
Deque::~Deque(){

}

int Deque::return_size(){
    return size;
}

std::shared_ptr<node> Deque::init_node(std::string string1, std::string string2, std::string string3){
        std::shared_ptr<node> ret(new node);
        ret->prev = std::shared_ptr<node>(NULL);
        ret->next = std::shared_ptr<node>(NULL);
        ret->stored_string_1 = string1;
        ret->stored_string_2 = string2;
        ret->stored_string_3 = string3;
        return ret;


}

void Deque::add_node_deque(std::shared_ptr<node> deque_node){
    
    if (head == nullptr)
    {
        head = deque_node;
        size++;
        tail = deque_node;
        return;
    }
    else
    {
        tail->next = deque_node;
        deque_node->prev = tail;
        tail = deque_node;
        size++;
    }
    
    return;

}

std::shared_ptr<node> Deque::pop_top(){
    if (head == nullptr)
    {
        return nullptr;
    }
    
    std::shared_ptr<node> temp_ptr = head;
    set_head(head->next);
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    
    
    size--;
    return temp_ptr;

}

std::shared_ptr<node> Deque::peak_top(){
    return head;

}

std::shared_ptr<node> Deque::pop_bot(){
    if (tail == nullptr)
    {
        return nullptr;
    }
    
    std::shared_ptr<node> temp_ptr = tail;
    set_tail(tail->prev);
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    
    
    size--;
    return temp_ptr;

}

std::shared_ptr<node> Deque::peak_bot(){
    return tail;

}

void Deque::set_head(std::shared_ptr<node> node){
    head = node;
    return;

}
void Deque::set_tail(std::shared_ptr<node> node){
    tail = node;
    return;
}

void Deque::reduce_size(){
    size--;
    return;
}
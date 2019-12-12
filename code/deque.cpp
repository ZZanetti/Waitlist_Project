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
    if (node == nullptr)
    {
        return;
    }
    node->prev = nullptr;
    return;

}
void Deque::set_tail(std::shared_ptr<node> node){
    tail = node;
    if (node == nullptr)
    {
        return;
    }
    
    node->next = nullptr;
    return;
}

void Deque::reduce_size(){
    size = 0;
    return;
}

bool Deque::remove_node(std::shared_ptr<node> node_to_delete){
    std::shared_ptr<node> temp_ptr_1;
    std::shared_ptr<node> temp_ptr_2;

    if (peak_top() == node_to_delete)
    {
        set_head(node_to_delete->next);
        return true;
    }
    else if (peak_bot() == node_to_delete)
    {
        set_tail(node_to_delete->prev);
        return true;
    }
    else
    {
        temp_ptr_1 = node_to_delete->prev;
        temp_ptr_2 = node_to_delete->next;
        temp_ptr_1->next = temp_ptr_2;
        temp_ptr_2->prev = temp_ptr_1;
        return true;
    }
    
    return true;
    
    
}
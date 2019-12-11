#ifndef DEQUE__H
#define DEQUE__H


/*the "Deque" or Double-ended Queue is the data structure used by the waitlist.
the waitlist has more specific features, whereas the Deque could be used for other 
applications easily. That is the reason for the separate .h and .cpp files*/

#include <string>



//deque is a doubly linked list made up of nodes that store up to three strings.
//this struct is easily modified to add other identifiers to nodes if wanted

struct node
{
	std::shared_ptr<node> prev;
	std::shared_ptr<node> next;
	std::string stored_string_1;
	std::string stored_string_2;
	std::string stored_string_3;
};


class Deque {
private:
	int size;
	std::shared_ptr<node> head;
	std::shared_ptr<node> tail;
    //private vars
public:
    //public functions
    Deque();
    ~Deque();
	
	//return the amount of nodes in the Deque
	int return_size();

	//initiate a node
	std::shared_ptr<node> init_node(std::string string1, std::string string2, std::string string3);

	//adds an already created node to the deque
	void add_node_deque(std::shared_ptr<node> deque_node);

	//returns the node on top of the deque and removes it
	std::shared_ptr<node> pop_top();

	//returns the node on top without removing it 
	std::shared_ptr<node> peak_top();

	//returns the node on bottom of the deque and removes it
	std::shared_ptr<node> pop_bot();

	//returns the bottom node without removing it 
	std::shared_ptr<node> peak_bot();

	//helper functions used to set head and tail of the Deque
	void set_head(std::shared_ptr<node> node);

	void set_tail(std::shared_ptr<node> node);

	void reduce_size();
	


	

    
};


#endif
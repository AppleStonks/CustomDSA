#include <iostream>

struct Node{
	int value;
	Node* next;
};

class LinkedList {
public:
	Node* head;
	Node* tail;
	int size;

	LinkedList(){
		head=nullptr;
		tail=nullptr;
		size=0;
	}

	~LinkedList() {
		while (size > 0) {
			pop_front();
		}
	}

	// insert node at head
	void push_front(int value){
		Node* new_node = new Node{value, nullptr};
		new_node->next=head;
		head=new_node;

		// tail and head are same when there is 1 element
		if(size == 0){
			tail = new_node;
		}
		size++;
	}

	// insert node at tail
	void push_back(int value){
		Node* new_node = new Node{value, nullptr};
		if(size == 0){
			head = new_node;
			tail = new_node;
		}
		else{
			tail->next=new_node;
			tail=new_node;
		}
		size++;
	}

	// insert value at index
	void insertAt(int index, int value){
		if(index < 0 || index > size){
			throw std::runtime_error("Index out of range");
		}
		
		if(index==0){
			push_front(value);
			return;
		}
		if(index==size){
			push_back(value);
			return;
		}

		int i = 0;
		Node* ptr = head;
		while(i!=index-1){
			ptr = ptr->next;
			i++;
		}
		Node* new_node = new Node{value, ptr->next};
		ptr->next=new_node;
		size++;

	}

	// get value at an index
	int getValueByIndex(int index){
		if(index >= size){
			throw std::runtime_error("Index out of range");
		}

		int count = 0;
		Node* ptr = head;
		while(ptr!=nullptr){
			if(count == index){
				return ptr->value;
			}
			ptr = ptr->next;
			count++;

		}

		throw std::runtime_error("Something went wrong");
	}

	// pop the value at head
	int pop_front(){
		if(size==0){
			throw std::runtime_error("List is empty");
		}

		int value = head->value;
		Node* next_head = head->next;
		delete head;
		head = next_head;
		size--;

		if(size==0){
			tail = nullptr;
		}
		return value;
	}

	// pop from tail
	int pop_back(){
		if(size==0){
			throw std::runtime_error("List is empty");
		}
		
		int value = tail->value;
		if(size==1){
			delete tail;
			head = nullptr;
			tail = nullptr;
			size--;
			return value;
		}
		Node* ptr = head;
		while(ptr->next != tail){
			ptr = ptr->next;
		}

		ptr->next=nullptr;
		delete tail;
		tail = ptr;
		size--;
		return value;

	}

	void printList(){
		Node* ptr = head;
		while(ptr != nullptr){
			std::cout << ptr->value << std::endl;
			ptr = ptr->next;
		}
	}

	int find(int value){
		int index = 0;
		Node* ptr = head;
		while(ptr != nullptr){
			if(ptr->value==value){
				return index;
			}
			ptr = ptr->next;
			index++;
		}

		return -1;
	}

	bool contains(int value){
		return find(value) != -1;
	}

	void removeAt(int index) {
		if (index < 0 || index >= size) {
			throw std::runtime_error("Index out of range");
		}

		if (index == 0) {
			pop_front(); // already handles size, head/tail
			return;
		}

		Node* prev = head;
		int i = 0;
		while (i < index - 1) {  // stop at node before the one to remove
			prev = prev->next;
			i++;
		}

		Node* to_delete = prev->next;
		prev->next = to_delete->next;

		// Update tail if last node was removed
		if (to_delete == tail) {
			tail = prev;
		}

		delete to_delete;
		size--;
	}	

	

};

int main(){
	
	LinkedList l;
	l.push_front(10);
	l.insertAt(0, 100);
	l.push_front(20);
	l.push_front(30);
	l.printList();

	std::cout << l.find(31230) << std::endl;
	
	return 0;
}
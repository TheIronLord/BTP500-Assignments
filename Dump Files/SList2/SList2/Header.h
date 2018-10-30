#include <iostream>
using namespace std;
template<typename T>
class SList{
	struct Node{
		Node* next;
		T data;
		Node(T data_, Node* next_ = nullptr){
			data = data_;
			next = next_;
		}
	};
	Node* Head_;
	Node* Tail_;
public:
	SList(){
		Head_ = nullptr;
		Tail_ = nullptr;
	}
	void push_Front(const T data_){
		Node* temp = new Node(data_, Head_);
		if (!Head_){
			Tail_ = temp;
		}
		Head_ = temp;
	}
	void push_Back(const T data_){
		Node* temp = new Node(data_);
		if (Head_){
			Node* tempTail = Tail_;
			tempTail->next = temp;
		}
		else{
			Head_ = temp;
		}
		Tail_ = temp;
	}
	void pop_Front(){
		if (Head_){
			Node* temp = Head_->next;
			delete Head_;
			Head_ = temp;
		}
	}
	void pop_Back(){
		if (Tail_){
			if (Head_ != Tail_){
				Node* last = Head_;
				Node* secondLast = Head_;
				while (last != Tail_){
					secondLast = last;
					last = last->next;
				}
				secondLast->next = nullptr;
				delete last;
				Tail_ = secondLast;
			}
			else{
				delete Head_;
				Head_ = Tail_ = nullptr;
			}
		}
	}

	void print(){
		Node* it = Head_;
		while (it){
			cout << "Data: " << it->data << endl;
			it = it->next;
		}
	}
};
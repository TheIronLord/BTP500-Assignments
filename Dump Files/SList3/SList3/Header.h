#include <iostream>
using namespace std;
template <typename T>
class SList{
	struct Node{
		Node* next;
		Node* prev;
		T data;
		Node(const T data_, Node* next_ = nullptr, Node* prev_ = nullptr){
			next = next_;
			prev = prev_;
			data = data_;
		}
	};
	Node* Head_;
	Node* Tail_;
public:
	SList(){
		Head_ = nullptr;
		Tail_ = nullptr;
	}
	void pop_Front(){
		if (Head_){
			if (Head_ != Tail_){
				Node* temp = Head_->next;
				temp->prev = nullptr;
				delete Head_;
				Head_ = temp;
			}
			else{
				delete Head_;
				Head_ = Tail_ = nullptr;
			}
		}
	}
	void pop_Back(){
		if (Head_){
			if (Head_ != Tail_){
				Node* temp = Tail_->prev;
				temp->next = nullptr;
				delete Tail_;
				Tail_ = temp;
			}
			else{
				delete Tail_;
				Head_ = Tail_ = nullptr;
			}
		}
	}
	void push_Front(const T data_){
		Node* temp = new Node(data_, Head_);
		
		if (Head_){
			Head_->prev = temp;
		}
		else{
			Tail_ = temp;
		}
		Head_ = temp;
	}
	void push_Back(const T data_){
		Node* temp = new Node(data_, nullptr, Tail_);
		
		if (Head_){
			Tail_->next = temp;
		}
		else{
			Head_ = temp;
		}
		Tail_ = temp;
	}
	void print(){
		Node* it = Head_;
		while (it){
			cout << "DATA: " << it->data << endl;
			it = it->next;
		}
	}
};
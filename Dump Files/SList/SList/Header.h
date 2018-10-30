#include<iostream>
using namespace std;

template <typename T>
class SList{
	struct Node{
		T data;
		Node* next_;
		Node(T _data, Node* next = nullptr){
			data = _data;
			next_ = next;
		}
	};
	Node* Head_;
	Node* Tail_;
public:
	SList(){
		Head_ = nullptr;
		Tail_ = nullptr;
	}
	void push_Front(T data){
		Node* temp = new Node(data, Head_);
		if (!Head_){
			Tail_ = temp;
		}
		Head_ = temp;
	}
	void push_Back(T data_){
		Node* temp = new Node(data_, Tail_);
		if (Head_){
			Tail_->next_ = temp;
			temp->data = data_;
			temp->next_ = nullptr;
		}else{
			Head_ = temp;
		}
		Tail_ = temp;
	}
	void pop_Front(){
		if (Head_){
			if (Head_ != Tail_){
				Node* n = Head_->next_;
				delete Head_;
				Head_ = n;
			}
			else{
				delete Head_;
				Head_ = nullptr;
			}
		}
	}
	void pop_Back(){
		if (Head_){
			if (Head_ != Tail_){
				Node* last = Head_;
				Node* secondLast = Head_;
				Node* it = Head_;
				while (last != Tail_){
					secondLast = last;
					last = last->next_;
				}
				secondLast->next_ = nullptr;
				delete last;
				Tail_ = secondLast;
			}
			else{
				delete Head_;
				Head_ = nullptr;
			}
		}
	}
	void printf(){
		Node* it = Head_;
		while (it){
			cout << "Data: " << it->data << endl;
			it = it->next_;
		}
	}
};

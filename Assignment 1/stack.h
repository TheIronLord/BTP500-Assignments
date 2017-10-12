
#define STACK_H
#include "a1.h"

template<typename S>
class DList;
template<typename T>
class Stack{
	struct Node{
		Node* m_next;
		T m_data;
		Node(T _data = T{}, Node* _next = nullptr){
			m_next = _next;
			m_data = _data;
		}
	};
	Node* m_head;
	Node* m_tail;
public:
	Stack(){
		m_head = new Node();
		m_tail = new Node();
		m_head->m_next = m_tail;
	}
	void push(const T& data){
		Node* temp = new Node(data);
		if (m_head->m_next == m_tail){
			temp->m_next = m_tail;
		}
		else{
			Node* hold = m_head->m_next;
			temp->m_next = hold;
		}
		m_head->m_next = temp;
	}

	void pop(){
		Node* delte = m_head->m_next;
		Node* connct = delte->m_next;
		delete delte;
		m_head->m_next = connct;
	}

	T top() const{
		Node* top = m_head->m_next;
		return top->m_data;
	}

	bool isEmpty(){
		return (m_head->m_next == m_tail) ? true : false;
	}
};

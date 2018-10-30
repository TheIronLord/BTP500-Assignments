#include <iostream>
using namespace std;

template<typename T>
class DList{
	struct Node{
		Node* m_next;
		Node* m_prev;
		T m_data;
		Node(const T _data T{}, Node* _next = nullptr, Node* _prev = nullptr): 
			m_data(_data),
			m_next(_next),
			m_prev(_prev)
		{}
	};
	Node* m_head;
	Node* m_tail;

public:
	class const_iterator{
		Node* m_curr;
		DList* m_mylist;
		const_iterator(Node* _curr, DList* _mylist):
			m_curr(_curr),
			m_mylist(_mylist)
		{}
	public:
		const_iterator():
			m_curr(nullptr),
			m_mylist(nullptr)
		{}
		const_iterator operator++(int){
			const_iterator old = *this;
			m_curr = m_curr->m_next;
			return old;
		}
		const_iterator operator++(){
			m_curr = m_curr->m_next;
			return *this;
		}
		const_iterator operator--(int){
			const_iterator old = *this;
			m_curr = m_curr->m_next;
			return old;
		}
		const_iterator operator--(){
			m_curr = m_curr->m_next;
			return *this;
		}
		bool operator==(const_iterator right){
			return m_curr == right.m_curr;
		}
		bool operator !=(const_iterator right){
			return m_curr != right.m_curr;
		}
		T operator*(){
			return m_curr->data;
		}
		const_iterator end(){
			return m_tail->m_prev;
		}
		const_iterator begin(){
			return m_head->m_next;
		}
	};
	class iterator : public const_iterator{

	};
	DList(){
		m_head = new Node();
		m_tail = new Node();
		m_head->m_next = m_tail;
		m_head->m_prev = nullptr;
		m_tail->m_prev = m_head;
		m_tail->m_next = nullptr;
	}

	void pop_front(){
		Node* remve = m_head->m_next;
		Node* connct;
		if (remve != m_tail){
			connct = remve->m_prev;
			delete remve;
			m_head->m_next = connct;
			connct->m_prev = m_head;
		}
	}

	void pop_back(){
		Node* remve = m_tail->m_prev;
		Node* connct;
		if (remve->m_prev != m_head){
			connct = remve->m_prev;
			delete remve;
			connct->m_next = m_tail;
			m_tail->m_prev = connct;
		}
	}

	void push_front(T _data){
		Node* add = new Node(_data, m_head->m_next, m_head);
		Node* connct = m_head->m_next;
		m_head->next = add;
		connct->m_prev = add;
	}

	void push_back(T _data){
		Node* add = new Node(_data, m_tail, m_tail->m_prev);
		Node* connct = m_tail->m_prev;
		connct->m_next = add;
		m_tail->m_prev = add;
	}
};
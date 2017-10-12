#include <iostream>
using namespace std;
/*===================================================================
			                Assignment 3				
Iterators:
-const_iterator & iterator
	#operator()--, operator()++, operator(int)++, operator(int)--
	
	These functions are responsible of getting the next highest or 
	lowest value, which it advances the Node pointer to and returns
	an iterator.
	
	#operator()==, operator()!=
	
	These functions are responsible for checking if two nodes are 
	the same or not. It returns a bool depending if the two Nodes
	are the same or not.
	
	#operator()*
	
	This function is responsible for returning the data inside the 
	Node of the iterator/const_iterator.

ThreadedTree:

-Constructor/Destructor
	#ThreadedTree(), ~ThreadedTree()
	
	The constructor is responsible for making root_ nullptr, while 
	the destructor is responsible for deleting each node in the 
	threadedtree and making it a nullptr.

-Insert
	#insert(const T& data), insertSpot(Node*& srch, const T& data)
	
	The insert(const T&data) is responsible for setting root_ Node 
	when The ThreadedTree is empty.It will then put it inside of an 
	iterator and return it. When it isnt empty insert will call 
	insertSpot(Node*& srch, const T& data) to set the data. Now when 
	insertSpot is called it will first locate the spot where 
	the Node is to be placed which is does recursivly. After finding
	the spot where the new Node is to be put it it will set the 
	threads if it needs to. insertSpot(Node*& srch, const T& data) 
	returns the new Node to the insert(const T& data) function which 
	it takes and puts inside of an iterator and returns it.

-Find
	#find(const T& data) const

	The find function uses the data in its parameter to find the Node 
	in the threadedtree which is puts into a const_iterator and then 
	into an iterator which it returns. If it does not find it, it will 
	return the end().

-Begin/End
	#begin(), end(), begin() const, end() const

	These functions are responsible for getting the beginning and one 
	after the end of the threadedtree. The ones with const at the end 
	return const_iterators while the others return iterator.
===================================================================*/

template <class T>
class ThreadedTree{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		bool leftThread;
		bool rightThread;
		bool parent;
		
		Node(const T& data = T{}, Node* left = nullptr, Node* right = nullptr){
			data_ = data;
			left_ = left;
			right_ = right;
			leftThread = false;
			rightThread = false;
		}
	};
	Node* root_;
	void print(const Node* rt, int lvl)const{
		//I won't test this on the main.  You might find it useful
		//to implement for testing purposes
		//Note, passed in lvl so that you can use indentations based on lvl to 
		//see the level of a node is within your tree.  if you don't want to use it
		//just alter the prototype and call from print function

	}

public:
	class const_iterator{
	protected:
		Node* curr_;
		const_iterator(Node* c){ curr_ = c; }
	public:
		const_iterator(){
			curr_ = nullptr;
		}
		const_iterator operator++(int){
			const_iterator old = *this;
			
			/*The rightThread points to the next biggest
			value so the funciton will check if there is 
			no rightThread which if there isnt it will go 
			right and check for a left value. If there is 
			a left value and it isnt a leftThread it will 
			keep going left until it hits the Node with a 
			leftThread.*/
			if (!this->curr_->rightThread){
				if (this->curr_->right_){
					this->curr_ = this->curr_->right_;
				}
				if (this->curr_->left_){
					if (!this->curr_->leftThread){
						while (!this->curr_->leftThread){ 
							this->curr_ = this->curr_->left_;
						}
					}
				}
			} else{
				this->curr_ = this->curr_->right_;
			}
			
			return old;
		}
		const_iterator operator--(int){
			const_iterator old = *this;
			/*The leftThread points to the next smallest
			value so the function will check if there is 
			no leftThread which if there isnt it will go 
			left and check for a right value. If there is 
			a right value and it isnt a rightThread it will 
			keep going right until it hits the Node with
			a rightThread.*/
			if (!this->curr_->leftThread){
				if (this->curr_->left_){
					this->curr_ = this->curr_->left_;
				}
				if (this->curr_->right_){
					while (!this->curr_->rightThread){
						this->curr_ = this->curr_->right_;
					}
				}
			} else{
				this->curr_ = this->curr_->left_;
			}
			return old;
		}
		const_iterator operator++(){
			/*The rightThread points to the next biggest
			value so the function will check if there is 
			no rightThread which if there isnt it will go 
			right and check for a left value. If there is 
			a left value and it isnt a leftThread it will 
			keep going left until it hits the Node with
			a leftThread.*/
			if (!this->curr_->rightThread){
				if (this->curr_->right_){
					this->curr_ = this->curr_->right_;
				}
				if (this->curr_->left_){
					if (!this->curr_->leftThread){
						while (!this->curr_->leftThread){
							this->curr_ = this->curr_->left_;
						}
					}
				}
			} else{
				this->curr_ = this->curr_->right_;
			}
			return *this;
		}
		const_iterator operator--(){
			/*The leftThread points to the next smallest
			value so the function will check if there is 
			no leftThread which if there isnt it will go left 
			and check for a right value. If there is a right 
			value and it isnt a rightThread it will keep going 
			right until it hits the Node with a rightThread.*/
			if (!this->curr_->leftThread){
				if (this->curr_->left_){
					this->curr_ = this->curr_->left_;
				}
				if (this->curr_->right_){
					while (!this->curr_->rightThread){
						this->curr_ = this->curr_->right_;
					}
				}
			} else{
				this->curr_ = this->curr_->left_;
			}
			return *this;
		}
		const T& operator*(){
			return curr_->data_;
		}
		bool operator==(const const_iterator& rhs) const{
			return curr_ == rhs.curr_;
		}
		bool operator!=(const const_iterator& rhs) const{
			return curr_ != rhs.curr_;
		}
		friend class ThreadedTree;
	};
	class iterator :public const_iterator{
		iterator(Node* c) :const_iterator(c){}
	public:
		iterator() :const_iterator(){}
		const T& operator*(){
			return this->curr_->data_;
		}
		iterator operator++(int){
			iterator old = *this;
			/*The rightThread points to the next biggest
			value so the function will check if there is 
			no rightThread which if there isnt it will go 
			right and check for a left value. If there is 
			a left value and it isnt a leftThread it will 
			keep going left until it hits the Node with
			a leftThread.*/
			if (!this->curr_->rightThread){
				if (this->curr_->right_){
					this->curr_ = this->curr_->right_;
				}
				if (this->curr_->left_){
					if (!this->curr_->leftThread){
						while (!this->curr_->leftThread){
							this->curr_ = this->curr_->left_;
						}
					}
				}
			} else{
				this->curr_ = this->curr_->right_;
			}
			return old;
		}
		iterator operator--(int){
			iterator old = *this;
			/*The leftThread points to the next smallest
			value so the function will check if there is 
			no leftThread which if there isnt it will go left 
			and check for a right value. If there is a right 
			value and it isnt a rightThread it will keep going 
			right until it hits the Node with a rightThread.*/
			if (!this->curr_->leftThread){
				if (this->curr_->left_){
					this->curr_ = this->curr_->left_;
				}
				if (this->curr_->right_){
					while (!this->curr_->rightThread){
						this->curr_ = this->curr_->right_;
					}
				}
			} else{
				this->curr_ = this->curr_->left_;
			}
			return old;
		}
		iterator operator++(){
			/*The rightThread points to the next biggest
			value so the function will check if there is 
			no rightThread which if there isnt it will go 
			right and check for a left value. If there is 
			a left value and it isnt a leftThread it will 
			keep going left until it hits the Node with
			a leftThread.*/
			if (!this->curr_->rightThread){
				if (this->curr_->right_){
					this->curr_ = this->curr_->right_;
				}
				if (this->curr_->left_){
					if (!this->curr_->leftThread){
						while (!this->curr_->leftThread){
							this->curr_ = this->curr_->left_;
						}
					}
				}
			} else{
				this->curr_ = this->curr_->right_;
			}
			return *this;
		}
		iterator operator--(){
			/*The leftThread points to the next smallest
			value so the function will check if there is 
			no leftThread which if there isnt it will go left 
			and check for a right value. If there is a right 
			value and it isnt a rightThread it will keep going 
			right until it hits the Node with a rightThread.*/
			if (!this->curr_->leftThread){
				if (this->curr_->left_){
					this->curr_ = this->curr_->left_;
				}
				if (this->curr_->right_){
					while (!this->curr_->rightThread){
						this->curr_ = this->curr_->right_;
					}
				}
			} else{
				this->curr_ = this->curr_->left_;
			}
			return *this;
		}

		friend class ThreadedTree;
	};

	ThreadedTree(){
		root_ = nullptr;
	}

private:
	Node* insertSpot(Node*& srch, const T& data){
		Node* spot = srch;
		Node* rc = spot;

		if (spot->data_ > data){
			if (spot->left_ && !spot->leftThread){
				rc = insertSpot(spot->left_, data);
			} 
			else{
			/*If the parent of the new Node being created
			has a leftThread I'm making the new Node's left
			pointer a leftThread and point to what its parent
			was pointing to and it's right pointer a rightThread
			and point to its parent. I also it's parents 
		    leftThread false since I am taking it. Or else I 
		    make it's left a nullptr and its right pointer a 
		    rightThread and point to its parent, which I also 
		    make it's rightThread true.*/	
				if (spot->leftThread){
					rc = new Node(data, spot->left_, spot);
					spot->leftThread = false;

					spot->left_ = rc;

					rc->rightThread = true;
					rc->leftThread = true;
				} else{
					rc = new Node(data, nullptr, spot);
					spot->left_ = rc;
					rc->rightThread = true;
				}
			}
			
		} else if (spot->data_ < data){
			if (spot->right_ && !spot->rightThread){
				rc = insertSpot(spot->right_, data);

			} else{
			/*If the parent of the new Node being created
			has a rightThread I'm making the new Node's right
			pointer a rightThread and point to what its parent
			was pointing to and it's left pointer a leftThread
			and point to it's parent. I also it's parents 
			rightThread false since I am taking it. Or else 
			I make it's right a nullptr and its left pointer 
			a leftThread and point to its parent, which I also 
			make its leftThread true.*/
				if (spot->rightThread){
					rc = new Node(data, spot, spot->right_);
					spot->rightThread = false;

					spot->right_ = rc;

					rc->leftThread = true;
					rc->rightThread = true;
				} else{
					rc = new Node(data, spot, nullptr);
					spot->right_ = rc;
					rc->leftThread = true;
				}
			}
		}
		
		return rc;
	}

public:
	iterator insert(const T& data){
		Node* rc;
		iterator it;

		if (!root_){
			root_ = new Node(data);
			it.curr_ = root_;
		} else{
			it.curr_ = insertSpot(root_, data);
		}
		
		
		return it;
	}
	
	iterator find(const T& data) const{
		Node* srch = root_;
		bool found = false;
		bool notThere = false;
		const_iterator itConst;
		itConst = end();
		
		while (!found && !notThere){
			if (srch->data_ == data){
				itConst.curr_ = srch;
				found = true;
			}
			if (srch->data_ > data){
				if (srch->left_ && !srch->leftThread){
					srch = srch->left_;
				}
				else{
					notThere = true;
				}
			}
			else if (srch->data_ < data){
				if (srch->right_ && !srch->rightThread){
					srch = srch->right_;
				}
				else{
					notThere = true;
				}
			}
		}
		
		iterator it;
		it.curr_ = itConst.curr_;
		const_iterator constIt = end();
		iterator itEnd;
		itEnd.curr_ = constIt.curr_;
		
		if (notThere){
			return itEnd;
		}
		return it;
	}
	
	iterator begin(){
		iterator it(root_);
		if (root_){
			while (it.curr_->left_){
				--it;
			}
		}
		return it;
	}
	
	iterator end(){
		iterator it(root_);
		if (root_){
			while (it.curr_->right_){
				++it;
			}
			++it;
		}
		return it;
	}
	
	const_iterator begin()const{
		const_iterator it(root_);
		if (root_){
			while (it.curr_->left_){
				--it;
			}
		}

		return it;
	}
	
	const_iterator end() const{
		const_iterator it(root_);

		if (root_){
			while (it.curr_->right_){
				++it;
			}
			++it;
		}
		return it;
	}
	
	void print() const{
		print(root_, 0);
	}
	
	~ThreadedTree(){
		iterator beg = begin();
		iterator endIter = end();
		Node* it;
		/*"it" points to beg Node. beg is now
		advanced and "it" is deleted and made
		a nullptr*/
		while (beg != endIter){
			it = beg.curr_;
			++beg;
			delete it;
			it = nullptr;
		}
	}
};
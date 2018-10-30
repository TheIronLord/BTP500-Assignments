#include<iostream>

class BST{
	struct Node{
		Node* m_left;
		Node* m_right;
		int m_data;
		Node(int _data = 0, Node* _left = nullptr, Node* _right = nullptr){
			m_data = _data;
			m_left = _left;
			m_right = _right;
		}
	};
	Node* m_root;
public:
	BST(){
		m_root = nullptr;
	}

	void insert(int _data){
		bool finished = false;
		Node* srch = m_root;
		if (!m_root){
			m_root = new Node(_data);
		} else{
			while (!finished){
				if (_data < srch->m_data){
					if (srch->m_left){
						srch = srch->m_left;
					} else{
						srch->m_left = new Node(_data);
						finished = true;
					}
				} else{
					if (srch->m_right){
						srch = srch->m_right;
					} else{
						srch->m_right = new Node(_data);
						finished = true;
					}
				}
			}//End of while(!finished)
		}
	}
	void search(Node*& srch, bool& found, int _data, Node*& prvRoot){
		bool valueExists = true;
		
		while (!found && valueExists){
			if (srch->m_data == _data){
				found = true;
			} else if (srch->m_data > _data){
				if (srch->m_left){
					prvRoot = srch;
					srch = srch->m_left;
				} else{
					valueExists = false;
				}
			} else if (srch->m_data < _data){
				if (srch->m_right){
					prvRoot = srch;
					srch = srch->m_right;
				} else{
					valueExists = false;
				}
			}
		} // End of while(!found && !notThere)
	}

	void oneChildSenario(Node*& srch, Node*& prvRoot, int _data){
		if (!srch->m_left && !srch->m_right){
			if (prvRoot->m_data > srch->m_data){
				prvRoot->m_left = nullptr;
			}else if (prvRoot->m_data < srch->m_data){
				prvRoot->m_right = nullptr;
			}
		}else if (srch->m_left && !srch->m_right || !srch->m_left && srch->m_right){
			if (m_root->m_data == _data){
				if (srch->m_right){
					Node* tmp = srch->m_right;
					m_root = tmp;
				}else{
					Node* tmp = srch->m_left;
					m_root = tmp;
				}
			}
		}
	}

	void twoChildrenSenario(Node*& srch, Node*& prvRoot, Node*& minVal, Node*& prvMinVal, int _data){
		bool leftValuesExist = false;
		
		minVal = minVal->m_right;
		while (minVal->m_left){
			prvMinVal = minVal;
			minVal = minVal->m_left;
			leftValuesExist = true;
		}
		
		/*If leftValuesExist is true i want to check if my minVal has any child
		on the right so that I can connect the prvMinVal's left child which was
		minVal to the right child of minVal*/
		if (leftValuesExist){
			if (minVal->m_right){
				prvMinVal->m_left = minVal->m_right;
			}else{
				prvMinVal->m_left = nullptr;
			}
		}
		/*Check to see that srch and prvRoot are not both
		pointing to m_root*/
		if (prvRoot != m_root && srch != m_root){
			if (prvRoot->m_data > srch->m_data){	//Check to see if prvRoot m_left or m_right connects to minVal
				prvRoot->m_left = minVal;
			}else{
				prvRoot->m_right = minVal;
			}
		}
		if (srch->m_right != minVal){	//Check to see that minVal doesnt connect to itself
			minVal->m_right = srch->m_right;
		}
		minVal->m_left = srch->m_left;
	}
	
	void remove(int _data){
		bool found = false;
		Node* srch = m_root;
		Node* prvRoot = srch;
		bool leftValuesExist = false;
		Node* minVal = srch;
		Node* prvMinVal = minVal;
		
		if (m_root){
			if (m_root->m_data == _data && !m_root->m_left && !m_root->m_right){
				delete m_root;
				m_root = nullptr;
				return;
			}
			search(srch, found, _data, prvRoot);
			if (found){
				if (srch->m_left && srch->m_right){
					twoChildrenSenario(srch, prvRoot, minVal, prvMinVal, _data);
				}else{
					oneChildSenario(srch, prvRoot, _data);
				}
				
				/*Incase the m_root is the one being deleted and it has
				two children the m_root would after being deleted be connected
				with minVal*/
				if (srch == m_root){
					delete srch;
					srch = nullptr;
					m_root = minVal;
				}else{
					delete srch;
					srch = nullptr;
				}
			}
		}
	}

	void print(){
		if (m_root){
			printRecursive(m_root);
		}
	}

	void printRecursive(Node* srch){
		if (srch->m_left){
			printRecursive(srch->m_left);
		}
		if (srch->m_right){
			printRecursive(srch->m_right);	
		}
		std::cout << srch->m_data << std::endl;
	}

}; //End of BST class
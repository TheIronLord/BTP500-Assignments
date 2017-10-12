#include <iostream>
#include <string>
#include <utility>
#include "a1.h"
using namespace std;

template <class TYPE>
class Table{
public:
	Table(){}
	virtual bool update(const string& key, const TYPE& value) = 0;
	virtual bool remove(const string& key) = 0;
	virtual bool find(const string& key, TYPE& value) = 0;
	virtual ~Table(){}
};

template <class TYPE>
class SimpleTable :public Table<TYPE>{

	struct Record{
		TYPE data_;
		string key_;
		Record(const string& key = "", const TYPE& data = TYPE{}){
			key_ = key;
			data_ = data;
		}
		bool isEmpty(){
			return key_ == "";
		}
	};

	Record* records_;   //the table
	int max_;           //capacity of the array
	int size_;          //current number of records held
	int search(const string& key);
	void sort();
	void grow();
public:
	SimpleTable(int maxExpected);
	SimpleTable(const SimpleTable& other);
	SimpleTable(SimpleTable&& other);
	virtual bool update(const string& key, const TYPE& value);
	virtual bool remove(const string& key);
	virtual bool find(const string& key, TYPE& value);
	virtual const SimpleTable& operator=(const SimpleTable& other);
	virtual const SimpleTable& operator=(SimpleTable&& other);
	virtual ~SimpleTable();
};


//returns index of where key is found.
template <class TYPE>
int SimpleTable<TYPE>::search(const string& key){
	TYPE rc = -1;
	int low = 0;
	int high = size_ - 1;
	int mid = 0;

	if (high != 0){
		while (low <= high && rc == -1){
			mid = (low + high) / 2;

			if (records_[mid].key_ < key){
				high = mid - 1;
			}
			else if (records_[mid].key_ > key){
				low = mid + 1;
			}
			else{
				rc = mid;
			}
		}
	}
	return rc;
}

//sort the according to key in table
template <class TYPE>
void SimpleTable<TYPE>::sort(){
	Record *tmp = new Record(records_[size_ - 1].key_, records_[size_ - 1].data_);
	int low = 0;
	int high = size_ - 1;
	int rc = -1;
	int mid;

	if (size_ > 1){
		if (tmp->key_ < records_[high - 1].key_){
			return;
		}
	}

	if (size_ <= 2){
		if (size_ == 1){
			return;
		}
		else if (size_ == 2){
			if (records_[0].key_ < records_[1].key_){
				records_[0].key_ = records_[1].key_;
				records_[0].data_ = records_[1].data_;
				records_[1]. key_ = tmp->key_;
				records_[1].key_ = tmp->data_;
			}
		}
	}else{
		bool found = false;
		while (low <= high && rc == -1){
			mid = (low + high) / 2;

			if (records_[mid].key_ > records_[size_ - 1].key_ && records_[mid + 1].key_ < records_[size_ - 1].key_){
				rc = mid + 1;
				found = true;
			}
			if (!found){
				if (records_[mid].key_ < records_[size_ - 1].key_){
					high = mid - 1;
				}
				else if (records_[mid].key_ > records_[size_ - 1].key_){
					low = mid + 1;
				}
			}
		}

		if (!found){
			rc = 0;
			found = true;
		}

		if (found){
			for (int i = size_ - 1; i > 0 && i > rc; i--){
				records_[i] = records_[i - 1];
			}
			records_[rc].key_ = tmp->key_;
			records_[rc].data_ = tmp->data_;
		}
	}
}

//grow the array by one element
template <class TYPE>
void SimpleTable<TYPE>::grow(){
	Record* newArray = new Record[max_ * 2];
	bool* tmp = new bool[max_ * 2];
	max_ = max_ * 2;
	for (int i = 0; i<size_; i++){
		newArray[i] = records_[i];
	}
	delete[] records_;
	records_ = newArray;
}

/* none of the code in the function definitions below are correct.  You can replace what you need
*/
template <class TYPE>
SimpleTable<TYPE>::SimpleTable(int maxExpected) : Table<TYPE>(){
	records_ = new Record[maxExpected];
	max_ = maxExpected;
	size_ = 0;
}

template <class TYPE>
SimpleTable<TYPE>::SimpleTable(const SimpleTable<TYPE>& other){
	*this = other;
}
template <class TYPE>
SimpleTable<TYPE>::SimpleTable(SimpleTable<TYPE>&& other){
	*this = std::move(other);
}

template <class TYPE>
bool SimpleTable<TYPE>::update(const string& key, const TYPE& value){
	int idx = search(key);
	if (idx == -1){
		if (size_ == max_){
			grow();
		}
		records_[size_].key_ = key;
		records_[size_].data_ = value;
		size_++;
		sort();
	}
	else{
		records_[idx].data_ = value;
	}
	return true;
}

template <class TYPE>
bool SimpleTable<TYPE>::remove(const string& key){
	int idx = search(key);
	if (idx != -1){
		int i = 0;
		for (i = idx; i<size_ - 1; i++){
			records_[i] = records_[i + 1];
		}
		records_[i].key_ = "";
		records_[i].data_ = 0;
		size_--;
		return true;
	}
	else{
		return false;
	}
}

template <class TYPE>
bool SimpleTable<TYPE>::find(const string& key, TYPE& value){
	int idx = search(key);
	if (idx == -1){
		return false;
	}
	value = records_[idx].data_;
	return true;
}

template <class TYPE>
const SimpleTable<TYPE>& SimpleTable<TYPE>::operator=(const SimpleTable<TYPE>& other){
	if (this != &other){
		if (records_){
			delete[] records_;
		}
		records_ = new Record[other.max_];
		max_ = other.max_;
		size_ = other.size_;
		for (int i = 0; i<other.size_; i++){
			records_[i] = other.records_[i];
		}
	}
	return *this;
}
template <class TYPE>
const SimpleTable<TYPE>& SimpleTable<TYPE>::operator=(SimpleTable<TYPE>&& other){
	size_ = std::move(other.size_);
	max_ = std::move(other.max_);
	records_ = std::move(other.records_);
	other.records_ = nullptr;
	other.size_ = 0;
	other.max_ = 0;

	return *this;
}
template <class TYPE>
SimpleTable<TYPE>::~SimpleTable(){
	if (records_){
		delete[] records_;
	}
}

template <class TYPE>
class HashTable :public Table<TYPE>{
	struct Records{
		TYPE data;
		string key;

		Records(const TYPE& data_ = TYPE{}, const string key_ = "") : data(data_), key(key_){}
	};
	DList<Records>*dlist;
	int capacity;
public:
	HashTable(int maxExpected);
	HashTable(const HashTable& other);
	HashTable(HashTable&& other);
	virtual bool update(const string& key, const TYPE& value);
	virtual bool remove(const string& key);
	virtual bool find(const string& key, TYPE& value);
	virtual const HashTable& operator=(const HashTable& other);
	virtual const HashTable& operator=(HashTable&& other);
	virtual ~HashTable();
};
/* none of the code in the function definitions below are correct.  You can replace what you need
*/
template <class TYPE>
HashTable<TYPE>::HashTable(int maxExpected) : Table<TYPE>(){
	dlist = new DList<Records>[maxExpected];
	capacity = maxExpected;
}

template <class TYPE>
HashTable<TYPE>::HashTable(const HashTable<TYPE>& other){
	*this = other;
}
template <class TYPE>
HashTable<TYPE>::HashTable(HashTable<TYPE>&& other){
	*this = std::move(other);
}
template <class TYPE>
bool HashTable<TYPE>::update(const string& key, const TYPE& value){
	std::hash<std::string> hash_fn;
	size_t address = hash_fn(key) % capacity;

	if (dlist[address].empty()){
		const Records r(value, key);
		dlist[address].push_front(r);
	}
	else{
		auto itB = dlist[address].begin();
		auto itE = dlist[address].end();
		bool found = false;

		while (itB != itE && !found){
			if (itB.getKey() == key){
				found = true;
				Records r(value, key);
				itB.setValue(r);
			}
			++itB;
		}
		if (!found){
			const Records r(value, key);
			dlist[address].push_front(r);
		}
	}
	return true;
}

template <class TYPE>
bool HashTable<TYPE>::remove(const string& key){
	std::hash<std::string> hash_fn;
	size_t address = hash_fn(key) % capacity;
	bool found = false;

	if (!dlist[address].empty()){
		auto it = dlist[address].begin();
		auto itE = dlist[address].end();
		
		it = dlist[address].search(key);
		found = it != itE;
		if (found){
			dlist[address].erase(it);
		}
	}
	return found;
}

template <class TYPE>
bool HashTable<TYPE>::find(const string& key, TYPE& value){
	std::hash<std::string>hash_fn;
	size_t address = hash_fn(key) % capacity;
	bool found = false;

	if (!dlist[address].empty()){
		auto it = dlist[address].begin();
		auto itE = dlist[address].end();
		it = dlist[address].search(key);
		found = it != itE;
		if (found){
			Records r = it.getValue();
			value = r.data;
		}
	}
	return found;
}

template <class TYPE>
const HashTable<TYPE>& HashTable<TYPE>::operator=(const HashTable<TYPE>& other){
	if (this != &other){
		if (dlist){
			delete[]dlist;
		}

		dlist = new DList<Records>[other.capacity];
		capacity = other.capacity;

		for (int i = 0; i < capacity; i++){
			if (!other.dlist[i].empty()){
				dlist[i] = other.dlist[i];
			}
		}
	}

	return *this;
}
template <class TYPE>
const HashTable<TYPE>& HashTable<TYPE>::operator=(HashTable<TYPE>&& other){
	dlist = std::move(other.dlist);
	capacity = std::move(other.capacity);

	other.capacity = 0;
	other.dlist = nullptr;

	return *this;
}
template <class TYPE>
HashTable<TYPE>::~HashTable(){
	if (dlist){
		delete[]dlist;
	}
}

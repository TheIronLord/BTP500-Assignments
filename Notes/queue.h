class Queue{
	DList<T> theQueue;
	public:
		Queue(){

		}
		void enqueue(const T& data){
			theQueue.push_back(data);
		}
		void dequeue(){
			theQueue.pop_front();
		}
		void front(){
			DList<T>::iterator it = theQueue.begin();
		}
		void pop();
		T top();
		bool isEmpty();
};
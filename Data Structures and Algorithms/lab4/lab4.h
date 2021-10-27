/**************************************************/
/*                                                */
/*  Lab 2 Starter file                            */
/*                                                */
/*  Name:Michael                                  */
/*  Student number:143152189                      */
/*                                                */
/**************************************************/
#include <iostream>

template <typename T>
class DList {
	struct Node {
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	DList() {
		front_ = nullptr;
		back_ = nullptr;
	}
	void push_front(const T& data);
	~DList();

	class const_iterator {
		friend class DList;
		const DList* myList_;			//list that the iterator refers to --> keeps track of which list we are iterating
		Node* curr_;
		const_iterator(Node* n, const DList* theList) {
			curr_ = n;
			myList_ = theList;
		}
	public:
		//Sets to safe state
		const_iterator() {
			curr_ = nullptr;
			myList_ = nullptr;
		}
		const_iterator operator++() {
			//prefix
			//increment value & return
			curr_ = curr_->next_;
			return *this;
		}
		const_iterator operator++(int) {
			//postfix requires unique signature
			//return original value and increment
			const_iterator old = *this;
			curr_ = curr_->next_;
			return old;
		}
		const_iterator operator--() {
			//If curr is not a nullptr
			if (curr_)
				curr_ = curr_->prev_;
			//otherwise set to back
			else if (myList_)
				curr_ = myList_->back_;
			
			return *this;
		}
		const_iterator operator--(int) {
			const_iterator old = *this;

			if (curr_)
				curr_ = curr_->prev_;
			else if (myList_)
				curr_ = myList_->back_;

			return old;
		}
		bool operator==(const_iterator rhs) {			
			return (myList_ == rhs.myList_ && curr_ == rhs.curr_) ? true : false;
		}
		bool operator!=(const_iterator rhs) { return !(*this == rhs); }
		const T& operator*()const { return curr_->data_; }
	};
	class iterator :public const_iterator {
		friend class DList;
		//no need for curr_ due to inheritence 
		iterator(Node* n, DList* theList) :const_iterator(n, theList) {};

	public:
		iterator() :const_iterator() {};
		iterator operator++() {
			//access to curr_ here is diff than base const_iterator
			this->curr_ = this->curr_->next_;  //might need to change this->
			return *this;
		}
		iterator operator++(int) {
			iterator old = *this;
			this->curr_ = this->curr_->next_;
			return old;
		}
		iterator operator--() {			
			if (this->curr_)
				this->curr_ =this->curr_->prev_;			
			else if (this->myList_)
				this->curr_ =this->myList_->back_;

			return *this;
		}
		iterator operator--(int) {}
		T& operator*() {
			return this->curr_->data_;
		}
		const T& operator*()const {return this->curr_->data_;}

	};
	const_iterator cbegin() const {
		//set iterator to refer to first data item in list
		return const_iterator(front_, this);
	}
	iterator begin() {
		return iterator(front_, this);
	}
	const_iterator cend() const {
		//returns node that follows last data node
		return const_iterator(nullptr, this);
		//does NOT return back-->next_ --> will fail on empty list
	}
	iterator end() {
		return iterator(nullptr, this);
	}
};


template <typename T>
void DList<T>::push_front(const T& data) {
	Node* nn = new Node(data, front_);
	if (front_ != nullptr) {
		front_->prev_ = nn;
	}
	else {
		back_ = nn;
	}
	front_ = nn;
}

template <typename T>
DList<T>::~DList() {
	Node* rm = front_;
	while (rm)
	{
		Node* nn = rm->next_;
		delete rm;
		rm = nn;
	}
}
template <typename T>
class Sentinel {
	struct Node {
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel() {
		front_ = new Node();
		back_ = new Node();
		front_->next_ = back_;
		back_->prev_ = front_;
	}
	void push_front(const T& data);
	~Sentinel();

	class const_iterator {
		friend class Sentinel;	
		Node* curr_;
		const_iterator(Node* n) {
			curr_ = n;						
		}

	public:
		const_iterator() {
			curr_ = nullptr;			
		}
		const_iterator operator++() {
			curr_ = curr_->next_;
			return *this;
		}
		const_iterator operator++(int) {
			const_iterator old = *this;
			curr_ = curr_->next_;
			return old;
		}
		const_iterator operator--() {
			curr_ = curr_->prev_;
			return *this;
		}
		const_iterator operator--(int) {
			const_iterator old = *this;
			curr_ = curr_->prev_;
			return old;
		}
		bool operator==(const_iterator rhs) {
			return (curr_ == rhs.curr_) ? true : false;
		}
		bool operator!=(const_iterator rhs) { return !(*this == rhs); }
		const T& operator*()const { return curr_->data_; } 
	};
	class iterator :public const_iterator {
		friend class Sentinel;
		iterator(Node* n) :const_iterator(n) {};
	public:
		iterator() :const_iterator() {};
		iterator operator++() {
			this->curr_ = this->curr_->next_;
			return *this;
		}
		iterator operator++(int) {
			iterator old = *this;
			this->curr_ = this->curr_->next_;
			return old;
		}
		iterator operator--() {}
		iterator operator--(int) {}
		T& operator*() { return this->curr_->data_; }
		const T& operator*()const { return this->curr_->data_; }
	};
	const_iterator cbegin() const {
		//returns front sentinel
		return const_iterator(front_->next_);
	}
	iterator begin() { 
		return iterator(front_->next_);
	}
	const_iterator cend() const {
		//returns back sentinel
		return const_iterator(back_);
	}
	iterator end() { 
		return iterator(back_); 
	}
};


template <typename T>
void Sentinel<T>::push_front(const T& data) {
	Node* nn = new Node(data, front_->next_, front_);
	front_->next_->prev_ = nn;
	front_->next_ = nn;
}

template <typename T>
Sentinel<T>::~Sentinel() {
	Node* rm = front_;
	while (rm)
	{
		Node* nn = rm->next_;
		delete rm;
		rm = nn;
	}
}
// Name: Dylan Phan
// CWID: 885582536
// Email: DylanP@csu.fullerton.edu

#ifndef MY_DOUBLY_LINKED_LIST_HPP
#define MY_DOUBLY_LINKED_LIST_HPP


/**
 * TODO: Implement DoublyLinkedList, its Node, and its Iterator!
 * 
 * I've left some methods filled out for you,
 * 	and stubbed out some structure, to reduce difficulty.
 * 
 * You may add or remove methods as you see fit,
 * 	as long as you can still pass all unit tests.
 * Although, it may be more difficult to do so. Your choice!
 * 
 * Notice we're inside a namespace here.
 * The DLL is inside a namespace called DoublyLinkedList,
 * 	which is itself inside a namespace called CPSC131
 * This means, if you'd like to play around with your class later,
 * 	you'll need to access it like so:
 * ::CPSC131::DoublyLinkedList::DoublyLinkedList<int> list;
 * 
 * Look into main.cpp and CPP_Tests.cpp for examples of using
 * 	the DLL and your BookStore. But don't worry too much, as you
 * 	only need to implement these classes
 * (main and tests are already done for you)
 */


//
#include <iostream>
#include <stdlib.h>
#include <stdexcept>


/**
 * Namespace for our classroom !
 */
namespace CPSC131
{
	/**
	 * Namespace to hold all things related to our DLL
	 */
	namespace DoublyLinkedList
	{
		/**
		 * Implement our DoublyLinkedList class !
		 */
		template <class T>
		class DoublyLinkedList
		{
			public:
				
				/**
				 * Node class, representing a single item in our linked list
				 */
				// TODO: Complete all class methods
				class Node
				{
					public:
						
						/// CTORS
						Node() : prev_(nullptr), next_(nullptr) {}
						Node(T element) {
							element_ = element;
							prev_ = nullptr;
							next_ = nullptr;
						}
						Node(T element, Node* prev, Node* next) {
							element_ = element;
							prev_ = prev;
							next_ = next;
							}
						
						/// Set the pointer to the previous element
						void setPrevious(Node* prev) {prev_ = prev;}
						
						/// Set the pointer to the previous element
						void setPrev(Node* prev) {this->setPrevious(prev);}
						
						/// Get a pointer to the previous element
						Node* getPrevious() { return prev_; }
						
						/// Get a pointer to the previous element
						Node* getPrev() { return this->getPrevious(); }
						
						/// Set the pointer to the next node
						void setNext(Node* next) {next_ = next;}
						
						/// Get a pointer to the next node
						Node* getNext() { return next_; }
						
						/// Set the element this node holds
						void setElement(T element) {element_ = element;}
						
						/// Get the element this node holds
						///	YOUR WELCOME
						T& getElement() { return this->element_; }
						
						/// Return a reference to the element
						///	YOUR WELCOME
						T& operator*() { return &element_; }
						
					private:
						T element_;
						Node* prev_;
						Node* next_;
				};
				
				/**
				 * Nested Iterator class.
				 * This allows user code to refer to the Iterator's type as:
				 * 
				 * CPSC131::DoublyLinkedList::DoublyLinkedList<int>::Iterator
				 * 
				 * (as opposed to specifying the template argument two times)
				 */
				class Iterator
				{
					public:
						
						///	Constructor that does nothing; YOUR WELCOME
						Iterator()
						{
							/// yw
						}
						
						///	Constructor taking a head and tail pointer; YOUR WELCOME
						Iterator(Node* head, Node* tail) : head_(head), tail_(tail)
						{
							this->cursor_ = this->end();
						}
						
						///	Constructor taking a head, tail, and cursor pointer; YOUR WELCOME
						Iterator(Node* head, Node* tail, Node* cursor) : head_(head), tail_(tail), cursor_(cursor) {}
						
						///	Get a pointer to the head node, or end() if this list is empty
						Node* begin()
						{
							//	TODO: Your code here
							if (head_ != nullptr) {
								return head_;
							} else {
							return this->end();
							}

						}
						
						///	Get a node pointer representing "end" (aka "depleted"). Probably want to just use nullptr.
						Node* end()
						{
							//	TODO: Your code here
							
							return nullptr;
						}
						
						///	Get the node to which this iterator is currently pointing
						Node* getCursor()
						{
							//	TODO: Your code here
							return this->cursor_;
						}
						
						/**
						 * Assignment operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator=(const Iterator& other)
						{
							//	TODO: Your code here
							head_ = other.head_;
							tail_ = other.tail_;
							cursor_ = other.cursor_;
							return *this;
						}
						
						///	Comparison operator
						bool operator==(const Iterator& other)
						{
							//	TODO: Your code here
							return ((head_ == other.head_)&&(tail_ == other.tail_)&&(cursor_ == other.cursor_));
							

						}
						///	Inequality comparison operator
						bool operator!=(const Iterator& other)
						{
							//	TODO: Your code here
							Iterator temp = other;
							if ((head_ != temp.begin())||(tail_ != temp.end())||(cursor_ != temp.getCursor())) {
								return true;
							} else {
								return false;
							}
						}
						
						/**
						 * Prefix increment operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator++()
						{
							//	TODO: Your code here
							if (cursor_ != nullptr) {
								cursor_ = cursor_->getNext();
							}
							return *this;
						}
						
						/**
						 * Postfix increment
						 * Return a copy of this Iterator, BEFORE it was modified
						 */
						Iterator operator++(int)
						{
							//	TODO: Your code here
							Node* temp = cursor_; // come back
							if (cursor_ != nullptr) {
								cursor_ = cursor_->getNext();
							}							
							return Iterator(head_,tail_,temp);
						}
						
						/**
						 * Prefix decrement operator
						 * Return a copy of this Iterator, after modification
						 */
						Iterator& operator--()
						{
							//	TODO: Your code here
							if (cursor_ != nullptr) {
								cursor_ = cursor_->getPrevious();
							}							
							return *this;
						}
						
						/**
						 * Postfix decrement operator
						 * Return a copy of this Iterator BEFORE it was modified
						 */
						Iterator operator--(int)
						{
							//	TODO: Your code here
							Node* temp = cursor_;
							if (cursor_ != nullptr) {
								cursor_ = cursor_->getPrevious();
							}
							return Iterator(head_,tail_,temp);
						}
						
						/**
						 * AdditionAssignment operator
						 * Return a copy of the current iterator, after modification
						*/
						Iterator operator +=(size_t add)
						{
							//	TODO: Your code here
							for (size_t i = 0; i < add && cursor_ != nullptr; i++) {
								cursor_ = (*cursor_).getNext();
							}
							return Iterator(head_,tail_,cursor_);
						}
						/**
						 * SubtractionAssignment operator
						 * Return a copy of the current iterator, after modification
						 */
						Iterator operator -=(size_t add)
						{
							//	TODO: Your code here
							for (size_t i = 0; i < add; i++) {
								if (cursor_ != nullptr) {
									cursor_ = cursor_->getPrevious();
								} else {
									break;
								}
							}
							return Iterator(head_,tail_,cursor_);
						}
						
						/**
						 * AdditionAssignment operator, supporting positive or negative ints
						 */
						Iterator operator +=(int add)
						{
							//	TODO: Your code here
							size_t temp = 0;
							if (add < 0) {
								temp = add*-1;
								return operator-=(temp);
							} else {
								temp = add;
								return operator+=(temp);
							}
						}
						
						/**
						 * SubtractionAssignment operator, supporting positive or negative ints
						 */
						Iterator operator -=(int subtract)
						{
							//	TODO: Your code here
							size_t temp =  0;
							if (subtract < 0) {
								temp = subtract*-1;
								return operator += (temp);
							} else {
								temp = subtract;
								return operator-=(temp);
							}
						}
						
						/**
						 * Dereference operator returns a reference to the ELEMENT contained with the current node
						 */
						T& operator*()
						{
							//	TODO: Your code here
							
							return (cursor_->getElement());
						}
					
					private:
						
						/// Pointer to the head node
						Node* head_ = nullptr;
						
						/// Pointer to the tail node
						Node* tail_ = nullptr;
						
						/**
						 * Pointer to the cursor node.
						 * This is only one way of letting the iterator traverse the linked list.
						 * You can change to a different method if you wish (and can still pass unit tests)
						 */
						Node* cursor_ = nullptr;
					
					friend class DoublyLinkedList;
				};
				
				/// Your welcome
				DoublyLinkedList()
				{
					//	TODO: Your code here
					this->head_ = nullptr;
					this->tail_ = nullptr;
					this->size_ = 0;
				}
				
				///	Copy Constructor
				DoublyLinkedList(DoublyLinkedList& other)
				{
					//	TODO: Your code here
					this->head_ = nullptr;
					this->tail_ = nullptr;
					this->size_ = 0;
					operator=(other);
				}
				
				/// DTOR
				~DoublyLinkedList()
				{
					//	TODO: Your code here
					this->clear();
				}
				
				/**
				 * Clear the list and assign the same value, count times.
				 * If count was 5, T was int, and value was 3,
				 * 	we'd end up with a list like {3, 3, 3, 3, 3}
				 */
				void assign(size_t count, const T& value)
				{
					//	TODO: Your code here
					clear();
					Iterator posit = begin();
					for (size_t i = 0; i < count; i++) {
						posit = insert_after(posit, value);
					}
				}
				
				/**
				 * Clear the list and assign values from another list.
				 * The 'first' iterator points to the first item copied from the other list.
				 * The 'last' iterator points to the last item copied from the other list.
				 * 
				 * Example:
				 * 	Suppose we have a source list like {8, 4, 3, 2, 7, 1}
				 * 	Suppose first points to the 4
				 *	Suppose last points to the 7
				 * 	We should end up with our list becoming: {4, 3, 2, 7}
				 *
				 * If the user code sends out-of-order iterators,
				 * 	just copy from 'first' to the end of the source list
				 * Example: first=7, last=4 from the list above would give us:
				 * 	{7, 1}
				 */
				void assign(Iterator first, Iterator last)
				{
					//	TODO: Your code here
					clear();
					for (auto i = first; i != last; ++i) {
						this->push_back(*i);
					}
				}
				
				/// Return a pointer to the head node, if any
				Node* head() const
				{
					//	TODO: Your code here
					return head_;
				}
				
				/// Return a pointer to the tail node, if any
				Node* tail() const
				{
					//	TODO: Your code here
					
					return tail_;
				}
				
				/**
				 * Return an iterator that points to the head of our list
				 */
				Iterator begin() const
				{
					//	TODO: Your code here
					
					return Iterator(head_, tail_, head_);
				}
				
				/**
				 * Return an iterator that points to the last element (tail) of our list
				 */
				Iterator last() const
				{
					//	TODO: Your code here
					
					return Iterator(head_, tail_, tail_);
				}
				
				/**
				 * Should return an iterator that represents being past the end of our nodes,
				 * or just that we are finished.
				 * You can make this a nullptr or use some other scheme of your choosing,
				 * 	as long as it works with the logic of the rest of your implementations.
				 */
				Iterator end() const
				{
					//	TODO: Your code here
					
					return Iterator(head_, tail_, nullptr);
				}
				
				/**
				 * Returns true if our list is empty
				 */
				bool empty() const
				{
					//	TODO: Your code here
					
					return(size_ == 0);
				}
				
				/**
				 * Returns the current size of the list
				 * Should finish in constant time!
				 * (keep track of the size elsewhere)
				 */
				size_t size() const
				{
					//	TODO: Your code here
					
					return size_;
				}
				
				/**
				 * Clears our entire list, making it empty
				 * Remember: All removal operations should be memory-leak free.
				 */
				void clear()
				{
					//	TODO: Your code here
					while (head_ != nullptr)
					{
						Node* temp = head_;
						head_ = head_->getNext();
						delete temp;
						size_--;
					}
					
					head_ = nullptr;
					tail_ = nullptr;
					size_ = 0;
				}
				
				/**
				 * Insert an element after the node pointed to by the pos Iterator
				 * 
				 * If the list is currently empty,
				 * 	ignore the iterator and just make the new node at the head/tail (list of length 1).
				 * 
				 * If the incoming iterator is this->end(), insert the element at the tail
				 * 
				 * Should return an iterator that points to the newly added node
				 * 
				 * To avoid repeated code, it might be a good idea to have other methods
				 * 	rely on this one.
				 */
				Iterator insert_after(Iterator pos, const T& value)
				{
					//	TODO: Your code here
					if (size_ == 0 || head_ == nullptr) {
						Node* new_node = new Node(value);
						new_node->setPrevious(nullptr);
						new_node->setNext(nullptr);
						head_ = new_node;
						tail_ = new_node;
						size_++;
						
					return Iterator(head_,tail_, new_node);
					}
					T tempor = value;
					Node* temp = new Node(tempor);

					if (pos == this->end()) {
						temp->setPrevious(tail_);
						temp->setNext(nullptr);
						tail_->setNext(temp);
						tail_= temp;
					} else {
						Node* pos_node = pos.getCursor();
						Node* temporary = pos_node->getNext();
						if (temporary != nullptr) {
							temporary->setPrevious(temp);
						}
						temp->setNext(temporary);
						temp->setPrevious(pos_node);
						pos_node->setNext(temp);
					}
					size_++;
					return Iterator(head_,tail_, temp);
				}
				
				/**
				 * Insert a new element after the index pos.
				 * Should work with an empty list.
				 * 
				 * Should return an iterator pointing to the newly created node
				 * 
				 * To reduce repeated code, you may want to simply find
				 * 	an iterator to the node at the pos index, then
				 * 	send it to the other overload of this method.
				*/
				Iterator insert_after(size_t pos, const T& value)
				{
					//	TODO: Your code here
					T temp = value;
					Iterator posit = begin();
					for (size_t i = 0; i < pos; i++) {
						posit++;
					}
					return insert_after(posit,temp);
				}
				
				/**
				 * Erase the node pointed to by the Iterator's cursor.
				 * 
				 * If the 'pos' iterator does not point to a valid node,
				 * 	throw an std::range_error
				 * 
				 * Return an iterator to the node AFTER the one we erased,
				 * 	or this->end() if we just erased the tail
				 */
				Iterator erase(Iterator pos)
				{
					//	TODO: Your code here
					if (pos.getCursor() == nullptr) {
						throw std::range_error("Invalid Iterator");
					}
					Node* temp = pos.getCursor();
					Node* previous = temp->getPrevious();
					Node* next = temp->getNext();
					bool is_first = (temp == head_);
					bool is_last = (temp == tail_);
						if (is_first && is_last) {
							head_ = nullptr;
							tail_ = nullptr;
						} else if (is_first) {
							head_ = next;
							if (next != nullptr) {
								next->setPrevious(nullptr);
							} 
						} else if (is_last) {
							tail_ = previous;
							if (previous != nullptr) {
								previous->setNext(nullptr);
							}
						} else {
							if (previous != nullptr) {
								previous->setNext(next);
							}
							if (next != nullptr) {
								next->setPrevious(previous);
							}
						}
						delete temp;
						size_--;
					return Iterator(head_,tail_, next);
				}
				
				/**
				 * Add an element just after the one pointed to by the 'pos' iterator
				 * 
				 * Should return an iterator pointing to the newly created node
				 */
				Iterator push_after(Iterator pos, const T& value)
				{
					//	TODO: Your code here
					Node* new_node = new Node(value);
					Iterator temp_pos = pos;
					Node* temp = temp_pos.getCursor();

					if (size_ == 0) {
						new_node->setPrevious(nullptr);
						new_node->setNext(nullptr);
						tail_ = new_node;
						head_ = new_node;
					} else {
						new_node->setPrevious(nullptr);
						new_node->setNext(temp);
						temp->setPrevious(new_node);
					}
					size_++;
					
					return Iterator(head_, tail_, new_node); //come back
					//
				}
				
				/**
				 * Add a new element to the front of our list.
				 */
				void push_front(const T& value)
				{
					//	TODO: Your code here
					Node* new_node = new Node(value);
					Node* olde_head = head_;
					if (size_== 0) {
						tail_ = new_node;
					} else {
						olde_head->setPrevious(new_node);
					}

					new_node->setNext(olde_head);
					new_node->setPrevious(nullptr);
					head_ = new_node;
					size_++;
				}
				
				/**
				 * Add an element to the end of this list.
				 * 
				 * Should return an iterator pointing to the newly created node.
				 */
				Iterator push_back(const T& value)
				{
					//	TODO: Your code here
					Node* new_node = new Node(value);
					if (size_ == 0) {
						new_node->setPrevious(nullptr);
						new_node->setNext(nullptr);
						head_ = new_node;
					} else {
						Iterator temp = last();
						Node* temp_cursor = temp.getCursor();
						new_node->setNext(nullptr);
						new_node->setPrevious(temp_cursor);
						temp_cursor->setNext(new_node);
					}
					tail_ = new_node;
					Iterator product = last();					
					size_++;
					//std::cout << new_node << " " << new_node->getNext() << new_node->getPrev() << head_ << tail_;
					return product;
				}
				
				/**
				 * Remove the node at the front of our list
				 * 
				 * Should throw an exception if our list is empty
				 */
				void pop_front()
				{
					//	TODO: Your code here
					if (size_ == 0) {
						throw std::range_error("empty list");
					} else {
						Iterator temp = begin();
						erase(temp);
					}
				}
				
				/**
				 * Remove the node at the end of our list
				 * 
				 * Should throw an exception if our list is empty
				 */
				void pop_back()
				{
					//	TODO: Your code here
					if (size_ == 0) {
						throw std::range_error("empty list");
					} else {
						Iterator temp = last();
						erase(temp);
					}
				}
				
				/**
				 * Return a reference to the element at the front.
				 * 
				 * Throw an exception if the list is empty
				 */
				T& front()
				{
					//	TODO: Your code here
					if (size_ == 0) {
						throw std::range_error("empty list");
					}
					return head_->getElement();
				}
				
				/**
				 * Return a reference to the element at the back.
				 * 
				 * Throw an exception if the list is empty
				 */
				T& back()
				{
					//	TODO: Your code here
					if (size_ == 0) {
						throw std::range_error("empty list");
					}
					return tail_->getElement();
				}
				
				/**
				 * Return the element at an index
				 * 
				 * Should throw a range_error is out of bounds
				 */
				T& at(size_t index)
				{
					//	TODO: Your code here
					Iterator temp = begin();
					if (index > size_-1 || index < 0) {
						throw std::range_error("invalid Node");
					} else {
						for (size_t i = 0; i < index; i++) {
							temp++;
						}
					Node* temp_cursor = temp.getCursor();
					return temp_cursor->getElement();						
					}

				}
				
				/**
				 * Reverse the current list
				 * 
				 * It might be easy to consider the following:
				 * - Create a temp empty list
				 * - Iterate through the current list
				 * - For each item in the current list, push to the FRONT (not back)
				 * - Assign the current list to the temp list
				 * - Discard the temp list
				 */
				void reverse()
				{
					//	TODO: Your code here
					DoublyLinkedList<T>* temp = new DoublyLinkedList();
					size_t i = 0;
					while (i != size_)
					{
						temp->push_front(this->at(i));
						i++;
					}
					*this = *temp;
					delete temp;
				}
				
				/**
				 * I bet you're happy I'm not making you do this.
				 * No tests will be run against this function,
				 * 	but feel free to try it out, as a challenge!
				 * 
				 * If I were doing this and didn't care too much for efficiency,
				 * 	I would probably create an extra helper function to swap two
				 * 	positions in the current list.
				 * Then I would simply sweep through the list and perform
				 *  the bubble-sort algorithm. Perhaps selection sort.
				 * 
				 * If you want a huge challenge, try implementing quicksort.
				 * 
				 * (but again, don't worry about this method; it will not be tested)
				 */
				void sort()
				{
					//	TODO: Your code here
				}
				
				/**
				 * Assignment operator
				 * 
				 * Clear this list and fill it with the others' values
				 * (by value, not by reference)
				 * 
				 * Return a reference to this list
				 */
				DoublyLinkedList<T>& operator =(DoublyLinkedList<T>& other)
				{
					//	TODO: Your code here
					clear();
					for (size_t i = 0; i < other.size(); i++) {
						this->push_back(other.at(i));
					}
					return *this;
				}
				
				/**
				 * Return true if the lists are "equal"
				 * 
				 * "Equal" here is defined as:
				 * - Same size
				 * - Elements at the same indexes would return true for their own comparison operators
				 * 
				 * In other words: "They contain all the same values"
				 * (no need to be references to each other)
				 */
				bool operator ==(DoublyLinkedList<T>& other)
				{
					//	TODO: Your code here
					if (size_ == other.size()) {
						for (size_t i = 0; i < size_; i++) {
							if (other.at(i) != this->at(i)) {
								return false;
							}
						}
						return true;
					}
					return false;
				}
				
				/**
				 * Return true if the lists are "not equal"
				 * 
				 * See the operator== stub for definition of "equal"
				 * 
				 * Probably want to avoid repeated code by relying on the other operator
				 */
				bool operator !=(DoublyLinkedList<T>& other)
				{
					//	TODO: Your code here
					return !(this->operator==(other));
				}
				
			private:
				
				Node* head_ = nullptr;
				Node* tail_ = nullptr;
				size_t size_ = 0;
		};
	}
}

#endif

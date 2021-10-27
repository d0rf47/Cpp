/**************************************************/
/*                                                */
/*                                                */
/*                                                */
/*  Name:Michael                                  */
/*  Student number:143152189                      */
/*                                                */
/**************************************************/
#pragma once
/*
	Class: Stack
		--> a stack container class with an array underlying data structure
		--> capacity is the SIZE of the array
		--> used is the number of items currently in the array at any point in time
*/

/// <summary>
/// Stack Class
/// Grow(): Double the size of the underlying array --> called once array is full
///			--> amoritzes the growth rate 
/// Push(): Adds new item to the array
///			--> pushed to back for a reduced growth rate
/// Pop(): subtracts from used allowing index to be over written
/// Top(): Returns the newest item in the structure data_[used_-1]
/// </summary>
/// <typeparam name="T"></typeparam>

template <typename T>
class Stack {
	T* data_;
	unsigned int capacity_;
	unsigned int used_;

	void grow() {
		//double size of our array
		T* newArray = new T[capacity_ * 2];
		for (unsigned int i = 0; i < used_; i++) {
			newArray[i] = data_[i];
		}
		capacity_ = capacity_ * 2;
		delete[] data_;
		data_ = newArray;
	}
public:
	Stack(int capacity = 4) {
		data_ = new T[capacity];
		used_ = 0;
		capacity_ = capacity;
	}
	void push(const T& data) {
		if (used_ == capacity_)
			grow();
		data_[used_++] = data;
	}
	void pop() {
		used_--;
	}
	T top()const {
		return data_[used_ - 1];
	}
	bool isEmpty() {
		return used_ == 0;
	}
};
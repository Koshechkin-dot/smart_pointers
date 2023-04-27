#pragma once
#include "pointers.h"

//Using namespace for avoiding redefinition of any classes or methods
namespace smptr
{
	//So this my realization of unique_ptr which clears the memory after destroying.
	//Meaning of this name is simple - this pointer stores address of only one memory cell, and two this pointers can't point on same object/
	//This class templated, but i don't recommend to try use this pointer with any collections, because there are not any exceptions throwing and you program maybe fall into fatal error.
	template <typename T>
	class unique_ptr
	{
	public:

		//basic constructor
		unique_ptr() { ptr = nullptr; }

		//copied constructor
		unique_ptr(unique_ptr& other);

		//constructor on typename T object
		unique_ptr(T* obj) { ptr = obj; }
		
		//overload of operators = and *
		unique_ptr<T>& operator=(unique_ptr<T>& other);

		unique_ptr<T>& operator=(T* obj);

		T& operator*() { return *ptr; }

		//destructor
		~unique_ptr() { delete ptr; }

	private:

		//this field stores pointer on typename T memory address
		T* ptr;

	};



	template<typename T>
	unique_ptr<T>::unique_ptr(unique_ptr& other)
	{
		this->ptr = other.ptr;
		other.ptr = nullptr;
	}

	template<typename T>
	unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>& other)
	{
		if (ptr) delete ptr;
		this->ptr = other.ptr;
		other.ptr = nullptr;
		return *this;
	}

	template<typename T>
	unique_ptr<T>& unique_ptr<T>::operator=(T* obj)
	{
		if (ptr != obj)
		{
			delete ptr;
			ptr = obj;
		}
		return *this;
	}

}


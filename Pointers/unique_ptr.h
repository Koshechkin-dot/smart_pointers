#pragma once

//Using namespace for avoiding redefinition of any classes or methods
namespace smptr
{

	//So this my realization of unique_ptr which clears the memory after destroying.
	//Meaning of this name is simple - this pointer stores address of only one memory cell, and two this pointers can't point on same object
	//This class templated, but i don't recommend to try use this pointer with any collections, because there are not any exceptions throwing and you program maybe fall into fatal error.
	template <typename TYPE>
	class unique_ptr
	{
	public:

		//basic constructor
		unique_ptr();

		//copied constructor
		unique_ptr(unique_ptr<TYPE>&);

		//constructor on typename T object
		unique_ptr(TYPE*);
		
		//overload of operators = and *
		unique_ptr<TYPE>& operator=(unique_ptr<TYPE>&);

		unique_ptr<TYPE>& operator=(TYPE*);

		TYPE& operator*();

		//get() returns raw-pointer, so use carefully
		TYPE* get();

		//destructor
		~unique_ptr();

	private:

		//this field stores pointer on typename T memory address
		TYPE* ptr;

	};



	template<typename TYPE>
	inline unique_ptr<TYPE>::unique_ptr()
	{
		ptr = nullptr;
	}

	template<typename TYPE>
	inline unique_ptr<TYPE>::unique_ptr(unique_ptr<TYPE>& other)
	{
		this->ptr = other.ptr;
		other.ptr = nullptr;
	}

	template<typename TYPE>
	inline unique_ptr<TYPE>::unique_ptr(TYPE* obj)
	{
		ptr = obj;
	}

	template<typename TYPE>
	inline unique_ptr<TYPE>& unique_ptr<TYPE>::operator=(unique_ptr<TYPE>& other)
	{
		if (ptr) delete ptr;
		this->ptr = other.ptr;
		other.ptr = nullptr;
		return *this;
	}

	template<typename TYPE>
	inline unique_ptr<TYPE>& unique_ptr<TYPE>::operator=(TYPE* obj)
	{
		if (ptr != obj)
		{
			delete ptr;
			ptr = obj;
		}
		return *this;
	}

	template<typename TYPE>
	inline TYPE& unique_ptr<TYPE>::operator*()
	{
		return *ptr;
	}

	template<typename TYPE>
	inline TYPE* unique_ptr<TYPE>::get()
	{
		return ptr;
	}

	template<typename TYPE>
	inline unique_ptr<TYPE>::~unique_ptr()
	{
		delete ptr; 
	}

}


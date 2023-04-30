#pragma once

#ifndef _COLLECTION_PTR_H_
#define _COLLECTION_PTR_H_

namespace smptr
{

	typedef unsigned int uint_t;

	//This is my realization for collection types pointer, which clear memory after destroying
	//Each pointer stores only one collection
	template <typename CONTAINERTYPE>
	class collection_ptr
	{
	public:

		//basic constructor
		collection_ptr();

		//constructor on collection and size
		collection_ptr(CONTAINERTYPE*, uint_t);

		//copied constructor
		collection_ptr(collection_ptr<CONTAINERTYPE>&);

		//get() returns raw-pointer, so use carefully
		CONTAINERTYPE* get();

		//overload of operator*
		collection_ptr<CONTAINERTYPE>& operator*();

		//overload of operator[] so you can indexating pointer
		CONTAINERTYPE& operator[](uint_t);

		//destructor
		~collection_ptr();

	private:

		//fields for pointer and size of collection
		CONTAINERTYPE* ptr;
		int size;
	};

	template<typename CONTAINERTYPE>
	inline collection_ptr<CONTAINERTYPE>::collection_ptr()
	{
		ptr = nullptr;
		size = 0;
	}

	template<typename CONTAINERTYPE>
	inline collection_ptr<CONTAINERTYPE>::collection_ptr(CONTAINERTYPE* container, uint_t SIZE)
	{
		this->size = SIZE;
		ptr = container;
	}

	template<typename CONTAINERTYPE>
	inline collection_ptr<CONTAINERTYPE>::collection_ptr(collection_ptr<CONTAINERTYPE>& other)
	{
		this->size = other.size;
		this->ptr = other.ptr;
		other.size = 0;
		other.ptr = nullptr;
	}

	template<typename CONTAINERTYPE>
	inline collection_ptr<CONTAINERTYPE>::~collection_ptr()
	{
		delete[] ptr;
	}

	template<typename CONTAINERTYPE>
	inline CONTAINERTYPE* collection_ptr<CONTAINERTYPE>::get()
	{
		return ptr;
	}

	template<typename CONTAINERTYPE>
	inline collection_ptr<CONTAINERTYPE>& collection_ptr<CONTAINERTYPE>::operator*()
	{
		return *ptr;
	}

	template<typename CONTAINERTYPE>
	inline CONTAINERTYPE& collection_ptr<CONTAINERTYPE>::operator[](uint_t INDEX)
	{
		return *(ptr + INDEX);
	}
}

#endif // !_COLLECTION_PTR_H_





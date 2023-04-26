#pragma once
#include "pointers.h"

namespace smptr
{
	template <typename T>
	class smart_ptr
	{

	public:
		smart_ptr() { ptr = nullptr; }

		smart_ptr(const smart_ptr& other)
		{
			ptr = other.ptr ? new T(*other.ptr) : nullptr;
		}

		smart_ptr(T* obj) { ptr = obj; }

		smart_ptr<T>& operator=(const smart_ptr<T>& other);

		smart_ptr<T>& operator=(T* obj);

		T& operator*() { return *ptr; }

		~smart_ptr() { delete ptr; }

	private:

		T* ptr;

	};



	template<typename T>
	smart_ptr<T>& smart_ptr<T>::operator=(const smart_ptr<T>& other)
	{
		{
			if (this == &other) return *this;
			delete ptr;
			ptr = other.ptr ? new T(*other.ptr) : nullptr;
			return *this;
		}
	}

	template<typename T>
	smart_ptr<T>& smart_ptr<T>::operator=(T* obj)
	{
		if (ptr != obj)
		{
			delete ptr;
			ptr = obj;
		}
		return *this;
	}

}


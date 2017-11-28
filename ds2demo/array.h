#pragma once
#include <assert.h>


namespace dataStructures
{
	template<typename T>
	class Array
	{
	private:
		T* data{ nullptr };

	public:
		int length{ 0 };

		Array(int length)
		{
			assert(length > 0);

			data = new T[length];
			
			this->length = length;
		}

		~Array()
		{
			assert(data != nullptr);
			delete[] data;
		}

		T& operator[](int index)
		{
			assert(isIndexValid(index));
			return data[index];
		}

		operator T*()
		{
			return data;
		}

		bool isIndexValid(int index) const
		{
			return index >= 0 && index < length;
		}

		void insert(T item, int index)
		{
			
		}

		void remove(int index)
		{
			
		}

		void resize(int newLength)
		{
			
		}
	};
} // End of namespace dataStructures
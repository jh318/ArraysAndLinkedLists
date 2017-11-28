#pragma once


namespace dataStructures
{
	template<typename T>
	class ListNode
	{
	public:
		T data;
		ListNode<T>* next{ nullptr };

		ListNode<T>* insertAfter(T newData)
		{
			ListNode<T>* newNode = new ListNode<T>;
			newNode->data = newData;
			newNode->next = next;
			next = newNode;

			return newNode;
		}
	};

	template<typename T>
	class LinkedList
	{
	public:
		ListNode<T>* head{ nullptr };
		ListNode<T>* tail{ nullptr };
		int length{ 0 };

		~LinkedList()
		{
			ListNode<T>* current = head;

			while (current != nullptr)
			{
				ListNode<T>* nodeToDelete = current;
				current = current->next;
				delete nodeToDelete;
			}
		}

		void append(T data)
		{
			if (head == nullptr)
			{
				assert(length == 0);
				head = new ListNode<T>;
				head->data = data;
				tail = head;
			}
			else 
			{
				assert(tail != nullptr);
				tail->insertAfter(data);
				tail = tail->next;
			}

			++length;
		}

		void prepend(T data)
		{
			
		}

		void removeHead()
		{
		
		}

		void removeTail() 
		{
		
		}

	};

} // end of namespace dataStructures
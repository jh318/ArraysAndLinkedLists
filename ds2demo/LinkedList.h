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
			ListNode<T>* newNode = new ListNode<T>;
			newNode->data = data;
			newNode->next = head;

			if (tail == nullptr)
			{
				tail = head;
			}

			++length;
		}

		void removeHead()
		{
			ListNode<T>* node = nullptr;

			if (head != nullptr)
			{
				node = head->next;
				delete head;
				head = node;

				--length;
			}

			if (head == nullptr)
			{
				tail = nullptr;
			}
		}

		void removeTail() 
		{
			ListNode<T>* node = head;
			
			if (head != nullptr)
			{
				if (head == tail)
				{
					delete head;
					head = nullptr;
					tail = nullptr;
				}
				else
				{
					while (node->next != tail) 
					{
						node = node->next;
					}

					tail = node;
					delete node->next;
					node->next = nullptr;
				}

				--length;
			}

			if (head == nullptr)
			{
				tail = nullptr;
			}
		}

	};

	template<typename T>
	class Stack
	{
	public:
		ListNode<T>* head{ nullptr };
		ListNode<T>* tail{ nullptr };
		int length{ 0 };

		~Stack()
		{
			ListNode<T>* current = head;

			while (current != nullptr)
			{
				ListNode<T>* nodeToDelete = current;
				current = current->next;
				delete nodeToDelete;
			}
		}

		void push(T data) //prepend
		{
			ListNode<T>* newNode = new ListNode<T>;
			newNode->data = data;
			newNode->next = head;

			if (tail == nullptr)
			{
				tail = head;
			}

			++length;
		}

		void pop() //remove head
		{
			ListNode<T>* node = nullptr;

			if (head != nullptr)
			{
				node = head->next;
				delete head;
				head = node;

				--length;
			}

			if (head == nullptr)
			{
				tail = nullptr;
			}
		}

	};

	template<typename T>
	class Queue 
	{
	public:
		ListNode<T>* head{ nullptr };
		ListNode<T>* tail{ nullptr };
		int length{ 0 };

		~Queue()
		{
			ListNode<T>* current = head;

			while (current != nullptr)
			{
				ListNode<T>* nodeToDelete = current;
				current = current->next;
				delete nodeToDelete;
			}
		}

		void enqueue(T data) //append
		{
			if (head == nullptr)
			{
				assert(length == 0);
				head = new ListNode<T>;
				//std::cout << 
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

		void dequeue() //remove head
		{
			ListNode<T>* node = nullptr;

			if (head != nullptr)
			{
				node = head->next;
				delete head;
				head = node;

				--length;
			}

			if (head == nullptr)
			{
				tail = nullptr;
			}
		}
		
	};
} // end of namespace dataStructures
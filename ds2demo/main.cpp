#include <iostream>
#include "array.h"
#include "LinkedList.h"
using namespace dataStructures;
using namespace std;


int main() 
{
	LinkedList<int> numList;
	numList.append(100);
	numList.append(200);


	ListNode<int>* pNode = numList.head;


	while (pNode != nullptr)
	{
		cout << pNode->data << endl;
		pNode = pNode->next;
	}

}
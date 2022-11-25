#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
	{
		std::cout << "\t\t----- Tests with MutantStack() -----" << std::endl;
		MutantStack<int> mstack;
		std::cout << "\n --- push() with values: 6, 17, 21, 42 :" << std::endl;
		mstack.push(6);
		mstack.push(17);
		mstack.push(21);
		mstack.push(42);
		std::cout << "- Value at the top of the mstack is : " << mstack.top() << std::endl;
		std::cout << "- Size of the mstack is : " << mstack.size() <<  std::endl;
		std::cout << "- Remove first element of the mstack using pop() function." << std::endl;
		mstack.pop();
		std::cout << "- Size of the mstack is now : " << mstack.size() << std::endl;
		std::cout << "\n --- Iterators time !!! \\o/" << std::endl;
		std::cout << "- First, let's push more values : 0, 650, 21." << std::endl;
		mstack.push(0);
		mstack.push(650);
		mstack.push(21);
		MutantStack<int>::iterator	itStart = mstack.begin();
		MutantStack<int>::iterator	itEnd = mstack.end();
		std::cout << "mstack.begin() = " << *itStart << std::endl;
		std::cout << "- Displaying the content of the mstack from start to end: " << std::endl;
		while (itStart != itEnd)
		{
			std::cout << *itStart << "  ";
			++itStart;
		}
		std::cout << std::endl;
		std::cout << "- Test of empty() method : " << std::endl;
		std::cout << "Is mstack empty ? (return 1 if empty, 0 otherwise) " << mstack.empty() << std::endl;
		std::cout << "- Same test with an empty one: " << std::endl;
		MutantStack<int> emptyOne;
		std::cout << "Is stack empty ? (return 1 if empty, 0 otherwise) " << emptyOne.empty() << std::endl;
	}

	std::cout << std::endl;

	{
 		std::cout << "\t\t----- Sames tests with std::list -----" << std::endl;
		std::list<int> list1;
		std::cout << "\n --- push() with values: 6, 17, 21, 42 :" << std::endl;
		list1.push_back(6);
		list1.push_back(17);
		list1.push_back(21);
		list1.push_back(42);
		std::cout << "- Value at the top of the list1 is : " << list1.back() << std::endl;
		std::cout << "- Size of the list1 is : " << list1.size() <<  std::endl;
		std::cout << "- Remove first element of the list1 using pop() function." << std::endl;
		list1.pop_back();
		std::cout << "- Size of the list1 is now : " << list1.size() << std::endl;
		std::cout << "\n --- Iterators time !!! \\o/" << std::endl;
		std::cout << "- First, let's push more values : 0, 650, 21." << std::endl;
		list1.push_back(0);
		list1.push_back(650);
		list1.push_back(21);
		std::list<int>::iterator	itStart = list1.begin();
		std::list<int>::iterator	itEnd = list1.end();
		std::cout << "list1.begin() = " << *itStart << std::endl;
		std::cout << "- Displaying the content of the list1 from start to end: " << std::endl;
		while (itStart != itEnd)
		{
			std::cout << *itStart << "  ";
			++itStart;
		}
		std::cout << std::endl;
		std::cout << "- Test of empty() method : " << std::endl;
		std::cout << "Is list1 empty ? (return 1 if empty, 0 otherwise) " << list1.empty() << std::endl;
		std::cout << "- Same test with an empty one: " << std::endl;
		std::list<int> emptyOne;
		std::cout << "Is list1 empty ? (return 1 if empty, 0 otherwise) " << emptyOne.empty() << std::endl;
	}
    return 0;
}

/*
InputIterator is a useful but limited class of iterators. If iter is an InputIterator, you can use:

1. ++iter and iter++ to increment it, i.e., advance the pointer to the next element
2. *iter to dereference it, i.e., get the element pointed to
3. == and != to compare it another iterator (typically the "end" iterator)
*/

#include <iostream>
#include <vector>
#include <iterator>

int main() {
	std :: vector <int> myVector;
	std :: vector <int> :: iterator myIterator;
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	for(myIterator = myVector.begin() ; myIterator < myVector.end() ; myIterator++) {
		std :: cout << *(myIterator) << std :: endl;
	}
	return 0;
}

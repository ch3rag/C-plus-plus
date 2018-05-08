#include <iostream>
#include <vector>

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
#include <iostream>
#include <iterator>
#include <vector>

int main() {
	int array[] = {1, 2, 3, 4, 5};
	std :: ostream_iterator <int> outputStream (std :: cout , " ");
	//Adds a white space after every output operation
	std :: cout << "ARRAY : ";
	copy(array, array+5, outputStream);
	//prints array to screen

	//Using Containers
	std :: vector <int> myVector;
	myVector.push_back(10);
	myVector.push_back(20);
	myVector.push_back(30);
	std :: cout << std :: endl << "VECTOR : ";
	copy(myVector.begin(), myVector.end(), outputStream);
	//prints Vector to screen
	
	return 0;
}

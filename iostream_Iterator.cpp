#include <iostream>
#include <iterator>

int main() {
	std :: istream_iterator <int> Input (std :: cin);
	//Declaration Of An Input Stream Iterator
	int i = *Input;
	//Equivalent to cin >> i
	Input++;
	int j = *Input;
	//Equivalent to cin >> j
	std :: ostream_iterator <int> Output (std :: cout);
	//Declaration Of An Output Stream Iterator
	int sum = i + j;
	*(Output) = sum;
	//Equivalent to cout << sum
	return 0;
}
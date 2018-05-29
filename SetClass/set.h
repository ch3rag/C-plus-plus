#ifndef set_h_
#define set_h_

#include <iostream>
#include <list>
#include <iterator>

template <typename T>
class Set {
		std :: list <T> setList;
		int length;
	public :
		Set(std :: initializer_list <T> l) {
			setList = l;
			setList.sort();
			T elem = setList.front();
			typename std :: list <T> :: iterator i;
			bool found = true;
			for(i = setList.begin() ; i != setList.end() ;) {
				if(elem != *(i) || found) {
					found = false;
					elem = *(i);
					i++;
				} else {
					setList.erase(i++);
				}
			}
			length = setList.size();
		} 
		
		Set() {
			length = 0;
		}

		void printSet() {
			typename std :: list <T> :: iterator i;
			std :: cout << "{";
			for(i = setList.begin() ; i != setList.end() ; i++) {
				std :: cout << " " << *(i);
			}
			std :: cout << " }";
		}


};


#endif 

//IMPLEMENTATION OF SETS IN C++

#ifndef set_h_
#define set_h_

#include <iostream>
#include <list>
#include <iterator>
#include <assert.h>

template <typename T>
class Set {
		std :: list <T> setList;
	public :
		Set(std :: initializer_list <T> l) {
			setList = l;
			setList.sort();
			T elem = setList.front();
			typename std :: list <T> :: iterator i = setList.begin();
			i++;
			while (i != setList.end()) {
				if(elem != *(i)) {
					elem = *(i);
					i++;
				} else {
					setList.erase(i++);
				}
			}
		}
		
		Set() {
		}

		void printSet() {
			typename std :: list <T> :: iterator i;
			std :: cout << "{";
			for(i = setList.begin() ; i != setList.end() ; i++) {
				std :: cout << " " << *(i);
			}
			std :: cout << " }";
		}

		void add(T elem) {

			typename std :: list <T> :: iterator i ;
			for(i = setList.begin() ; i != setList.end() ; i++) {
				if(elem == *(i)) {
					return;
				}
			}

			setList.push_back(elem);
		}

		void remove(T elem) {
			typename std :: list <T> :: iterator i ;
			for(i = setList.begin() ; i != setList.end() ; i++) {
				if(elem == *(i)) {
					setList.erase(i++);
					return;
				}
			}
		}

		T pop() {
			assert(setList.size() > 0);
			T elem = setList.front();
			setList.pop_front();
			return elem;
		}

		int getLength() {
			return setList.size();
		}
};
#endif 

//Pirority Queue
//Based On Age Of People

#include <iostream>
#include <vector>
#include <queue>

class Person {

	std :: string name;
	int age;

	public  : bool operator < (const Person & other ) const {

		return (this->age < other.age);

	} 

	Person(std :: string name, int age) {
		this->name = name;
		this->age  = age;
	}

	int getAge() {
		return age;
	}

	std :: string getName() {
		return name;
	}
};


int main() {
	std :: priority_queue <Person, std :: vector <Person>, std :: less<Person> > pq;

	Person p1("David", 18);
	Person p2("John", 15);
	Person p3("Robert", 20);
	Person p4("Gary", 17);
	Person p5("Peter", 10);

	//Insert

	pq.push(p1);
	pq.push(p2);
	pq.push(p3);
	pq.push(p4);
	pq.push(p5);

	//POP

	for(int i = 0 ; i < 5 ; i++) {
		Person temp = pq.top();
		std :: cout << "Name : " << temp.getName() << " " << "Age : " << temp.getAge() << std :: endl;
		pq.pop(); 
	}
}

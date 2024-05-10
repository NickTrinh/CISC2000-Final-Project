#ifndef NAME_H
#define NAME_H

#include <string>
using namespace std;

class Name {
	private:
		string firstName;
		string lastName;

	public:
		Name();
		Name(string fullName);

		void setFirstName(string firstName);
		void setLastName(string lastName);
		string getFirstName() const;
		string getLastName() const;
		void printName() const;
};

#endif


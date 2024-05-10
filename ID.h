//Nick Trinh
#ifndef ID_H
#define ID_H

#include <string>
using namespace std;

class ID{
	private:
		int ID_number;
		string full_ID;
	
	public:
		ID();
		int getIDNumber() const;
		void setIDNumber(int newIDNumber);

		string getFullID() const;
		void setFullID(string newFullID);
};

#endif

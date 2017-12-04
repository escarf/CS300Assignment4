/*
 * Contact.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: escarf
 */

#include "Contact.h"
#include <iostream>
using namespace std;

Contact::Contact() {

	fName = "none";
	lName = "none";
	num = 0;
}
Contact::Contact(string f, string l, int num) {

	Contact:: fName = f;
	Contact:: lName = l;
	Contact:: num = num;

}

Contact::~Contact() {

}

void fPrint(Contact &con) {

	if(con.num == 0) {
		cout<<" "<<endl;
	}
	else {
		cout<< con.fName<<" "<<con.lName<<" "<< con.num<<endl;
	}
}

bool Contact::operator==(const Contact& other) const {
	return ( (fName == other.fName) && (lName == other.lName) );
}

bool Contact::operator<(const Contact& other) const {
	string s1 = fName + lName;
	string s2 = other.fName + other.lName;

	// this Contact's name is earlier in the alphabet, so return true
	if( ((s1).compare(s2) < 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

bool Contact::operator >(const Contact& other) const {
	string s1 = fName + lName;
	string s2 = other.fName + other.lName;

	// this Contact's name is later in the alphabet, so return true
	if(((s1).compare(s2) > 0)) {
		return 1;
	}
	else {
		return 0;
	}

}

string Contact::getFirst() {
	return this->fName;
}

string Contact::getLast() {
	return this->lName;
}


int Contact::getNum() {
	return this->num;
}

void Contact::del() {
	fName = "";
	lName = "";
	num = 0; // 0 is the number for a "deleted" Contact

}

ostream& operator<<(ostream& os, const Contact& c)
{
	string f = c.fName;
    os << c.fName << " " << c.lName << " " << c.num <<endl;

    return os;
}


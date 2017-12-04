//============================================================================
// Name        : CS300Assignment4.cpp
// Author      : Ephraim Scarf
// Description :
//============================================================================

#include <iostream>
#include <fstream>
#include <ctime>
#include "Contact.h"
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BinarySearchTree<Contact> book;
	bool quit = 0; // false while the user hasn't selected quit

	while(!quit) {
		char choice; // which of the options below is chosen

		cout << "***MY PHONEBOOK APPLICATION***" << endl;
		cout << "Please choose an operation:" << endl;
		cout <<"A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit): ";

		cin >> choice;

		if( (choice == 'A') || (choice == 'a') ) {
			string firstName;
			string lastName;
			int number;

			cout<<"Enter name to add: "<< endl;
			cin>> firstName;
			cin>> lastName;
			cout<<"Enter number: "<< endl;
			cin>> number;

			Contact temp(firstName, lastName, number);
			book.insert(temp);
			cout<<"Contact added "<< endl;

		}

		else if((choice == 'L') || (choice == 'l')) {

			string firstName;
			string lastName;
			int phoneNum;

			string fileName;
			ifstream infile; // parses over phonebook.txt for filling the tree
			ofstream outfile; // for adding back into original file

			cout<<"Enter file name: "<<endl;
			cin>>fileName;
			infile.open(fileName);


			//reads contacts from file, adds to tree
			while(!infile.eof()) {

				infile >> firstName;
				infile >> lastName;
				infile >> phoneNum;

				Contact temp(firstName, lastName, phoneNum);
				book.insert(temp);

			}

			infile.close();
			outfile.open(fileName);
		}

		else if((choice == 'S') || (choice == 's')) {

			string firstName;
			string lastName;
			cout<<"Enter name to search for: "<< endl;

			cin>> firstName;
			cin>> lastName;
			Contact temp(firstName, lastName, 0);

			//loop to get multiple trials
			for(int i = 0; i < 6; i++) {
				clock_t begin = clock();

				//loop to emphasize the time difference between BST and array implementation
				//for(int i = 0; i < 1000; i++) {
					temp = book.searchReturn(temp);
				 //}

				clock_t end = clock();

				// temp.getNum() is 0 if temp's first and last name are NOT found in the tree
				if(temp.getNum() == 0) {
					cout<<"Not found"<<endl;
				}


				// found
				else {
					cout<<"Number: "<< temp.getNum() << endl;
				}

				cout<< "trial "<< i+1 << ": ";
				double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
				cout<<"time: "<<elapsed_secs<<endl;
			}
		}

		else if((choice == 'P') || (choice == 'p')) {
			int result = book.inOrder();
			cout << "Number of Contacts: " << result << endl;

		}

		else if((choice == 'F') || (choice == 'f')) {
			string firstName;
			string lastName;
			cout<<"Enter name: "<< endl;

			cin>> firstName;
			cin>> lastName;
			Contact temp(firstName, lastName, 0);
			int result = book.inOrderT(temp);
			cout << "Number of Contacts: " << result << endl;
		}

		else if((choice == 'Q') || (choice == 'q')) {
			quit = 1;
			cout<<"bye"<<endl;
		}

		else {
			cout<<"Unrecognized input: try again"<< endl;
		}

	}

	return 0;
}

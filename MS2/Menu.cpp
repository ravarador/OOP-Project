/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author:	Jexequiel Ravni Arador
Date: November 15, 2021
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include<iomanip>
#include <iostream>
#include <cstring>

#include"Menu.h"

using namespace std;

namespace sdds {
	// MENU ITEM

	// Constructor
	MenuItem::MenuItem() {
		m_content = nullptr;
	};

	MenuItem::MenuItem(const char* content) {
		delete[] m_content;
		m_content = nullptr;

		m_content = new char[strlen(content) + 1];
		strcpy(m_content, content);
	};

	// Destructor
	MenuItem::~MenuItem() {
		delete[] m_content;
		m_content = nullptr;
	};

	// bool type conversion
	MenuItem::operator bool() const {
		return m_content != nullptr;
	};

	// displaying the MenuItem
	void MenuItem::display() {
		cout << m_content;
	};

	// MENU ITEM END

	// MENU START

	// Constructors
	Menu::Menu() {
		m_title = nullptr;
		m_NoOfItems = 0;
	};

	Menu::Menu(const char* title) {
		delete[] m_title;
		m_title = nullptr;

		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
	};

	// Destructor
	Menu::~Menu() {
		delete[] this->m_title;
		m_title = nullptr;

		// Looping through the MenuItems array of pointers, it deletes each pointer up to the number of menu items in the menu.
		for (int i = 0; i < m_NoOfItems; i++) {
			delete m_items[i];
			m_items[i] = nullptr;
		}
	};

	// Suggestion: create a function to display the title of the Menu on ostream
	void Menu::display() {
		if (m_title != nullptr) {
			cout << m_title
				<< endl;
		}


		for (int i = 0; i < m_NoOfItems; i++) {
			cout << " " << i + 1
				<< "- "
				<< m_items[i]->m_content
				<< endl;
		}


		cout << " 0- Exit" << endl << "> ";
	};

	// Create a member function called run.
	// The function receives nothing and returns an unsigned integer (That is the user’s selection). 
	unsigned int Menu::run() {
		// This function displays the Menu and gets the user selection.
		display();

		int num;
		while (true)
		{
			cin >> num;
			if (!cin || num < 0 || num > m_NoOfItems)
			{
				cout << "Invalid Selection, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			else break;
		}

		return static_cast<unsigned int>(num);
	};

	// Overload operator~ to do exactly what the run function does
	unsigned int Menu::operator~() {
		return run();
	};

	// Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
	Menu& Menu::operator<<(const char* menuitemConent) {
		m_items[m_NoOfItems] = new MenuItem(menuitemConent);
		m_NoOfItems++;

		return (*this);
	};

	// Overload two type conversions for int and unsigned int to return the number of MenuItems on the 
	Menu::operator int()const {
		// return the number of MenuItems on the Menu
		return m_NoOfItems;
	};

	Menu::operator unsigned int()const {
		// return the number of MenuItems on the Menu
		return m_NoOfItems;
	};

	// Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
	Menu::operator bool()const {
		return m_title != nullptr;
	};

	// Overload the insertion operator to print the title of the Menu using cout.
	ostream& operator<<(ostream& os, const Menu& RO) {
		return RO.write(os);
	};

	// Overload the indexing operator to return the const char*
	char* Menu::operator[](int index) const {
		return m_items[index]->m_content;
	};

	// EXTRAS 
	ostream& Menu::write(std::ostream& os)const
	{
		if (m_title != nullptr) {
			os << m_title;
		}

		return os;
	}

	// MENU END
}


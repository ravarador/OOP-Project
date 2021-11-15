/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author:	Jexequiel Ravni Arador
Date: November 15, 2021
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>  

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem {
	private:
		char* m_content{};

		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		operator bool() const;
		void display();
		friend class Menu;
	};

	class Menu {
		MenuItem* m_items[MAX_MENU_ITEMS]{};
		int m_NoOfItems = 0;
	public:
		char* m_title{};
		

	public:
		// Constructors
		Menu();
		Menu(const char*);

		// Destructor
		~Menu();

		// Suggestion: create a function to display the title of the Menu on ostream
		void display();

		// Create a member function called run.
		// The function receives nothing and returns an unsigned integer (That is the user’s selection). 
		unsigned int run();

		// Overload operator~ to do exactly what the run function does
		unsigned int operator~();

		// Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
		Menu& operator<<(const char* menuitemConent);

		// Overload two type conversions for int and unsigned int to return the number of MenuItems on the 
		operator int()const;
		operator unsigned int()const;

		// Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
		operator bool()const;

		// Overload the indexing operator to return the const char*
		char* operator[](int index)const;

		// EXTRAS
		std::ostream& write(std::ostream& os)const;
	};

	// Overload the insertion operator to print the title of the Menu using cout.
	std::ostream& operator<<(std::ostream& os, const Menu& RO);
};

#endif // SDDS_MENU_H__
/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.h
Version 1.0
Author:	Jexequiel Ravni Arador
Date: November 15, 2021
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"

namespace sdds {
   class LibApp {
       bool m_changed; // A flag to keep track of changes made to the application data.
       Menu m_mainMenu;
       Menu m_exitMenu;

       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */
       void newPublication();
       void removePublication();
       void checkOutPub();

       void exitMessage();

       friend class Menu;

   public:
       void run();

       // CONSTRUCTOR
       LibApp();
   };
}
#endif // !SDDS_LIBAPP_H




/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author:	Jexequiel Ravni Arador
Date: November 15, 2021
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>  
#include <cstring>
#include "LibApp.h"

using namespace std;

namespace sdds {
    // CONSTRUCTOR
    LibApp::LibApp() {
        // Initializes the attributes (see the attribute section)
        // populates the Menu attributes
        /*      
        Menu mainMenu("Seneca Libray Application");

        if (mainMenu) {
            mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
            this->m_mainMenu = mainMenu;
        }
        
        Menu exitMenu("Changes have been made to the data, what would you like to do?");

        if (exitMenu) {
            exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
            this->m_exitMenu = exitMenu;
        }
        */
        const char title[] = "Seneca Library Application";

        m_mainMenu.m_title = new char[strlen(title) + 1];

        strcpy(m_mainMenu.m_title, title);

        if (m_mainMenu) {
            m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        }

        const char exitTitle[] = "Changes have been made to the data, what would you like to do?";

        m_exitMenu.m_title = new char[strlen(exitTitle) + 1];

        strcpy(m_exitMenu.m_title, exitTitle);

        if (m_exitMenu) {
            m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        }

        this->m_changed = 0;

        load();
    }

    bool LibApp::confirm(const char* message) {
        // Instantiate a Menu in this function and initialize it with the message argument.
        Menu confirmMenu(message);

        // Then add only a "yes" as a single menu item to the Menu.
        confirmMenu << "Yes";

        // Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.
        return confirmMenu.run() == 1 ? true : false;
    }

    void LibApp::load() {
        // prints: "Loading Data"<NEWLINE>
        cout << "Loading Data" << endl; 
    } 

    void LibApp::save() {
        // prints: "Saving Data"<NEWLINE>
        cout << "Saving Data" << endl; 
        //m_changed = false;
    } 

    void LibApp::search() {
        // prints: "Searching for publication"<NEWLINE>
        cout << "Searching for publication" << endl; 
    }

    void LibApp::returnPub() {
        // Calls the search() method.
        search();

        // prints "Returning publication"<NEWLINE>
        cout << "Returning publication" << endl;

        // prints "Publication returned"<NEWLINE>
        cout << "Publication returned" << endl;

        // sets m_changed to true;
        m_changed = true;
    }

    void LibApp::newPublication() {
        // prints "Adding new publication to library"+newline
        cout << "Adding new publication to library" << endl;

        // calls the confirm method with "Add this publication to library?"
        if (confirm("Add this publication to library?")) {
            // if confrim returns true, it will set m_changed to true and prints "Publication added" + newline
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication() {
        // prints "Removing publication from library"+newline
        cout << "Removing publication from library" << endl;

        // calls the search method
        search();

        // calls the confirm method with "Remove this publication from the library?"
        if (confirm("Remove this publication from the library?")) {
            // if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub() {
        // calls the search method
        search();
        
        // calls the confirm method with "Check out publication?"
        if (confirm("Check out publication?")) {
            // if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
    }

    void LibApp::run() {
        // It displays the main menuand based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
        unsigned int choice = -1;
        while ((choice = this->m_mainMenu.run())) {
            switch (choice) {
            case 1:
                this->newPublication();
                break;
            case 2:
                this->removePublication();
                break;
            case 3:
                this->checkOutPub();
                break;
            case 4:
                this->returnPub();
                break;
            }

            cout << endl;
        }

        // When the user selects exit, the value of m_changed is examined. If the value is false, then since the data of the application is not modified, the program terminates.
        if (this->m_changed) {
            // If the value is true, the m_exitMenu is used by calling its run method. Doing so the user has the selection of saving and exiting, 
            // cancelling and going back to the main menu or exiting without saving.
            unsigned int exitChoice = -1;
            switch ((exitChoice = this->m_exitMenu.run())) {
            case 1:
                // If the first one is selected, the save() method is called and the program terminates.
                save();
                exitMessage();
                break;
            case 2:
                // If the second one is selected the program goes back to the main menu and execution continues.
                cout << endl;
                //this->m_mainMenu.run();
                run();
                break;
            case 0:
                // If the exit is selected, then the confirm menu will be called using the message: "This will discard all the changes are you sure?". 
                if (confirm("This will discard all the changes are you sure?")) {
                    // If the user selects Yes, the program terminates. Otherwise, the program goes back to the main menu and execution resumes.
                    exitMessage();
                }
                else {
                    //this->m_mainMenu.run();
                    run();
                }
            }
        }
        else {
            exitMessage();
        }
    }

    void LibApp::exitMessage() {
        cout << "\n-------------------------------------------" << endl
            << "Thanks for using Seneca Library Application\n";
    }

}

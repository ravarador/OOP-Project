/* Citation and Sources...
Final Project Milestone 3
Module: Lib
Filename: Lib.h
Version 1.0
Author:	Jexequiel Ravni Arador
Date: November 22, 2021
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_LIB_H
#define SDDS_LIB_H

namespace sdds {
    const int SDDS_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_LIBRARY_CAPACITY = 5000;
    // Maximum number of publications the library can hold.
}

#endif
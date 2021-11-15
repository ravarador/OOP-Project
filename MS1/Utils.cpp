/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <ctype.h>
#include "Utils.h"

using namespace std;

namespace sdds {
	bool isInt(const char s[]) {
		bool res = true;
		for (int i = 0; s[i] != '\0' && res; i++) {
			if (!isdigit(s[i])) {
				res = false;
			}
		}

		return res;
	}
}
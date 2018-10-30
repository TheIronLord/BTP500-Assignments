// Bank ATM.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "ATM.h"


int main()
{
    ATM abunch[15];
    for (int i = 0; i < 15; i++){
        abunch[i] = ATM();
    }
    return 0;
}


//ATM.h
 #include "stdafx.h"
 #ifndef atm
#define atm
class ATM {
    static int accountID;

public:
    ATM();
};
int ATM::accountID = 0;
#endif


//ATM.cpp
#include "stdafx.h"
#include "ATM.h"
#include <iostream>
ATM::ATM() {
    ++accountID;
    std::cout << accountID;
}
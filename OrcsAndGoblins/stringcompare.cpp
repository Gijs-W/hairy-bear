//
//  main.cpp
//  stringcompare
//
//  Created by Bob Polis on 26/09/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    /*
     std::strings vergelijken gaat simpeler dan in Java.
     
     Je mag gewoon == gebruiken, want de operator==() is correct geïmplenteerd hiervoor. Dit test dus object equivalentie.
     
     Als je in plaats hiervan object identiteit wil vergelijken (hebben we hetzelfde exemplaar) kun je dat
     in C++ heel eenvoudig oplossen: dan vergelijk je de adressen (pointers). Die zijn alleen gelijk
     wanneer ze naar dezelfde instantie wijzen.
     */
    
    string naam1("Jan");
    string naam2("Marie");
    string naam3("Marie");
    
    if (naam1 == naam2) {
        cout << "naam1 is hetzelfde als naam2\n";
    } else {
        cout << "naam1 en naam2 zijn verschillend.\n";
    }
    
    if (naam2 == naam3) {
        cout << "naam2 is hetzelfde als naam3\n";
    } else {
        cout << "naam2 en naam3 zijn verschillend.\n";
    }
    
    return 0;
}

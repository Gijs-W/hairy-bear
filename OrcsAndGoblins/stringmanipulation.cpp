//
//  stringmanipulation.cpp
//
//  Created by Bob Polis on 17/09/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[])
{
    /*
     Strings in C++ doen we liefst met std::string, een klasse die uitgebreide stringmanipulatie mogelijk maakt.
     Hieronder een paar voorbeelden van veel voorkomende zaken.
     Kijk ook beslist op: http://en.cppreference.com/w/cpp/string
     */
    
    // (1) strings aan elkaar plakken (concatenatie)
    string s1("Real programmers ");
    s1 += "do C++";
    cout << s1 << '\n';
    
    // (2) substrings: gebruik string-methode substr()
    cout << s1.substr(5, 11) << '\n'; // toont: programmers
    
    // (3a) individuele karakters benaderen met at()
    cout << s1.at(0) << '\n'; // toont: R
    
    // (3b) individuele karakters benaderen met array-syntax: []
    cout << s1[20] << '\n'; // toont: C
    
    /*
     Verschil tussen at() en []:
     at() controleert grenzen, [] niet
     */
//    cout << s1.at(23) << '\n'; // genereert index out-of-range exception
//    cout << s1[23] << '\n'; // doet vrolijk buffer overflow! (als je geluk hebt, crasht het meteen... maar meestal pas later)
    
    // (4a) zoeken
    string::size_type pos = s1.find("p"); // let op: gebruik altijd het juiste type voor pos, dus géén int!
    cout << "found 'p' at index " << pos << '\n';
    
    // (4b) zoeken maar niet vinden: pos == string::npos
    pos = s1.find("x");
    cout << pos << '\n';
    cout << "x " << (pos == string::npos ? "niet " : "") << "gevonden" << '\n';
    
    /*
     Tip: bekijk de reference http://en.cppreference.com/w/cpp/string/basic_string voor wat er allemaal kan.
     Je kunt ook reguliere expressions gebruiken met de regex library, zie: http://en.cppreference.com/w/cpp/regex
     We gaan in CPPLS2 ook kijken naar andere onderdelen van de standard library die nog leuke dingen
     met strings kunnen doen, met name algorithms.
     */
    
    return 0;
}

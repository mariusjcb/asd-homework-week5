//
//  StackView.h
//  ASD Tema 5
//
//  Created by Marius Ilie on 02/01/17.
//  Copyright © 2017 University of Bucharest - Marius Ilie. All rights reserved.
//

#ifndef StackView_h
#define StackView_h

#include <stdlib.h>
#include <iostream>
#include "StackModel.h"

using namespace std;

template <class T>
class StackView {
public:
    static void printIndex(int index) {
        cout << "stack[" << index << "]: ";
    }
    
    static void printValue(T value) {
        cout << value << "\n";
    }
    
    static void printElement(int index, T value) {
        printIndex(index);
        printValue(value);
    }
};

void showErrorClosure(string message) {
    cout << "\n\n╔══════════════════════════════╗\n";
    cout << "║                              ║\n";
    cout << "║ (!) ERROR: " << message << "  ║\n";
    cout << "║                              ║\n";
    cout << "╚══════════════════════════════╝\n\n\n";
}

void showMessage(string message) {
    cout << "\n\n╔══════════════════════════════╗\n\n";
    cout << "         " << message << "       \n\n";
    cout << "╚══════════════════════════════╝\n\n\n";
}

#endif /* StackView_h */

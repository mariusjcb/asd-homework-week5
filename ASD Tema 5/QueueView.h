//
//  QueueView.h
//  ASD Tema 5
//
//  Created by Marius Ilie on 02/01/17.
//  Copyright © 2017 University of Bucharest - Marius Ilie. All rights reserved.
//

#ifndef QueueView_h
#define QueueView_h

#include <iostream>
#include "QueueModel.h"
using namespace std;

template <class T>
class QueueView {
public:
    static void printIndex(int index) {
        cout << "queue[" << index << "]: ";
    }
    
    static void printValue(T value) {
        cout << value << "\n";
    }
    
    static void printElement(int index, T value) {
        printIndex(index);
        printValue(value);
    }
};

#endif /* QueueView_h */

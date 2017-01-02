//
//  main.cpp
//  ASD Tema 5
//
//  Created by Marius Ilie on 02/01/17.
//  Copyright © 2017 University of Bucharest - Marius Ilie. All rights reserved.
//

#include "Queue.h"

int main(int argc, const char * argv[]) {
#pragma mark COADA
    
    Queue<double> coada = *new Queue<double>();
    
    coada.push(-2.4);
    coada.push(2);
    coada.push(3);
    coada.push(1.2);
    coada.push(2.1);
    coada.push(8);
    coada.push(3.7);
    coada.push(74);
    
    coada.afiseaza();
    while(coada.pop().isSet());
    
    
#pragma mark: - STIVA
    
    Stack<float> stiva = *new Stack<float>();
    
    stiva.push(1.2);
    stiva.push(2.1);
    stiva.push(3);
    stiva.push(3.7);
    stiva.push(7);
    
    stiva.afiseaza();
    
    while(coada.pop().isSet());
    cout << "\n\n";
    
    return 0;
}

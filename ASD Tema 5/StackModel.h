//
//  StackModel.h
//  ASD Tema 5
//
//  Created by Marius Ilie on 02/01/17.
//  Copyright © 2017 University of Bucharest - Marius Ilie. All rights reserved.
//

#ifndef StackModel_h
#define StackModel_h

#include <string>
#include <functional>
#include "OptionalType.h"

using namespace std;

template <class T>
class StackModel
{
protected:
    struct StackNode
    {
        T value;
        StackNode *back;
        StackNode *next;
    };
    
    StackNode *top;
    StackNode *bottom;
    
public:
    class ForEach {
    private:
        StackModel *parent;
        
    public:
        ForEach() {
            parent = NULL;
        }
        
        ForEach(StackModel *parent) {
            this->parent = parent;
        }
        
        void elements(function<void (int, StackNode*)> eventClosure, bool reversed = false) {
            StackNode *currentNode, *nextOne;
            
            if(reversed) currentNode = parent->bottom;
            else currentNode = parent->top;
            
            int index = 0;
            while (currentNode)
            {
                eventClosure(index++, currentNode);
                
                if(reversed)
                    nextOne = currentNode->back;
                else nextOne = currentNode->next;
                
                currentNode = nextOne;
            }
        }
        
        void values(function<void (int, T)> eventClosure, bool reversed = false) {
            StackNode *currentNode, *nextOne;
            
            if(reversed) currentNode = parent->bottom;
            else currentNode = parent->top;
            
            int index = 0;
            while (currentNode)
            {
                eventClosure(index++, currentNode->value);
                
                if(reversed)
                    nextOne = currentNode->back;
                else nextOne = currentNode->next;
                
                currentNode = nextOne;
            }
        }
    };
    
    ForEach forEach;
    
    static void deleteNode(int index, StackNode *node) {
        delete node;
    }
    
    T getLast() {
        return bottom->value;
    }
    
    StackModel()
    {
        forEach = *new ForEach(this);
        bottom = top = 0;
    }
    
    ~StackModel() {
        forEach.elements(deleteNode);
    }
    
    bool isEmpty() {
        if(!top) return true;
        else return false;
    }
    
    void push(T value) {
        StackNode *newNode;
        
        newNode = new StackNode;
        newNode->value = value;
        
        if (isEmpty())
        {
            newNode->back = 0;
            newNode->next = 0;
            bottom = top = newNode;
        }
        else
        {
            newNode->next = top;
            top->back = newNode;
            
            top = newNode;
        }
    }
    
    virtual Optional<T> pop(function<void (string)> eventClosure) {
        StackNode *nextTop;
        Optional<T> optionalValue;
        
        if (isEmpty())
        {
            eventClosure("STIVA ESTE GOALA");
        }
        else
        {
            optionalValue = top->value;
            
            nextTop = top->next;
            delete top;
            top = nextTop;
        }
        
        return optionalValue;
    }
    
    virtual Optional<T> peek(function<void (string)> eventClosure) {
        Optional<T> optionalValue;
        
        if(isEmpty()) {
            eventClosure("STIVA ESTE GOALA");
        } else {
            optionalValue = top->value;
        }
        
        return optionalValue;
    }
    
    Optional<int> search(T value, bool reversed = false) {
        int index = -1;
        
        function<void (int, T)> fct = [&] (int elementIndex, T elementValue) -> void {
            if(value == elementValue) {
                index = elementIndex;
            }
        };
        
        this->forEach.values(fct, reversed);
        return index;
    }
};

#endif /* StackModel_h */

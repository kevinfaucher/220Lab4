/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SLL.cpp
 * Author: Kevin
 * 
 * Created on April 2, 2017, 3:06 PM
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

SLL::SLL() {
    first = NULL;
    last = p2->next;
    p2 = first->next;
    size = 0;
}

SLL::~SLL() {
    SNode *tmp = first;
    while (tmp->next != NULL) {
        SNode * tmp2 = tmp->next;
        tmp->~SNode();
        tmp = tmp2;
        delete[] tmp2;
        size--;
    }
    delete [] tmp;
    size--;
}

void SLL::printSLL() {
    SNode *tmp = first;

    while (tmp->priority == 1 || tmp->priority == 2 || tmp->priority == 3) {
        if (tmp->priority == 1) {
            cout << "Priority 1: " << endl << tmp->word << ":" << tmp->priority << ", " << endl;
            tmp = tmp->next;
        } else if (tmp->priority == 2) {
            cout << "Priority 2: " << endl << tmp->word << ":" << tmp->priority << ", " << endl;
            tmp = tmp->next;

        } else if (tmp->priority == 3)
            cout << "Priority 3: " << endl << tmp->word << ":" << tmp->priority << ", " << endl;

            tmp = tmp->next;
    }
    cout << endl << endl;
}

void SLL::priorityInsert(string s, int p) {
    SNode *tmp = new SNode(s, p);
    if (p == 1) {
        addAtFront(tmp);
    } else if (p == 2) {
        tmp->next = p2->next;
        p2->next = tmp;
        p2 = tmp;
        size++;
    } else if (p == 3) {
        push(tmp);
    }
}

void SLL::push(SNode *n) {
    //pushes n onto the end of the stack
    last->next = n;
    n->next = NULL;
    last = n;
    size++;
}

void SLL::addAtFront(SNode *n) {
    n->next = first;
    first = n;
    size++;
}
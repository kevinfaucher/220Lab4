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

SLL::SLL(){
	first = NULL;
	last = NULL;
        size = 0;
}

void SLL::printSLL() {
	SNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->word << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

void SLL::push(int x) { //6 pts

//add a new node to the end of the list, with data x
	SNode *node = new SNode(x);
	last->next = node;
	last = node;
	size ++;


}

void SLL::addAtFront(int x) {  //3 pts
    //add a new node to the front of the list with data being x
	SNode *node = new SNode(x);
	node->next = first;
	first = node;
    size ++;
}

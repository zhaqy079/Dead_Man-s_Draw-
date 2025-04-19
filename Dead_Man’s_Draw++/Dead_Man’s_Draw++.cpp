// Dead_Man’s_Draw++.cpp : Defines the entry point for the application.
//

#include "Dead_Man’s_Draw++.h"
#include "Cards/MermaidCard.h"
#include <iostream>
#include <vector>

const std::vector<int> testValues = { 2,3,4,5,6,7 };

int main()
{
    for (int val : testValues) {
        Card* c = new MermaidCard(val);
        
        std::cout << c->str() << std::endl;
        delete c;
    }
    return 0;
}

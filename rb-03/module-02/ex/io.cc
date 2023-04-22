#include <fstream>
#include <iostream>
#include "perf.h"
using namespace std;

int main(){


    ofstream out("test.txt");
    {
        LOG_DURATION("endl");
    for (size_t i = 0; i < 25000; i++)
    {
        out << "Hello" << "My name is Igor" << endl;
    }
       
    }

    {

        LOG_DURATION("\\n");
    for (size_t i = 0; i < 25000; i++)
    {
        out << "Hello" << "My name is Igor" << "\n";
    }
    
    }
        
}
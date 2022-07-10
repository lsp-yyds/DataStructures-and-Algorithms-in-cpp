//
// Created by bruce on 7/10/22.
//
#include "ArrayList.h"

int main() {
    try {
        arrayList<int> a = arrayList<int>( 100 );
        if ( a.empty() )
            std::cout << "empty" << std::endl;
        else
            std::cout << "not empty" << std::endl;
        for ( int i = 0; i < a.capacity(); i++ ) {
            a.element[ i ] = i;
            a.listSize++;
        }
        if ( a.empty() )
            std::cout << "empty" << std::endl;
        else
            std::cout << "not empty" << std::endl;
        // std::cout << a << std::endl;
        a.erase( 2 );
        std::cout << a << std::endl;
        std::cout << a.size() << std::endl;
        a.insert( 2, 2 );
        std::cout << a << std::endl;
    } catch ( illegalParameterValue e ) {
        e.outputMessage();
    }

    return 0;
}
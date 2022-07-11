//
// Created by bruce on 7/10/22.
//
#include "Chain.h"

int main() {
    try {
        chain<int> c = chain<int>( 100 );

        for ( int i = 0; i < 100; i++ ) {
            c.insert( i, i );
        }
        std::cout << c.size() << std::endl;
        std::cout << c.get( 33 ) << std::endl;
        std::cout << c.indexOf( 32 ) << std::endl;
        c.erase( 2 );
        std::cout << c.size() << std::endl;
        std::cout << c << std::endl;
        c.insert( 2, 2 );
        std::cout << c << std::endl;
    } catch ( illegalParameterValue e ) {
        e.outputMessage();
    }

    return 0;
}
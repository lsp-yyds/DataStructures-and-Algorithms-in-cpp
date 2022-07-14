//
// Created by bruce on 7/14/22.
//

#include "ArrayStack.h"
#include "DerivedArrayStack.h"
#include "LinkedStack.h"

int main() {

    // derivedArrayStack<int> s( 10 );
    // arrayStack<int> s( 10 );
    linkedStack<int> s( 100 );
    if ( s.empty() )
        std::cout << "empty" << std::endl;
    else
        std::cout << "not empty" << std::endl;

    for ( int i = 0; i < 10; ++i ) {
        s.push( i );
    }

    if ( s.empty() )
        std::cout << "empty" << std::endl;
    else
        std::cout << "not empty" << std::endl;
    std::cout << s.size() << std::endl;

    return 0;
}

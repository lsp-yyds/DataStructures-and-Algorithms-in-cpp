//
// Created by bruce on 7/13/22.
//

#include "Matrix.h"

int main() {
    try {
        matrix<int> m = matrix<int>( 4, 4 );
        matrix<int> m1( 4, 4 );

        m += 4;
        m1 += 3;
        m = m - m1;

        std::cout << m( 2, 2 ) << std::endl;
        std::cout << m << std::endl;
    } catch ( illegalParameterValue e ) {
        e.outputMessage();
    } catch ( matrixIndexOutOfBounds e ) {
        e.outputMessage();
    } catch ( matrixSizeMismatch e ) {
        e.outputMessage();
    }

    return 0;
}
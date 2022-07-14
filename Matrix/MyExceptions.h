//
// Created by bruce on 7/13/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MYEXCEPTIONS_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MYEXCEPTIONS_H

#include <iostream>
#include <string>

class illegalParameterValue {
  private:
    std::string message;

  public:
    illegalParameterValue()
        : message( "Illegal parameter value" ) {
    }
    illegalParameterValue( std::string theMessage ) {
        message = theMessage;
    }
    void outputMessage() {
        std::cout << message << std::endl;
    }
};

class matrixIndexOutOfBounds {
  private:
    std::string message;

  public:
    matrixIndexOutOfBounds()
        : message( "Matrix index out of bounds" ) {
    }
    matrixIndexOutOfBounds( std::string theMessage ) {
        message = theMessage;
    }
    void outputMessage() {
        std::cout << message << std::endl;
    }
};

class matrixSizeMismatch {
  private:
    std::string message;

  public:
    matrixSizeMismatch()
        : message( "Matrix size mismatch" ) {
    }
    matrixSizeMismatch( std::string theMessage ) {
        this->message = theMessage;
    }

    void outputMessage() {
        std::cout << message << std::endl;
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MYEXCEPTIONS_H

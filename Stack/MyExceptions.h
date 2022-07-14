//
// Created by bruce on 7/13/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MYEXCEPTIONS_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MYEXCEPTIONS_H

#include <iostream>
#include <string>

class stackEmpty {
  private:
    std::string message;

  public:
    stackEmpty()
        : message( "stack empty" ) {
    }
    stackEmpty( std::string theMessage ) {
        message = theMessage;
    }
    void outputMessage() {
        std::cout << message << std::endl;
    }
};

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

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MYEXCEPTIONS_H

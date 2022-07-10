//
// Created by bruce on 7/10/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ILLEGALPARAMETERVALUE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ILLEGALPARAMETERVALUE_H

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

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ILLEGALPARAMETERVALUE_H

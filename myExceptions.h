//
// Created by bruce on 7/15/22.
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
        : message("Illegal parameter value") {
    }
    illegalParameterValue(std::string theMessage) {
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
        : message("Matrix index out of bounds") {
    }
    matrixIndexOutOfBounds(std::string theMessage) {
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
        : message("Matrix size mismatch") {
    }
    matrixSizeMismatch(std::string theMessage) {
        this->message = theMessage;
    }

    void outputMessage() {
        std::cout << message << std::endl;
    }
};

class illegalIndex {
  private:
    std::string message;

  public:
    illegalIndex()
        : message("Illegal index") {
    }
    illegalIndex(std::string theMessage) {
        message = theMessage;
    }
    void outputMessage() {
        std::cout << message << std::endl;
    }
};

class stackEmpty {
  private:
    std::string message;

  public:
    stackEmpty()
        : message("Stack empty") {
    }
    stackEmpty(std::string theMessage) {
        message = theMessage;
    }
    void outputMessage() {
        std::cout << message << std::endl;
    }
};

class queueEmpty {
  private:
    std::string message;

  public:
    queueEmpty()
        : message("Queue empty") {
    }
    queueEmpty(std::string theMessage) {
        message = theMessage;
    }
    void outputMessage() {
        std::cout << message << std::endl;
    }
};

class undefinedMethod {
  private:
    std::string message;

  public:
    undefinedMethod()
        : message("method undefined") {
    }
    undefinedMethod(std::string theMessage) {
        message = theMessage;
    }
    void outputMessage() {
        std::cout << message << std::endl;
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MYEXCEPTIONS_H

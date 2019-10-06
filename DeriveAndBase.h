//
// Created by lzx on 10/1/19.
//

#ifndef VECTOR_DERIVEANDBASE_H
#define VECTOR_DERIVEANDBASE_H

#include <string>

class Base {
public:
     std::string str() {return "hello";}

private:
    int baseId;
protected:
    int ha = 1.0;
};

class Derived:  Base {
public:
    std::string str() {return "fuck";}

private:
    int derivedId;

};




#endif //VECTOR_DERIVEANDBASE_H

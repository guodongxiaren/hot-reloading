#include <iostream>

#include "alice.h"

int Alice::play() {
    //std::cout<<"My'name is alice"<<std::endl;
    std::cout<<"My'name is alice, how are you"<<std::endl;
    return 0;
}
extern "C" {
    Kid* create() {
        Kid* alice = new Alice;
        return alice;
    }
}

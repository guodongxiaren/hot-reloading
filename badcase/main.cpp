#include <iostream>
#include <string>

#include <dlfcn.h>
#include <unistd.h>

#include "kid.h"
#include "alice.h"
//#include "test.h"
typedef Kid* (*create_t)();

int test() {
    void* handle = dlopen("./libkids.so", RTLD_LAZY);
    if (!handle) {
        return 1;
    }
    create_t create = (create_t)dlsym(handle, "create");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cout<<dlsym_error<<std::endl;
        return 1;
    }
    Kid* kid = create();
    if (kid) {
        kid->play();
    }
    //delete kid;
    dlclose(handle);
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cout<<dlsym_error<<std::endl;
        return 1;
    }
    return 0;
}

int main() {
    int ret = 0;
    do {
        ret = test();
        sleep(5);
    } while(!ret);
}


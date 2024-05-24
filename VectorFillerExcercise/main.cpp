#include <iostream>
#include "src/generator/impl/generic/GenericGeneratorImpl.h"
#include "src/bootstrap/Bootstrap.h"

int main() {
    atlas::bootstrap::Bootstrap bootstrap;
    bootstrap.startApplication();

//    atlas::generator::GenericGeneratorImpl generator{1, [](int x)->int{return x + 3;}};
//
//    for (int i = 0; i < 5; ++i) {
//        std::cout << generator.next() << std::endl;
//    }
    return 0;
}

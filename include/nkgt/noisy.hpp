#ifndef _NKGT_NOISY_
#define _NKGT_NOISY_

#include <nkgt/type_support.hpp>
#include <iostream>

namespace nkgt {

template<typename T>
class Noisy {
public:
    Noisy() {
        std::cout << type_name_v<T> << " constructor invoked.\n";
    };

    Noisy(const Noisy&) {
        std::cout << type_name_v<T> << " copy-constructor invoked.\n";
    };

    Noisy(Noisy&&) {
        std::cout << type_name_v<T> << " move-constructor invoked.\n";
    };

    ~Noisy() {
        std::cout << type_name_v<T> << " destructor invoked.\n";
    };
};

}

#endif // _NKGT_NOISY_HPP_
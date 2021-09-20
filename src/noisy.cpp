#include <nkgt/noisy.hpp>

#include <iostream>

nkgt::Noisy::Noisy() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

nkgt::Noisy::Noisy(const Noisy&) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

nkgt::Noisy::Noisy(Noisy&&) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
}

nkgt::Noisy::~Noisy() {
    std::cout << __PRETTY_FUNCTION__ << "\n";
}


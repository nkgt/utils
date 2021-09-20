#ifndef _NKGT_NOISY_HPP_
#define _NKGT_NOISY_HPP_

namespace nkgt {

class Noisy {
public:
    Noisy();
    Noisy(const Noisy&);
    Noisy(Noisy&&);
    ~Noisy();
};

}

#endif // _NKGT_NOISY_HPP_
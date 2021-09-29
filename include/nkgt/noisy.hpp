#ifndef _NKGT_NOISY_
#define _NKGT_NOISY_

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
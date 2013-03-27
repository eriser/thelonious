#ifndef THELONIOUS_CONSTANT_MODULO_H
#define THELONIOUS_CONSTANT_MODULO_H

#include "thelonious/types.h"
#include "thelonious/unit.h"

namespace thelonious {
namespace operators {

template <size_t N>
class ConstantModuloN : public Unit<N> {
public:
    ConstantModuloN(Unit<N> &unit, Sample value, bool inverse=false):
            unit(&unit), value(value), inverse(inverse) {}

    void tick(Block<N> &block) {
        unit->tick(block);

        if (!inverse) {
            block %= value;
        }
        else {
            block = value % block;
        }
    }

    Unit<N> *unit;
    Sample value;
    bool inverse;
};

typedef ConstantModuloN<1> ConstantModulo;

template <size_t N>
ConstantModuloN<N> operator%(Unit<N> &a, Sample b) {
    return ConstantModuloN<N>(a, b);
}

template <size_t N>
ConstantModuloN<N> operator%(Unit<N> &&a, Sample b) {
    return ConstantModuloN<N>(a, b);
}

template <size_t N>
ConstantModuloN<N> operator%(Sample a, Unit<N> &b) {
    return ConstantModuloN<N>(b, a, true);
}

template <size_t N>
ConstantModuloN<N> operator%(Sample a, Unit<N> &&b) {
    return ConstantModuloN<N>(b, a, true);
}

} // namespace operators
} // namespace thelonious

#endif

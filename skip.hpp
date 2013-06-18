#ifndef SKIP_HPP
#define SKIP_HPP

#include "binary.hpp"
#include "load.hpp"

#include "type_traits/extended/is_container.hpp"

// #include <string>
// #include <utility> // std::pair
#include <fstream> // read


namespace util { namespace serialize { namespace binary {
    template <typename T> void skip(std::ifstream & is);
    template <typename T> void skip(std::ifstream & is) { load<T>(is); }

} } } /* namespace util::serialize::binary */

#endif /* end of include guard: SKIP_HPP */
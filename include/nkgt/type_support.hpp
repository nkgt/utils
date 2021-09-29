#ifndef _NKGT_TYPESUPPORT_
#define _NKGT_TYPESUPPORT_

#include <string_view>

namespace nkgt {

template<typename T>
constexpr auto type_name() {
#ifdef __clang__
    std::string_view name = __PRETTY_FUNCTION__;
    return std::string_view{name.data() + 22, name.size() - 22 - 1};
    // prefix = "auto type_name() [T = ";
    // suffix = "]";
#elif defined(__GNUC__)
    std::string_view name = __PRETTY_FUNCTION__;
    return std::string_view{name.data() + 37, name.size() - 37 - 1};
    // prefix = "constexpr auto type_name() [with T = ";
    // suffix = "]";
#elif defined(_MSC_VER)
    std::string_view name = __FUNCSIG__;
    return std::string_view{name.data() + 23, name.size() - 23 - 7};
    // prefix = "auto __cdecl type_name<";
    // suffix = ">(void)";
#endif
}

}

#endif // _NKGT_TYPESUPPORT_
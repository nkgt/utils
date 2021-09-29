#ifndef _NKGT_TYPESUPPORT_
#define _NKGT_TYPESUPPORT_

#include <string_view>

namespace nkgt {

template<typename T>
constexpr auto type_name() {
#ifdef __clang__
    std::string_view name = __PRETTY_FUNCTION__;
    return std::string_view{name.data() + 28, name.size() - 28 - 1};
    // prefix = "auto nkgt::type_name() [T = ";
    // suffix = "]";
#elif defined(__GNUC__)
    std::string_view name = __PRETTY_FUNCTION__;
    return std::string_view{name.data() + 43, name.size() - 43 - 1};
    // prefix = "constexpr auto nkgt::type_name() [with T = ";
    // suffix = "]";
#elif defined(_MSC_VER)
    std::string_view name = __FUNCSIG__;
    return std::string_view{name.data() + 29, name.size() - 29 - 7};
    // prefix = "auto __cdecl nkgt::type_name<";
    // suffix = ">(void)";
#endif
}

template<typename T>
inline constexpr std::string_view type_name_v = type_name<T>();

}

#endif // _NKGT_TYPESUPPORT_
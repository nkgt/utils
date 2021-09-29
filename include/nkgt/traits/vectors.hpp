#ifndef _NKGT_TRAITS_VECTORS_
#define _NKGT_TRAITS_VECTORS_

#include <type_traits>

namespace nkgt {

template<typename, typename = void>
struct is_vec3_like : std::false_type {};

/**
 * @brief A type trait to check if a given type T is vector3-like by exposing
 * public data members named x, y and z. Note that static and/or const data
 * members are acceptable to be "vector3-like".
 * 
 * @tparam T The type you wish to know if is vector3-like.
 */
template<typename T>
struct is_vec3_like<
    T,
    std::void_t<
        // Using decltype(std::declval<T>().x) instead of decltype(&T::x)
        // allows to detect also static data members.
        decltype(std::declval<T>().x),
        decltype(std::declval<T>().y),
        decltype(std::declval<T>().z)
    >
> : std::bool_constant<
        // Check that the types are uniform across members
        std::is_same_v<decltype(std::declval<T>().x), decltype(std::declval<T>().y)> &&
        std::is_same_v<decltype(std::declval<T>().y), decltype(std::declval<T>().z)> &&
        // Check that the type are numerical. This still accepts char and the
        // like which I think is a mistake!
        std::is_arithmetic_v<decltype(std::declval<T>().x)> &&
        std::is_arithmetic_v<decltype(std::declval<T>().y)> &&
        std::is_arithmetic_v<decltype(std::declval<T>().z)>
    >
{};

/**
 * @brief A convenience definition to access the [[is_vec3_like]] boolean value
 * 
 * @tparam T The type you wish to know if is vector3-like
 */
template<typename T>
inline constexpr bool is_vec3_like_v = is_vec3_like<T>::value;

} // namespace nkgt

#endif // _NKGT_TRAITS_VECTORS_
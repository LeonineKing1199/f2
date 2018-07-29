#ifndef FOXY_TYPE_TRAITS_HPP_
#define FOXY_TYPE_TRAITS_HPP_

#include <boost/asio/strand.hpp>

#include <type_traits>

namespace foxy {

namespace detail
{

auto _is_strand(void const*) -> std::false_type;

template <typename T>
auto _is_strand(boost::asio::strand<T> const*) -> std::true_type;

} // detail

template <typename T>
struct is_strand : decltype(detail::_is_strand(static_cast<T*>(nullptr)))
{
};

template <typename T>
inline constexpr
bool is_strand_v = is_strand<T>::value;

} // foxy

#endif // FOXY_TYPE_TRAITS_HPP_
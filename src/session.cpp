#include "foxy/detail/session.hpp"

foxy::detail::session::session(boost::asio::io_context& io)
: s_(std::make_shared<session_state>(io))
{
}

foxy::detail::session::session(
  boost::asio::io_context&   io,
  boost::asio::ssl::context& ctx)
: s_(std::make_shared<session_state>(io, ctx))
{
}
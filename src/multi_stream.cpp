#include "foxy/multi_stream.hpp"

foxy::multi_stream::multi_stream(boost::asio::io_context& io)
: stream_(io)
, ssl_stream_()
{
}

foxy::multi_stream::multi_stream(
  boost::asio::io_context&   io,
  boost::asio::ssl::context& ctx)
: stream_(io)
, ssl_stream_(std::in_place, stream_, ctx)
{
}

auto foxy::multi_stream::get_executor() -> executor_type {
  return stream_.get_executor();
}

auto foxy::multi_stream::is_ssl() const -> bool {
  return static_cast<bool>(ssl_stream_);
}

auto foxy::multi_stream::stream() & -> stream_type& {
  return stream_;
}

auto foxy::multi_stream::ssl_stream() & -> ssl_stream_type& {
  return *ssl_stream_;
}
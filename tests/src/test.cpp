#include <boost/ut.hpp>
#include <pqrs/gsl.hpp>
#include <unordered_map>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace std::literals;

  "not_null_shared_ptr_t"_test = [] {
    pqrs::not_null_shared_ptr_t<std::string> p = std::make_shared<std::string>("hello");
    expect("hello"sv == *p);
  };

  "unwrap_not_null"_test = [] {
    pqrs::not_null_shared_ptr_t<std::string> p = std::make_shared<std::string>("hello");
    expect("hello"sv == *(pqrs::unwrap_not_null(p)));
  };

  "make_weak"_test = [] {
    pqrs::not_null_shared_ptr_t<std::string> p = std::make_shared<std::string>("hello");
    auto w = pqrs::make_weak(p);
    expect("hello"sv == *(w.lock()));
  };

  "hash"_test = [] {
    std::unordered_map<pqrs::not_null_shared_ptr_t<std::string>, std::string> map;
    map.insert({std::make_shared<std::string>("hello"), "world"});
  };

  return 0;
}

#include <boost/ut.hpp>
#include <pqrs/gsl.hpp>
#include <unordered_map>

int main() {
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
    pqrs::not_null_shared_ptr_t<std::string> key1 = std::make_shared<std::string>("hello");
    pqrs::not_null_shared_ptr_t<std::string> key2 = std::make_shared<std::string>("hello");
    map.insert({key1, "world1"});
    map.insert({key2, "world2"});

    expect("world1"sv == map.at(key1));
    expect("world2"sv == map.at(key2));
  };

  return 0;
}

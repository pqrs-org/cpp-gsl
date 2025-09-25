#include <boost/ut.hpp>
#include <pqrs/gsl.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace std::literals;

  "not_null_shared_ptr_t"_test = [] {
    pqrs::not_null_shared_ptr_t<std::string> p = std::make_shared<std::string>("hello");
    expect("hello"sv == *p);
  };

  return 0;
}

#include <iostream>
#include <pqrs/gsl.hpp>

int main(void) {
  pqrs::not_null_shared_ptr_t<std::string> p = std::make_shared<std::string>("hello");
  std::cout << *p << std::endl;

  return 0;
}

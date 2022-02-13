
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include <catch.hpp>

#include <iostream>
#include <vector>
#include <ranges>
#include <string>

// Lots of room for improvements

class Mystring : public std::string {
 public:
  Mystring() : std::string{} { std::cout << "Mystring ctor\n"; }
  Mystring(std::string s) : std::string{s} { std::cout << "Mystring ctor(\"" << *this << "\")\n"; }
  Mystring(Mystring const& copy) : std::string{copy} {
    std::cout << "Mystring copy(\"" << *this << "\")\n";
  }
  Mystring(Mystring&& move) noexcept : std::string{std::move(move)} {
    std::cout << "Mystring move(\"" << *this << "\")\n";
  }
};

std::vector<Mystring> create_data() {
  std::vector<Mystring> strings{};

  std::vector<uint32_t> range = {0, 1 , 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "using push_back\n";
  for (auto i : range) // std::views::iota(0, 10))
    //strings.emplace_back(std::move(std::to_string(i)));
    strings.emplace_back(std::to_string(i));
    //strings.push_back(std::to_string(i));
  return strings;
}

TEST_CASE("r-values vs copying", "[factorial]") {
  std::cout << "Testing r-value references\n";

  std::vector<Mystring> strings = create_data();
}


struct Elidor {
  ~Elidor() { std::cout << "Elidor dtor" << std::endl; }
  void sayHi() const { std::cout << "Hi I am an Elidor\n"; }
};

TEST_CASE("closures", "[lambdas]") {
  Elidor eli;

  auto f = [eli]() { eli.sayHi(); };

  f();

  std::cout << "--> We are here <--" << std::endl;
}


#include <iostream>
#include <vector>

// Lots of room for improvements

class Mystring : public std::string
{
public:
    Mystring() : std::string{} { std::cout << "Mystring()\n"; }
    Mystring(Mystring const &copy) : std::string{copy}
    {
        std::cout << "Mystring copy(\"" << *this << "\")\n";
    }
    Mystring(Mystring &&move) noexcept
        : std::string{std::move(move)}
    {
        std::cout << "Mystring move(\"" << *this << "\")\n";
    }
};

std::vector<Mystring> read_data()
{
    std::vector<Mystring> strings{};
    Mystring line{};
    while (std::getline(std::cin, line))
        strings.emplace_back(std::move(line));
    return strings;
}

int test_rvalue_refs() noexcept
{
    std::cout << "Testing r-value references\n";

    std::vector<Mystring> strings{};
    strings = read_data();

    return 0;
}

int main()
{
    test_rvalue_refs();
}
#include <iostream>
#include <string>
#include <list>
#include <boost/algorithm/string.hpp>

int main(int argc, char const *argv[])
{
    std::string str("Abra cadabra !");
    std::list<std::string> list_string;
    boost::split(list_string, str, boost::is_space());

    for (std::string i : list_string)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

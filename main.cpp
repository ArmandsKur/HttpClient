#include <iostream>

int main(int argc, char* argv[] ) {
    //Must be only one argument provided
    if (argc != 2) {
        std::cerr << "Usage: <program> <hostname>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string_view hostname = argv[1];

    //Reject blank argument
    if (hostname.empty()) return EXIT_FAILURE;
    //Reject too large argument
    if (hostname.size() > 254) return EXIT_FAILURE;
    //Reject special hostname symbol
    if (hostname.find("://") < hostname.size()) {
        std::cerr << "Invalid input: looks like a URL (contains \"://\"). Please pass a hostname like \"example.com\"." << std::endl;
        return EXIT_FAILURE;
    }
    //Reject path or query chars
    if (
        hostname.find('/') < hostname.size() ||
        hostname.find('\\') < hostname.size() ||
        hostname.find('?') < hostname.size() ||
        hostname.find('&') < hostname.size() ||
        hostname.find('@') < hostname.size()
    ) {
        std::cerr << "Invalid input: contains path or query characters ('/', '?', '#')" << std::endl;
        return EXIT_FAILURE;
    }

    if (
        hostname.find(' ') < hostname.size() ||
        hostname.find('\t') < hostname.size() ||
        hostname.find('\n') < hostname.size()
    ) {
        std::cerr << "No whitespace allowed" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Host: " << argv[1] << std::endl;
    return 0;
}
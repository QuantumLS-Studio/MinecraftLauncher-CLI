#include <cstdio>
#include <fmt/core.h>

#include "MCL.hpp"

int main(int argc, char* argv[]) {
    config MCL_config("config.toml");
    if (argc < 2) {
        printf("MCL\n");
    }
    else {
        if (MCL_config.load()) {
            printf("%s\n", MCL_config.get<std::string>("awa").c_str());
        }
        else {
            return 1;
        }
    }

    return 0;
}

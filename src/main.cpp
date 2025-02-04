#include <cstdio>
#include <argh.h>
#include <string>

#include "include/info.h"
#include "config/config.cpp"

int main(int argc, char* argv[]){
    argh::parser cmdl(argc, argv);
    
    if(cmdl[{"-h", "--help"}]){
        printf("Usage: MCL [options]\n");
        printf("Options:\n");
        printf("  -h, --help    Print this help message\n");
        printf("  -v, --version Print version\n");
        return 0;
    }

    if (cmdl[{"-v", "--version"}]) {
        printf("%s\n", PROJ_VERSION);
        return 0;
    }

    if (cmdl[{"-i", "--info"}]) {
        printf("---- %s ----\n", PROJ_NAME);
        printf("Version: %s\n", PROJ_VERSION);
        printf("Description: %s\n", PROJ_DESC);
        printf("Author: %s\n", PROJ_AUTHOR);
        printf("License: %s\n", PROJ_LICENSE);
        printf("URL: %s\n", PROJ_URL);
        return 0;
    }

    if(cmdl[{"-c", "--config"}]){
        std::string config_file;
        cmdl(1) >> config_file;
        config c = config(config_file);
        return 0;
    }

    if (cmdl.pos_args().size() > 0) {
        printf("Invalid arguments\n");
        return 1;
    }
    
    printf("Hello, World!\n");
    return 0;
}
#include <cstdio>
#include <args.hxx>

int main(int argc, char** argv){
    args::ArgumentParser parser("This is a test program", "This goes after the options.");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    try {
        parser.ParseCLI(argc, argv);
    }
    catch (const args::Help&) {
        printf("%s", parser);
        return 0;
    }
    catch (const args::ParseError& e) {
        fprintf(stderr, "Parse error: %s\n", e.what());
        fprintf(stderr, "%s", parser);
        return 1;
    }
    return 0;
}
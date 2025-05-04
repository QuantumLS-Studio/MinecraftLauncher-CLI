#include <fstream>
#include <toml++/impl/parse_error.hpp>
#include <toml++/impl/parser.hpp>
class MLP {
private:
    std::string file_path;

public:
    MLP(std::string FP) :
        file_path(FP) {
        config_file.open(file_path, std::ios::out);

        if (!config_file) {
            printf("Unable to open the file!\n");
        }
        cf = toml::parse_file(file_path);

    }

    std::fstream config_file;
    toml::table cf;

    std::string get_game_name() const {
        return cf["game"]["name"].value_or("NULL");
    }
};

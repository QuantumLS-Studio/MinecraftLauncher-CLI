#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <filesystem>
#include <fmt/base.h>
#include <fstream>
#include <sstream>
#include <toml++/toml.hpp>

class config {
private:
    std::filesystem::path file_path;

    std::string file_content;

public:
    config(std::filesystem::path _file_path) : file_path(_file_path) {}

    bool load() {
        std::ifstream file(file_path, std::ios::in);
        if (file) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file_content = buffer.str();
            return true;
        }
        else {
            fmt::report_error("Failed to open config file for reading!");
            return false;
        }
    }

    bool save(toml::table config_data_table) {
        std::ofstream file(file_path, std::ios::app);
        if (file) {
            file << config_data_table << std::endl;
            return true;
        }
        else {
            return false;
        }
    }

    std::string get_content_string() const {
        return file_content;
    }

    template<typename T>
    T get(const std::string& key) {
        toml::table config_toml;
        if (file_content.empty()) {
            fmt::report_error("Read config failed or config is empty!");
            return NULL;
        }
        else {
            try {
                config_toml = toml::parse(file_content);
                return config_toml.get_as<T>(key);
            }
            catch (const toml::parse_error& e) {
                fmt::report_error(e.what());
                return NULL;
            }
        }
        return NULL;
    }
};

#endif

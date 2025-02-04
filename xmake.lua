add_requires("fmt", "spdlog", "nlohmann_json", "argh")

target("MCL")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("src/include")
    add_packages("fmt", "spdlog", "nlohmann_json", "argh")
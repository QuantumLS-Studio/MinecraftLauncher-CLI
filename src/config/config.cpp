#include <string>
#include <string_view>
#include <toml++/toml.h>
#include <toml++/toml.h>

using namespace std::literals;

class config{
    private:
        toml::table config_file;

    public:
        config(const std::string& path){
            config_file = toml::parse_file(path);
        }
        std::string_view get_system_editor(){
            return config_file["system"]["editor"].value_or("vim");
        }
        std::string_view get_system_viewer(){
            return config_file["system"]["viewer"].value_or("cat");
        }
        std::string_view get_system_shell(){
            return config_file["system"]["shell"].value_or("bash");
        }
        
        void set_system_editor(const std::string& editor){
            config_file.insert_or_assign("system", toml::table{{"editor", editor}});
        }
        void set_system_viewer(const std::string& viewer){
            config_file.insert_or_assign("system", toml::table{{"viewer", viewer}});
        }
        void set_system_shell(const std::string& shell){
            config_file.insert_or_assign("system", toml::table{{"shell", shell}});
        }
        
        void load(const std::string& path){
            try{
                config_file = toml::parse_file(path);
            }catch(const toml::parse_error& err){
                printf("Failed to load config file: %s\n", err.what());
            }
        }
        
        void save(const std::string& path){
            std::ofstream file(path);
            file << config_file;
        }
};
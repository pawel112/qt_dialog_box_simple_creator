#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <fstream>

class settings
{
private:
    static std::fstream settings_file;
    static std::string with_language;
    static unsigned int centering_a_string_horizontally;
    static unsigned int centering_a_string_vertically;
    static unsigned int no_change_window_size;
    static unsigned int without_a_question_mark;
    static unsigned int remove_unnecessary_spaces;

    settings(std::string with_language, unsigned int centering_a_string_horizontally, unsigned int centering_a_string_vertically, unsigned int no_change_window_size, unsigned int without_a_question_mark, unsigned int remove_unnecessary_spaces)
    {
        settings::with_language = with_language;
        settings::centering_a_string_horizontally = centering_a_string_horizontally;
        settings::centering_a_string_vertically = centering_a_string_vertically;
        settings::no_change_window_size = no_change_window_size;
        settings::without_a_question_mark = without_a_question_mark;
        settings::remove_unnecessary_spaces = remove_unnecessary_spaces;
    }

public:
    static settings& getInstance (std::string with_language, unsigned int centering_a_string_horizontally, unsigned int centering_a_string_vertically, unsigned int no_change_window_size, unsigned int without_a_question_mark, unsigned int remove_unnecessary_spaces)
    {
        static settings instance (with_language, centering_a_string_horizontally, centering_a_string_vertically, no_change_window_size, without_a_question_mark, remove_unnecessary_spaces);
        return instance;
    }

    settings();
    static void load_file();
    static void save_file();
    static void default_settings();
    static bool if_file_exists();

    static void set_language (std::string new_language)
    {
        if (new_language == "polski")
        {
            settings::with_language = "polski";
        }
        else
        {
            settings::with_language = "English";
        }
        save_file();
    }

    static void set_centering_a_string_horizontally (unsigned int centering_a_string_horizontally)
    {
        settings::centering_a_string_horizontally = centering_a_string_horizontally;
        save_file();
    }

    static void set_centering_a_string_vertically (unsigned int centering_a_string_vertically)
    {
        settings::centering_a_string_vertically = centering_a_string_vertically;
        save_file();
    }

    static void set_no_change_window_size(unsigned int no_change_window_size)
    {
        settings::no_change_window_size = no_change_window_size;
        save_file();
    }

    static void set_without_a_question_mark(unsigned int without_a_question_mark)
    {
        settings::without_a_question_mark = without_a_question_mark;
        save_file();
    }

    static void set_remove_unnecessary_spaces(unsigned int remove_unnecessary_spaces)
    {
        settings::remove_unnecessary_spaces = remove_unnecessary_spaces;
        save_file();
    }

    static std::string get_language ()
    {
        return settings::with_language;
    }

    static unsigned int get_centering_a_string_horizontally ()
    {
        return settings::centering_a_string_horizontally;
    }

    static unsigned int get_centering_a_string_vertically ()
    {
        return settings::centering_a_string_vertically;
    }

    static unsigned int get_no_change_window_size()
    {
        return settings::no_change_window_size;
    }

    static unsigned int get_without_a_question_mark()
    {
        return settings::without_a_question_mark;
    }

    static unsigned int get_remove_unnecessary_spaces()
    {
        return settings::remove_unnecessary_spaces;
    }
};

#endif // SETTINGS_H

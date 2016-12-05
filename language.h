#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "error.h"
#include <iostream>
#include <fstream>
#include <string>

class language
{
private:
    static std::string menu_settings;
    static std::string menu_language;
    static std::string menu_language_english;
    static std::string menu_language_polish;
    static std::string menu_default_settings;
    static std::string menu_centering_a_string_horizontally;
    static std::string menu_centering_a_string_vertically;
    static std::string menu_no_change_window_size;
    static std::string menu_without_a_question_mark;
    static std::string menu_remove_unnecessary_spaces;
    static std::string menu_default_validation_of_integers;
    static std::string menu_default_validation_of_floats;
    static std::string menu_default_no_validation;
    static std::string menu_default_validation_of_string;
    static std::string menu_exit;
    static std::string menu_about_program;
    static std::string app_dialog_class_name;
    static std::string app_dir_with_source_code;
    static std::string app_create_dialog;
    static std::string app_new_int;
    static std::string app_new_float;
    static std::string app_new_string;
    static std::string app_no_validation;
    static std::string app_new_field;
    static std::string app_new_text_field;
    static std::string app_new_min_value;
    static std::string app_new_max_value;
    static std::string app_new_button;
    static std::string app_new_min_length;
    static std::string app_new_max_length;
    static std::string app_choose_dir;
    static std::string app_no_fields;
    static std::string app_no_error;
    static std::string app_donation;
    static std::string error_creating_files;

    language(std::string menu_settings, std::string menu_language, std::string menu_language_english, std::string menu_language_polish, std::string menu_default_settings, std::string menu_centering_a_string_horizontally, std::string menu_centering_a_string_vertically, std::string menu_no_change_window_size, std::string menu_without_a_question_mark, std::string menu_remove_unnecessary_spaces, std::string menu_default_validation_of_integers, std::string menu_default_validation_of_floats, std::string menu_default_no_validation, std::string menu_default_validation_of_string, std::string menu_exit, std::string menu_about_program, std::string app_dialog_class_name, std::string app_dir_with_source_code, std::string app_create_dialog, std::string app_new_int, std::string app_new_float, std::string app_new_string, std::string app_no_validation, std::string app_new_field, std::string app_new_min_value, std::string app_new_max_value, std::string app_new_button, std::string app_new_min_length, std::string app_new_max_length, std::string app_choose_dir, std::string app_no_fields, std::string app_no_error, std::string app_donation, std::string error_creating_files)
    {
        language::menu_settings = menu_settings;
        language::menu_language = menu_language;
        language::menu_language_english = menu_language_english;
        language::menu_language_polish = menu_language_polish;
        language::menu_default_settings = menu_default_settings;
        language::menu_centering_a_string_horizontally =menu_centering_a_string_horizontally ;
        language::menu_centering_a_string_vertically = menu_centering_a_string_vertically;
        language::menu_no_change_window_size = menu_no_change_window_size;
        language::menu_without_a_question_mark = menu_without_a_question_mark;
        language::menu_remove_unnecessary_spaces = menu_remove_unnecessary_spaces;
        language::menu_default_validation_of_integers = menu_default_validation_of_integers;
        language::menu_default_validation_of_floats = menu_default_validation_of_floats;
        language::menu_default_no_validation = menu_default_no_validation;
        language::menu_default_validation_of_string = menu_default_validation_of_string;
        language::menu_exit = menu_exit;
        language::menu_about_program = menu_about_program;
        language::app_dialog_class_name = app_dialog_class_name;
        language::app_dir_with_source_code = app_dir_with_source_code;
        language::app_create_dialog = app_create_dialog;
        language::app_new_int = app_new_int;
        language::app_new_float = app_new_float;
        language::app_new_string = app_new_string;
        language::app_no_validation = app_no_validation;
        language::app_new_field = app_new_field;
        language::app_new_min_value = app_new_min_value;
        language::app_new_max_value = app_new_max_value;
        language::app_new_button = app_new_button;
        language::app_new_min_length = app_new_min_length;
        language::app_new_max_length = app_new_max_length;
        language::app_choose_dir = app_choose_dir;
        language::app_no_fields = app_no_fields;
        language::app_no_error = app_no_error;
        language::app_donation = app_donation;
        language::error_creating_files = error_creating_files;
    }

public:
    language(std::string language)
    {
        if (language == "polski")
        {
            set_language("polski");
        }
        else
        {
            set_language("English");
        }
    }

    static language& getInstance (std::string menu_settings, std::string menu_language, std::string menu_language_english, std::string menu_language_polish, std::string menu_default_settings, std::string menu_centering_a_string_horizontally, std::string menu_centering_a_string_vertically, std::string menu_no_change_window_size, std::string menu_without_a_question_mark, std::string menu_remove_unnecessary_spaces, std::string menu_default_validation_of_integers, std::string menu_default_validation_of_floats, std::string menu_default_no_validation, std::string menu_default_validation_of_string, std::string menu_exit, std::string menu_about_program, std::string app_dialog_class_name, std::string app_dir_with_source_code, std::string app_create_dialog, std::string app_new_int, std::string app_new_float, std::string app_new_string, std::string app_no_validation, std::string app_new_field, std::string app_new_min_value, std::string app_new_max_value, std::string app_new_button, std::string app_new_min_length, std::string app_new_max_length, std::string app_choose_dir, std::string app_no_fields, std::string app_no_error, std::string app_donation, std::string error_creating_files)
    {
        static language instance (menu_settings, menu_language, menu_language_english, menu_language_polish, menu_default_settings, menu_centering_a_string_horizontally, menu_centering_a_string_vertically, menu_no_change_window_size, menu_without_a_question_mark, menu_remove_unnecessary_spaces, menu_default_validation_of_integers, menu_default_validation_of_floats, menu_default_no_validation, menu_default_validation_of_string, menu_exit, menu_about_program, app_dialog_class_name, app_dir_with_source_code, app_create_dialog, app_new_int, app_new_float, app_new_string, app_no_validation, app_new_field, app_new_min_value, app_new_max_value, app_new_button, app_new_min_length, app_new_max_length, app_choose_dir, app_no_fields, app_no_error, app_donation, error_creating_files);
        return instance;
    }

    static bool if_file_exists(std::string new_language)
    {
        std::ifstream ifile(new_language);
        return (bool)ifile;
    }

    static void set_language (std::string new_language)
    {
        std::fstream language_file;
        std::string line = "";
        std::string file_name = "languages\\" + new_language;
        file_name += ".lang";

        if (if_file_exists (file_name) == true)
        {
            language_file.open(file_name, std::ios_base::in);
            if (language_file.is_open() == true)
            {
                std::getline (language_file, line);
                if (line.length() > 19)
                {
                    language::menu_settings = line.substr(17, line.length() - 19);
                }

                std::getline (language_file, line);
                if (line.length() > 19)
                {
                    language::menu_language = line.substr(17, line.length() - 19);
                }

                language::menu_language_english = "English";
                language::menu_language_polish = "polski";

                std::getline (language_file, line);
                if (line.length() > 27)
                {
                    language::menu_default_settings = line.substr(25, line.length() - 27);
                }

                std::getline (language_file, line);
                if (line.length() > 42)
                {
                    language::menu_centering_a_string_horizontally = line.substr(40, line.length() - 42);
                }

                std::getline (language_file, line);
                if (line.length() > 40)
                {
                    language::menu_centering_a_string_vertically = line.substr(38, line.length() - 40);
                }

                std::getline (language_file, line);
                if (line.length() > 32)
                {
                    language::menu_no_change_window_size = line.substr(30, line.length() - 32);
                }

                std::getline (language_file, line);
                if (line.length() > 34)
                {
                    language::menu_without_a_question_mark = line.substr(32, line.length() - 34);
                }

                std::getline (language_file, line);
                if (line.length() > 36)
                {
                    language::menu_remove_unnecessary_spaces = line.substr(34, line.length() - 36);
                }

                std::getline (language_file, line);
                if (line.length() > 41)
                {
                    language::menu_default_validation_of_integers = line.substr(39, line.length() - 41);
                }

                std::getline (language_file, line);
                if (line.length() > 39)
                {
                    language::menu_default_validation_of_floats = line.substr(37, line.length() - 39);
                }

                std::getline (language_file, line);
                if (line.length() > 32)
                {
                    language::menu_default_no_validation = line.substr(30, line.length() - 32);
                }

                std::getline (language_file, line);
                if (line.length() > 39)
                {
                    language::menu_default_validation_of_string = line.substr(37, line.length() - 39);
                }

                std::getline (language_file, line);
                if (line.length() > 15)
                {
                    language::menu_exit = line.substr(13, line.length() - 15);
                }

                std::getline (language_file, line);
                if (line.length() > 24)
                {
                    language::menu_about_program = line.substr(22, line.length() - 24);
                }

                std::getline (language_file, line);
                if (line.length() > 27)
                {
                    language::app_dialog_class_name = line.substr(25, line.length() - 27);
                }

                std::getline (language_file, line);
                if (line.length() > 30)
                {
                    language::app_dir_with_source_code = line.substr(28, line.length() - 30);
                }

                std::getline (language_file, line);
                if (line.length() > 23)
                {
                    language::app_create_dialog = line.substr(21, line.length() - 23);
                }

                std::getline (language_file, line);
                if (line.length() > 26)
                {
                    language::error_creating_files = line.substr(24, line.length() - 26);
                }

                std::getline (language_file, line);
                if (line.length() > 17)
                {
                    language::app_new_int = line.substr(15, line.length() - 17);
                }

                std::getline (language_file, line);
                if (line.length() > 19)
                {
                    language::app_new_float = line.substr(17, line.length() - 19);
                }

                std::getline (language_file, line);
                if (line.length() > 20)
                {
                    language::app_new_string = line.substr(18, line.length() - 20);
                }

                std::getline (language_file, line);
                if (line.length() > 23)
                {
                    language::app_no_validation = line.substr(21, line.length() - 23);
                }

                std::getline (language_file, line);
                if (line.length() > 19)
                {
                    language::app_new_field = line.substr(17, line.length() - 19);
                }

                std::getline (language_file, line);
                if (line.length() > 24)
                {
                    language::app_new_text_field = line.substr(22, line.length() - 24);
                }

                std::getline (language_file, line);
                if (line.length() > 23)
                {
                    language::app_new_min_value = line.substr(21, line.length() - 23);
                }

                std::getline (language_file, line);
                if (line.length() > 23)
                {
                    language::app_new_max_value = line.substr(21, line.length() - 23);
                }

                std::getline (language_file, line);
                if (line.length() > 20)
                {
                    language::app_new_button = line.substr(18, line.length() - 20);
                }

                std::getline (language_file, line);
                if (line.length() > 24)
                {
                    language::app_new_min_length = line.substr(22, line.length() - 24);
                }

                std::getline (language_file, line);
                if (line.length() > 24)
                {
                    language::app_new_max_length = line.substr(22, line.length() - 24);
                }

                std::getline (language_file, line);
                if (line.length() > 20)
                {
                    language::app_choose_dir = line.substr(18, line.length() - 20);
                }

                std::getline (language_file, line);
                if (line.length() > 19)
                {
                    language::app_no_fields = line.substr(17, line.length() - 19);
                }

                std::getline (language_file, line);
                if (line.length() > 18)
                {
                    language::app_no_error = line.substr(16, line.length() - 18);
                }

                std::getline (language_file, line);
                if (line.length() > 18)
                {
                    language::app_donation = line.substr(16, line.length() - 18);
                }
            }
        }
        else
        {
            error *w = new error (NULL, "No file English.lang. The program will exit.");
            w->exec();
            exit(1);
        }
    }

    static std::string get_menu_settings() { return language::menu_settings; }
    static std::string get_menu_language() { return language::menu_language; }
    static std::string get_menu_language_english() { return language::menu_language_english; }
    static std::string get_menu_language_polish() { return language::menu_language_polish; }
    static std::string get_menu_default_settings() { return language::menu_default_settings; }
    static std::string get_menu_centering_a_string_horizontally() { return language::menu_centering_a_string_horizontally; }
    static std::string get_menu_centering_a_string_vertically() { return language::menu_centering_a_string_vertically; }
    static std::string get_menu_no_change_window_size() { return language::menu_no_change_window_size; }
    static std::string get_menu_without_a_question_mark() { return language::menu_without_a_question_mark; }
    static std::string get_menu_remove_unnecessary_spaces() { return language::menu_remove_unnecessary_spaces; }
    static std::string get_menu_default_validation_of_integers() { return language::menu_default_validation_of_integers; }
    static std::string get_menu_default_validation_of_floats() { return language::menu_default_validation_of_floats; }
    static std::string get_menu_default_no_validation() { return language::menu_default_no_validation; }
    static std::string get_menu_default_validation_of_string() { return language::menu_default_validation_of_string; }
    static std::string get_menu_exit() { return language::menu_exit; }
    static std::string get_menu_about_program() { return language::menu_about_program; }
    static std::string get_app_dialog_class_name() { return language::app_dialog_class_name; }
    static std::string get_app_dir_with_source_code() { return language::app_dir_with_source_code; }
    static std::string get_app_create_dialog() { return language::app_create_dialog; }
    static std::string get_app_new_int() { return language::app_new_int; }
    static std::string get_app_new_float() { return language::app_new_float; }
    static std::string get_app_new_string() { return language::app_new_string; }
    static std::string get_app_no_validation() { return language::app_no_validation; }
    static std::string get_app_new_field() { return language::app_new_field; }
    static std::string get_app_new_text_field() { return language::app_new_text_field; }
    static std::string get_app_new_min_value() { return language::app_new_min_value; }
    static std::string get_app_new_max_value() { return language::app_new_max_value; }
    static std::string get_app_new_button() { return language::app_new_button; }
    static std::string get_app_new_min_length() { return language::app_new_min_length; }
    static std::string get_app_new_max_length() { return language::app_new_max_length; }
    static std::string get_app_choose_dir() { return language::app_choose_dir; }
    static std::string get_app_no_fields() { return language::app_no_fields; }
    static std::string get_app_no_error() { return language::app_no_error; }
    static std::string get_app_donation() { return language::app_donation; }
    static std::string get_error_creating_files() { return language::error_creating_files; }
};

#endif // LANGUAGE_H

#include "settings.h"
#include <iostream>
#include <fstream>
#include <string>

std::fstream settings::settings_file;
std::string settings::with_language = "";
unsigned int settings::centering_a_string_horizontally = 1;
unsigned int settings::centering_a_string_vertically = 1;
unsigned int settings::no_change_window_size = 1;
unsigned int settings::without_a_question_mark = 1;
unsigned int settings::remove_unnecessary_spaces = 1;

settings::settings()
{
    if (if_file_exists() == true)
    {
        load_file();
    }
    else
    {
        default_settings();
        save_file();
    }
}

void settings::load_file()
{
    std::string line;
    settings_file.open ("settings.conf", std::ios_base::in);
    std::getline (settings_file, line);
    if (settings_file.is_open() == true)
    {
        std::getline (settings_file, line);
        if (line.length() >= 16)
        {
            settings::with_language = line.substr(12, line.length() - 14);
        }
        else
        {
            default_settings();
        }

        std::getline (settings_file, line);
        if (line.length() == 36)
        {
            settings::centering_a_string_horizontally = std::stoi(line.substr(line.length() - 2, 1));
        }
        else
        {
            default_settings();
        }

        std::getline (settings_file, line);
        if (line.length() == 34)
        {
            settings::centering_a_string_vertically = std::stoi(line.substr(line.length() - 2, 1));
        }
        else
        {
            default_settings();
        }

        std::getline (settings_file, line);
        if (line.length() == 26)
        {
             settings::no_change_window_size = std::stoi(line.substr(line.length() - 2, 1));
        }
        else
        {
            default_settings();
        }

        std::getline (settings_file, line);
        if (line.length() == 28)
        {
            settings::without_a_question_mark = std::stoi(line.substr(line.length() - 2, 1));
        }
        else
        {
            default_settings();
        }

        std::getline (settings_file, line);
        if (line.length() == 30)
        {
            settings::remove_unnecessary_spaces = std::stoi(line.substr(line.length() - 2, 1));
        }
        else
        {
            default_settings();
        }
    }
    else
    {
        default_settings();
    }

    settings_file.close();
}

void settings::save_file()
{
    settings_file.open ("settings.conf", std::ios_base::out | std::ios::trunc);
    if (settings_file.is_open() == true)
    {
        settings_file << "# Configuration file program \"Dialog box simple creator\". Don't edit this file.\n";
        settings_file << "language = \"" << settings::with_language << "\";\n";
        settings_file << "centering_a_string_horizontally = " << settings::centering_a_string_horizontally << ";\n";
        settings_file << "centering_a_string_vertically = " << settings::centering_a_string_vertically << ";\n";
        settings_file << "no_change_window_size = " << settings::no_change_window_size << ";\n";
        settings_file << "without_a_question_mark = " << settings::without_a_question_mark << ";\n";
        settings_file << "remove_unnecessary_spaces = " << settings::remove_unnecessary_spaces << ";\n";
    }
    settings_file.close();
}

void settings::default_settings()
{
    settings::with_language = "English";
    settings::centering_a_string_horizontally = 1;
    settings::centering_a_string_vertically = 1;
    settings::no_change_window_size = 1;
    settings::without_a_question_mark = 1;
    settings::remove_unnecessary_spaces = 1;
}

bool settings::if_file_exists()
{
    std::ifstream ifile("settings.conf");
    return (bool)ifile;
}

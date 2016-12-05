#ifndef CREATE_FILES_H
#define CREATE_FILES_H

#include "settings.h"

bool create_ui_file(std::string class_name, std::string dir, settings app_settings);
bool create_h_file(std::string class_name, std::string dir);
bool create_cpp_file(std::string class_name, std::string dir, settings app_settings);
void trim (std::string &s);

#endif // CREATE_FILES_H

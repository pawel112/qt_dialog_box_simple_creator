#include "done_window.h"
#include "settings.h"
#include "main_window.h"
#include "create_files.h"
#include "structure.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <string>

extern std::list <struct structure> list_of_fields;

bool create_ui_file(std::string class_name, std::string dir, settings app_settings)
{
    std::fstream ui_file;
    std::string file_name;
    for (unsigned int i=0; i<class_name.length(); i++)
    {
        file_name += tolower(class_name[i]);
    }

    ui_file.open(dir+file_name+".ui", std::ios::out | std::ios::trunc);

    if (ui_file.good() == true)
    {
        ui_file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        ui_file << "<ui version=\"4.0\">\n";
        ui_file << " <class>" << class_name << "</class>\n";
        ui_file << " <widget class=\"QDialog\" name=\"" << class_name << "\">\n";
        ui_file << "  <property name=\"geometry\">\n";
        ui_file << "   <rect>\n";
        ui_file << "    <x>0</x>\n";
        ui_file << "    <y>0</y>\n";
        ui_file << "    <width>400</width>\n";
        ui_file << "    <height>" << (60+list_of_fields.size()*30) << "</height>\n";
        ui_file << "   </rect>\n";
        ui_file << "  </property>\n";
        ui_file << "  <property name=\"windowTitle\">\n";
        ui_file << "   <string>" << class_name << "</string>\n";
        ui_file << "  </property>\n";

        std::list <struct structure>::iterator it = list_of_fields.begin();

        if (list_of_fields.size() > 0)
        {
            for (unsigned int i=0; i<list_of_fields.size(); i++)
            {
               ui_file << "  <widget class=\"QLabel\" name=\"label_" << i+1 << "\">\n";
               ui_file << "   <property name=\"geometry\">\n";
               ui_file << "    <rect>\n";
               ui_file << "     <x>20</x>\n";
               ui_file << "     <y>" << (10+i*30) << "</y>\n";
               ui_file << "     <width>210</width>\n";
               ui_file << "     <height>16</height>\n";
               ui_file << "    </rect>\n";
               ui_file << "   </property>\n";
               ui_file << "   <property name=\"font\">\n";
               ui_file << "     <font>\n";
               ui_file << "      <pointsize>13</pointsize>\n";
               ui_file << "     </font>\n";
               ui_file << "    </property>\n";
               ui_file << "    <property name=\"text\">\n";

               if (app_settings.get_remove_unnecessary_spaces() == 1)
               {
                    ui_file << "     <string>" << it->text <<"</string>\n";
               }
               else
               {
                    trim(it->text);
                    ui_file << "     <string>" << it->text <<"</string>\n";
               }

               ui_file << "    </property>\n";

               if ((app_settings.get_centering_a_string_horizontally() == 1) && (app_settings.get_centering_a_string_vertically() == 1))
               {
                   ui_file << "    <property name=\"alignment\"\n>";
                   ui_file << "     <set>Qt::AlignCenter</set>\n";
                   ui_file << "    </property>\n";
               }
               else if ((app_settings.get_centering_a_string_horizontally() == 0) && (app_settings.get_centering_a_string_vertically() == 1))
               {
                   ui_file << "    <property name=\"alignment\"\n>";
                   ui_file << "     <set>Qt::AlignBottom|Qt::AlignHCenter</set>\n";
                   ui_file << "    </property>\n";
               }
               else if ((app_settings.get_centering_a_string_horizontally() == 1) && (app_settings.get_centering_a_string_vertically() == 0))
               {
                   ui_file << "    <property name=\"alignment\"\n>";
                   ui_file << "     <set>Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter</set>n";
                   ui_file << "    </property>\n";
               }

               ui_file << "   </widget>\n";

               ui_file << "  <widget class=\"QLineEdit\" name=\"lineEdit_" << i+1 << "\">\n";
               ui_file << "   <property name=\"geometry\">\n";
               ui_file << "    <rect>\n";
               ui_file << "     <x>240</x>\n";
               ui_file << "     <y>" << (10+i*30) << "</y>\n";
               ui_file << "     <width>140</width>\n";
               ui_file << "     <height>20</height>\n";
               ui_file << "    </rect>\n";
               ui_file << "   </property>\n";
               ui_file << "  </widget>\n";

               it++;
            }
        }

        ui_file << "  <widget class=\"QPushButton\" name=\"pushButton\">\n";
        ui_file << "   <property name=\"geometry\">\n";
        ui_file << "    <rect>\n";
        ui_file << "     <x>140</x>\n";
        ui_file << "     <y>" << (20+list_of_fields.size()*30) << "</y>\n";
        ui_file << "     <width>120</width>\n";
        ui_file << "     <height>30</height>\n";
        ui_file << "    </rect>\n";
        ui_file << "   </property>\n";
        ui_file << "   <property name=\"font\">\n";
        ui_file << "    <font>\n";
        ui_file << "     <pointsize>11</pointsize>\n";
        ui_file << "    </font>\n";
        ui_file << "   </property>\n";
        ui_file << "   <property name=\"text\">\n";
        ui_file << "    <string>Button Text</string>\n";
        ui_file << "   </property>\n";
        ui_file << "  </widget>\n";

        ui_file << " </widget>\n";
        ui_file << " <resources/>\n";
        ui_file << " <connections/>\n";
        ui_file << "</ui>\n";
    }
    else
    {
        return false;
    }
    ui_file.close();
    return true;
}

bool create_h_file(std::string class_name, std::string dir)
{
    std::fstream ui_file;
    std::string file_name;
    std::string def_name;
    for (unsigned int i=0; i<class_name.length(); i++)
    {
        file_name += tolower(class_name[i]);
        def_name  += toupper(class_name[i]);
    }

    ui_file.open(dir+file_name+".h", std::ios::out | std::ios::trunc);

    if (ui_file.is_open() == true)
    {
        ui_file << "#ifndef " << def_name << "_H\n";
        ui_file << "#define " << def_name << "_H\n\n";
        ui_file << "#include <QDialog>\n\n";
        ui_file << "namespace Ui\n";
        ui_file << "{\n";
        ui_file << "\tclass " << class_name << ";\n";
        ui_file << "}\n\n";
        ui_file << "class " << class_name << ": public QDialog\n";
        ui_file << "{\n";
        ui_file << "private:\n";
        ui_file << "\tQ_OBJECT\n";
        ui_file << "\tUi::" << class_name << " *ui;\n\n";       
        ui_file << "private slots:\n";
        ui_file << "\tvoid on_pushButton_clicked();\n";
        ui_file << "public:\n";
        ui_file << "\texplicit " << class_name << "(QWidget *parent = 0);\n";
        ui_file << "\t~" << class_name << "();\n";
        ui_file << "};\n\n";
        ui_file << "#endif // " << def_name << "_H\n";
    }
    else
    {
        return false;
    }
    ui_file.close();
    return true;
}

bool create_cpp_file(std::string class_name, std::string dir, settings app_settings)
{
    bool is_int = false;
    bool is_float = false;

    std::list <struct structure>::iterator it = list_of_fields.begin();

    for (; it != list_of_fields.end(); it++)
    {
        if ((*it).type == 1)
        {
            is_int = true;
        }
        else if ((*it).type == 2)
        {
            is_float = true;
        }
    }

    std::fstream ui_file;
    std::string file_name;
    int licznik = 0;
    for (unsigned int i=0; i<class_name.length(); i++)
    {
        file_name += tolower(class_name[i]);
    }

    ui_file.open(dir+file_name+".cpp", std::ios::out | std::ios::trunc);

    if (ui_file.is_open() == true)
    {
        ui_file << "#include \"" << file_name << ".h\"\n";
        if (is_float == true)
        {
            ui_file << "#include <sstream>\n";
        }
        ui_file << "#include \"ui_" << file_name << ".h\"\n\n";

        if (is_int == true)
        {
            ui_file << "bool is_int (const std::string &s)\n";
            ui_file << "{\n";
            ui_file << "\treturn (strspn(s.c_str(), \"0123456789\") == s.size());\n";
            ui_file << "}\n";
        }

        if (is_float == true)
        {
            ui_file << "bool is_float (const std::string &s)\n";
            ui_file << "{\n";
            ui_file << "\tstd::istringstream iss(s);\n";
            ui_file << "\tfloat dummy;\n";
            ui_file << "\tiss >> std::noskipws >> dummy;\n";
            ui_file << "\treturn iss && iss.eof();\n";
            ui_file << "}\n";
        }

        ui_file << class_name << "::" << class_name << "(QWidget *parent) :\n";
        ui_file << "\tQDialog(parent),\n";
        ui_file << "\tui(new Ui::" << class_name << ")\n";
        ui_file << "\t{\n";
        ui_file << "\t\tui->setupUi(this);\n";
		
        if (app_settings.get_no_change_window_size() == 1)
        {
            ui_file << "\t\tthis->setFixedWidth(this->width());\n";
            ui_file << "\t\tthis->setFixedHeight(this->height());\n";
        }

        if (app_settings.get_without_a_question_mark() == 1)
        {
            ui_file << "\t\tthis->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);\n";
        }
		
        ui_file << "\t}\n\n";
        ui_file << class_name << "::~" << class_name << "()\n";
        ui_file << "{\n";
        ui_file << "\tdelete ui;\n";
        ui_file << "}\n";

        ui_file << "\nvoid " << class_name << "::on_pushButton_clicked()\n";
        ui_file << "{\n";
        ui_file << "\tbool error = false;\n";
        for (it = list_of_fields.begin(); it != list_of_fields.end(); it++)
        {
            switch ((*it).type)
            {
            case 0:
                ui_file << "\tif (ui->lineEdit_" << licznik+1 << "->text().length() <= 0)\n";
                ui_file << "\t{\n";
                ui_file << "\t\terror = true;\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : yellow; }\");\n";
                ui_file << "\t}\n";
                ui_file << "\telse\n";
                ui_file << "\t{\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : white; }\");\n";
                ui_file << "\t}\n";
                break;
            case 1:
                ui_file << "\tif ((is_int (ui->lineEdit_" << licznik+1 << "->text().toStdString() ) == false) || (ui->lineEdit_" << licznik+1 << "->text().length() <= 0) || (ui->lineEdit_" << licznik+1 << "->text().toInt() < " << (*it).min << ") || (ui->lineEdit_" << licznik+1 << "->text().toInt() > " << (*it).max << "))\n";
                ui_file << "\t{\n";
                ui_file << "\t\terror = true;\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : yellow; }\");\n";
                ui_file << "\t}\n";
                ui_file << "\telse\n";
                ui_file << "\t{\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : white; }\");\n";
                ui_file << "\t}\n";
                break;
            case 2:
                ui_file << "\tif ((is_float (ui->lineEdit_" << licznik+1 << "->text().toStdString() ) == false) || (ui->lineEdit_" << licznik+1 << "->text().length() <= 0) || (ui->lineEdit_" << licznik+1 << "->text().toFloat() < " << (*it).min << ") || (ui->lineEdit_" << licznik+1 << "->text().toFloat() > " << (*it).max << "))\n";
                ui_file << "\t{\n";
                ui_file << "\t\terror = true;\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : yellow; }\");\n";
                ui_file << "\t}\n";
                ui_file << "\telse\n";
                ui_file << "\t{\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : white; }\");\n";
                ui_file << "\t}\n";
            break;
            case 3:
                ui_file << "\tif ((is_int (ui->lineEdit_" << licznik+1 << "->text().toStdString() ) == false) || (ui->lineEdit_" << licznik+1 << "->text().length() <= 0) || (ui->lineEdit_" << licznik+1 << "->text().length() < " << (*it).min << ") || (ui->lineEdit_" << licznik+1 << "->text().length() > " << (*it).max << "))\n";
                ui_file << "\t{\n";
                ui_file << "\t\terror = true;\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : yellow; }\");\n";
                ui_file << "\t}\n";
                ui_file << "\telse\n";
                ui_file << "\t{\n";
                ui_file << "\t\tui->lineEdit_" << licznik+1 << "->setStyleSheet(\"QLineEdit { background-color : white; }\");\n";
                ui_file << "\t}\n";
            break;
            }
            licznik++;
        }
        ui_file << "\tif (error == false)\n";
        ui_file << "\t{\n";
        ui_file << "\t\tthis->close();\n";
        ui_file << "\t}\n";
        ui_file << "}\n";

    }
    else
    {
        return false;
    }
    ui_file.close();
    return true;
}

void trim (std::string &s)
{
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ')+1);
}


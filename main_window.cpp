#include "main_window.h"
#include "ui_main_window.h"
#include "done_window.h"
#include "error.h"
#include "create_files.h"
#include "new_float.h"
#include "new_int.h"
#include "new_string.h"
#include "language.h"
#include "new_no_validation.h"
#include "structure.h"
#include "aboutwindow.h"
#include <QFileDialog>
#include <list>

std::list <struct structure> list_of_fields;

main_window::main_window(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::main_window)
    {
        ui->setupUi(this);
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        app_settings = new settings();
        app_language = new language(app_settings->get_language());

        set_the_buttons();
        set_the_lang();
    }

main_window::~main_window()
{
    app_settings->save_file();
    delete ui;
}

void main_window::on_actionExit_triggered()
{
    this->close();
}

void main_window::on_lineEdit_2_selectionChanged()
{
    ui->lineEdit_2->setText (QFileDialog::getExistingDirectory(this, QString::fromStdString(app_language->get_app_choose_dir()), ""));

    if (ui->lineEdit_2->text().length() > 2)
    {
        if (ui->lineEdit_2->text().toStdString().at(ui->lineEdit_2->text().toStdString().length()-1) != '/')
        {
            ui->lineEdit_2->setText(ui->lineEdit_2->text()+"/");
        }
    }
}

void main_window::set_the_buttons()
{
    ui->actionCentering_a_string_horizontally->setChecked(settings::get_centering_a_string_horizontally());
    ui->actionCentering_a_string_vertically->setChecked(settings::get_centering_a_string_vertically());
    ui->action_No_change_window_size->setChecked(settings::get_no_change_window_size());
    ui->actionWithout_a_question_mark->setChecked(settings::get_without_a_question_mark());
    ui->actionRemove_unnecessary_spaces->setChecked(settings::get_remove_unnecessary_spaces());
}

void main_window::set_the_lang()
{
    ui->menuSettings->setTitle(QString::fromStdString(this->app_language->get_menu_settings()));
    ui->menuLanguage->setTitle(QString::fromStdString(this->app_language->get_menu_language()));
    ui->actionPolski->setText(QString::fromStdString(this->app_language->get_menu_language_polish()));
    ui->actionEnglish->setText(QString::fromStdString(this->app_language->get_menu_language_english()));
    ui->menuDefault_checking->setTitle(QString::fromStdString(this->app_language->get_menu_default_settings()));
    ui->actionCentering_a_string_horizontally->setText(QString::fromStdString(this->app_language->get_menu_centering_a_string_horizontally()));
    ui->actionCentering_a_string_vertically->setText(QString::fromStdString(this->app_language->get_menu_centering_a_string_vertically()));
    ui->action_No_change_window_size->setText(QString::fromStdString(this->app_language->get_menu_no_change_window_size()));
    ui->actionWithout_a_question_mark->setText(QString::fromStdString(this->app_language->get_menu_without_a_question_mark()));
    ui->actionRemove_unnecessary_spaces->setText(QString::fromStdString(this->app_language->get_menu_remove_unnecessary_spaces()));
    ui->actionExit->setText(QString::fromStdString(this->app_language->get_menu_exit()));
    ui->actionAbout_program->setText(QString::fromStdString(this->app_language->get_menu_about_program()));
    ui->dialog_class_name->setText(QString::fromStdString(this->app_language->get_app_dialog_class_name()));
    ui->dir_with_source_code->setText(QString::fromStdString(this->app_language->get_app_dir_with_source_code()));
    ui->create_dialog->setText(QString::fromStdString(this->app_language->get_app_create_dialog()));
    ui->pushButton->setText(QString::fromStdString(this->app_language->get_app_no_validation()));
    ui->pushButton_2->setText(QString::fromStdString(this->app_language->get_app_new_string()));
    ui->pushButton_3->setText(QString::fromStdString(this->app_language->get_app_new_float()));
    ui->pushButton_4->setText(QString::fromStdString(this->app_language->get_app_new_int()));
}

void main_window::on_actionEnglish_triggered()
{
    settings::set_language("English");
    language::set_language("English");
    set_the_lang();
}

void main_window::on_actionPolski_triggered()
{
    settings::set_language("polski");
    language::set_language("polski");
    set_the_lang();
}

void main_window::on_create_dialog_clicked()
{
    if (list_of_fields.empty() == true)
    {
        error *w = new error (NULL, app_language->get_app_no_fields());
        w->exec();
        return;
    }

    bool some_error = false;

    if (ui->lineEdit->text().toStdString() == "")
    {
        some_error = true;
        ui->lineEdit->setStyleSheet("QLineEdit { background-color : yellow; }");
    }
    else
    {
        ui->lineEdit->setStyleSheet("QLineEdit { background-color : white; }");
    }

    if (ui->lineEdit_2->text().toStdString() == "")
    {
        some_error = true;
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color : yellow; }");
    }
    else
    {
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color : white; }");
    }

    if (some_error == false)
    {
        bool error_creating_files = true;
        if (create_ui_file(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString(), *(app_settings)) == false)
        {
            error_creating_files = false;
        }

        if (create_h_file(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString()) == false)
        {
            error_creating_files = false;
        }

        if (create_cpp_file(ui->lineEdit->text().toStdString(), ui->lineEdit_2->text().toStdString(), *(app_settings)) == false)
        {
            error_creating_files = false;
        }

        if (error_creating_files == false)
        {
            error *w = new error (NULL, app_language->get_error_creating_files());
            w->exec();
            exit(1);
        }
        else
        {
            if (list_of_fields.size() > 0)
            {
                list_of_fields.clear();
            }

            done_window w(this, app_language);
            w.exec();
        }
    }
}

void main_window::on_actionCentering_a_string_horizontally_triggered(bool checked)
{
    if (checked == true)
    {
        settings::set_centering_a_string_horizontally (1);
    }
    else
    {
        settings::set_centering_a_string_horizontally (0);
    }
    app_settings->save_file();
}

void main_window::on_actionCentering_a_string_vertically_triggered(bool checked)
{
    if (checked == true)
    {
        settings::set_centering_a_string_vertically (1);
    }
    else
    {
        settings::set_centering_a_string_vertically (0);
    }
    app_settings->save_file();
}

void main_window::on_action_No_change_window_size_triggered(bool checked)
{
    if (checked == true)
    {
        settings::set_no_change_window_size (1);
    }
    else
    {
        settings::set_no_change_window_size (0);
    }
    app_settings->save_file();;
}

void main_window::on_actionWithout_a_question_mark_triggered(bool checked)
{
    if (checked == true)
    {
        settings::set_without_a_question_mark (1);
    }
    else
    {
        settings::set_without_a_question_mark (0);
    }
    app_settings->save_file();;
}

void main_window::on_actionRemove_unnecessary_spaces_triggered(bool checked)
{
    if (checked == true)
    {
        settings::set_remove_unnecessary_spaces (1);
    }
    else
    {
        settings::set_remove_unnecessary_spaces (0);
    }
    app_settings->save_file();
}

void main_window::on_pushButton_4_clicked()
{
    new_int *w = new new_int (this);
    w->exec();
}

void main_window::on_pushButton_3_clicked()
{
    new_float *w = new new_float (this);
    w->exec();
}

void main_window::on_pushButton_2_clicked()
{
    new_string *w = new new_string (this);
    w->exec();
}

void main_window::on_pushButton_clicked()
{
    new_no_validation *w = new new_no_validation (this);
    w->exec();
}

void main_window::on_actionAbout_program_triggered()
{
    AboutWindow *w = new AboutWindow (this, app_language);
    w->exec();
}

#include "new_int.h"
#include "ui_new_int_window.h"
#include "main_window.h"
#include "language.h"
#include "structure.h"

extern std::list <struct structure> list_of_fields;

new_int::new_int(QWidget *parent, language *app_language):
    QDialog(parent),
    ui(new Ui::new_int)
    {
        ui->setupUi(this);
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        this->setWindowTitle (QString::fromStdString(app_language->get_app_new_field()));
        ui->dir_with_source_code_2->setText(QString::fromStdString(app_language->get_app_new_text_field()));
        ui->dir_with_source_code->setText(QString::fromStdString(app_language->get_app_new_min_value()));
        ui->dir_with_source_code_3->setText(QString::fromStdString(app_language->get_app_new_max_value()));
        ui->pushButton->setText(QString::fromStdString(app_language->get_app_new_button()));
    }

new_int::~new_int()
{
    delete ui;
}

void new_int::on_pushButton_clicked()
{
    bool error = false;

    if (ui->lineEdit->text().length() <= 0)
    {
        error = true;
        ui->lineEdit->setStyleSheet("QLineEdit { background-color : yellow; }");
    }
    else
    {
        ui->lineEdit->setStyleSheet("QLineEdit { background-color : white; }");
    }

    if (is_int(ui->lineEdit_2->text().toStdString()) == false)
    {
        error = true;
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color : yellow; }");
    }
    else
    {
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color : white; }");
    }

    if ((is_int(ui->lineEdit_3->text().toStdString()) == false) || (ui->lineEdit_3->text().toInt() < ui->lineEdit_2->text().toInt()))
    {
        error = true;
        ui->lineEdit_3->setStyleSheet("QLineEdit { background-color : yellow; }");
    }
    else
    {
        ui->lineEdit_3->setStyleSheet("QLineEdit { background-color : white; }");
    }

    if (error == false)
    {
        struct structure add_field;
        add_field.text = ui->lineEdit->text().toStdString();
        add_field.type = 1;
        add_field.min = ui->lineEdit_2->text().toFloat();
        add_field.max = ui->lineEdit_3->text().toFloat();
        list_of_fields.push_front(add_field);
        this->close();
    }
}

bool new_int::is_int (const std::string &s)
{
    return (strspn(s.c_str(), "0123456789") == s.size());
}

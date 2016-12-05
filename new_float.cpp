#include "new_float.h"
#include "ui_new_float_window.h"
#include "main_window.h"
#include "language.h"
#include "structure.h"
#include <sstream>

extern std::list <struct structure> list_of_fields;

new_float::new_float(QWidget *parent, language *app_language):
    QDialog(parent),
    ui(new Ui::new_float)
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

new_float::~new_float()
{
    delete ui;
}

void new_float::on_pushButton_clicked()
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

    if (is_float(ui->lineEdit_2->text().toStdString()) == false)
    {
        error = true;
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color : yellow; }");
    }
    else
    {
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color : white; }");
    }

    if ((is_float(ui->lineEdit_3->text().toStdString()) == false) || (ui->lineEdit_3->text().toFloat() < ui->lineEdit_2->text().toFloat()))
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
        add_field.type = 2;
        add_field.min = ui->lineEdit_2->text().toFloat();
        add_field.max = ui->lineEdit_3->text().toFloat();
        list_of_fields.push_back(add_field);
        this->close();
    }
}

bool new_float::is_float (const std::string &s)
{
    std::istringstream iss(s);
    float dummy;
    iss >> std::noskipws >> dummy;
    return iss && iss.eof();
}

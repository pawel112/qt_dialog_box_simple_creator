#include "new_no_validation.h"
#include "ui_new_no_validation_window.h"
#include "main_window.h"
#include "language.h"
#include "structure.h"

extern std::list <struct structure> list_of_fields;

new_no_validation::new_no_validation(QWidget *parent, language *app_language):
    QDialog(parent),
    ui(new Ui::new_no_validation)
    {
        ui->setupUi(this);
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        this->setWindowTitle (QString::fromStdString(app_language->get_app_new_field()));
        ui->dir_with_source_code_2->setText(QString::fromStdString(app_language->get_app_new_text_field()));
        ui->pushButton->setText(QString::fromStdString(app_language->get_app_new_button()));
    }

new_no_validation::~new_no_validation()
{
    delete ui;
}

void new_no_validation::on_pushButton_clicked()
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

    if (error == false)
    {
        struct structure add_field;
        add_field.text = ui->lineEdit->text().toStdString();
        add_field.type = 0;
        add_field.min = 0;
        add_field.max = 0;
        list_of_fields.push_back(add_field);
        this->close();
    }
}

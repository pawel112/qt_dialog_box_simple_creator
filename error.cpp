#include "error.h"
#include "ui_error_window.h"

error::error(QWidget *parent, std::string message):
    QDialog(parent),
    ui(new Ui::error)
    {
        ui->setupUi(this);
        ui->label->setText(QString::fromStdString(ui->label->text().toStdString()+message));
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
    }

error::~error()
{
    delete ui;
}

void error::on_pushButton_clicked()
{
    this->close();
}

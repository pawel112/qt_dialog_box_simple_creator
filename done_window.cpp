#include "done_window.h"
#include "ui_done_window.h"
#include "language.h"

done_window::done_window(QWidget *parent, language *app_language):
    QDialog(parent),
    ui(new Ui::done_window)
    {
        ui->setupUi(this);
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        ui->label->setText(QString::fromStdString(app_language->get_app_donation()));
        ui->pushButton->setText(QString::fromStdString(app_language->get_menu_exit()));
    }

done_window::~done_window()
{
    delete ui;
}

void done_window::on_pushButton_clicked()
{
    this->close();
}

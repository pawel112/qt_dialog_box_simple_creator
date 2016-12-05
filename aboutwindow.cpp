#include "aboutwindow.h"
#include "ui_about_window.h"
#include "language.h"

AboutWindow::AboutWindow(QWidget *parent, language *app_language) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
    {
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        ui->setupUi(this);
        this->setFixedHeight(this->height());
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        this->setWindowTitle(QString::fromStdString(app_language->get_menu_about_program()));
        ui->pushButton->setText(QString::fromStdString(app_language->get_menu_exit()));
        ui->paypalButton->setText(QString::fromStdString(app_language->get_app_donation()));
    }

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_pushButton_clicked()
{
    this->close();
}

void AboutWindow::on_paypalButton_clicked()
{
    if (language::get_menu_language() == "Język")
    {
        QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=paypal%40roszatycki%2epl&lc=US&item_name=Darowizna%20%2d%20Dialog%20box%20simple%20creator&no_note=0&currency_code=PLN&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHostedGuest"));
    }
    else
    {
        QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=paypal%40roszatycki%2epl&lc=US&item_name=Darowizna%20%2d%20Dialog%20box%20simple%20creator&no_note=0&currency_code=USD&bn=PP%2dDonationsBF%3abtn_donateCC_LG%2egif%3aNonHostedGuest"));
    }
}

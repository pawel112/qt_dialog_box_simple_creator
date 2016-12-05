#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include "language.h"
#include <QDialog>
#include <QDesktopServices>
#include <QUrl>

namespace Ui
{
    class AboutWindow;
}

class AboutWindow: public QDialog
{
private:
    Ui::AboutWindow *ui;
    Q_OBJECT
private slots:
    void on_pushButton_clicked();
    void on_paypalButton_clicked();

public:
    explicit AboutWindow(QWidget *parent = 0, language *app_language = NULL);
    ~AboutWindow();
};

#endif

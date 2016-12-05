#ifndef DONE_WINDOW_H
#define DONE_WINDOW_H

#include "language.h"
#include <QDialog>

namespace Ui
{
    class done_window;
}

class done_window: public QDialog
{   
private:
    Q_OBJECT
    Ui::done_window *ui;

private slots:
    void on_pushButton_clicked();

public:
    explicit done_window(QWidget *parent = 0, language *app_language = NULL);
    ~done_window();
};

#endif // DONE_WINDOW_H

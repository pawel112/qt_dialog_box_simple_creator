#ifndef NEW_STRING_H
#define NEW_STRING_H

#include "language.h"
#include <QDialog>
#include <list>

namespace Ui
{
    class new_string;
}

class new_string: public QDialog
{
private:
    Q_OBJECT
    Ui::new_string *ui;

private slots:
    void on_pushButton_clicked();

public:
    bool is_int (const std::string &s);
    explicit new_string(QWidget *parent = 0, language *app_language = NULL);
    ~new_string();
};

#endif // NEW_STRING_H

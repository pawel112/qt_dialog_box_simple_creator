#ifndef NEW_INT_H
#define NEW_INT_H

#include "language.h"
#include <QDialog>
#include <list>

namespace Ui
{
    class new_int;
}

class new_int: public QDialog
{
private:
    Q_OBJECT
    Ui::new_int *ui;

private slots:
    void on_pushButton_clicked();

public:
    bool is_int (const std::string &s);
    explicit new_int(QWidget *parent = 0, language *app_language = NULL);
    ~new_int();
};

#endif // NEW_INT_H

#ifndef NEW_FLOAT_H
#define NEW_FLOAT_H

#include "language.h"
#include <QDialog>
#include <list>

namespace Ui
{
    class new_float;
}

class new_float: public QDialog
{
private:
    Q_OBJECT
    Ui::new_float *ui;

private slots:
    void on_pushButton_clicked();

public:
    bool is_float (const std::string &s);
    explicit new_float(QWidget *parent = 0, language *app_language = NULL);
    ~new_float();
};

#endif // NEW_FLOAT_H

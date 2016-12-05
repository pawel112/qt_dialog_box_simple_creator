#ifndef NEW_NO_VALIDATION_H
#define NEW_NO_VALIDATION_H

#include "language.h"
#include <QDialog>
#include <list>

namespace Ui
{
    class new_no_validation;
}

class new_no_validation: public QDialog
{
private:
    Q_OBJECT
    Ui::new_no_validation *ui;

private slots:
    void on_pushButton_clicked();

public:
    explicit new_no_validation(QWidget *parent = 0, language *app_language = NULL);
    ~new_no_validation();
};

#endif // NEW_NO_VALIDATION_H

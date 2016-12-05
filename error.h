#ifndef ERROR_H
#define ERROR_H

#include <QDialog>

namespace Ui
{
    class error;
}

class error: public QDialog
{
private:
    Q_OBJECT
    Ui::error *ui;

public:
    explicit error(QWidget *parent = 0, std::string message = "");
    ~error();

private slots:
    void on_pushButton_clicked();
};

#endif // ERROR_H

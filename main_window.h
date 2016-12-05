#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "settings.h"
#include "language.h"
#include "structure.h"
#include <QMainWindow>
#include <list>

namespace Ui
{
    class main_window;
}

class main_window: public QMainWindow
{
private:
    Q_OBJECT
    Ui::main_window *ui;

private slots:
    void on_actionExit_triggered();
    void on_lineEdit_2_selectionChanged();
    void on_actionEnglish_triggered();
    void on_actionPolski_triggered();
    void on_create_dialog_clicked();
    void on_actionCentering_a_string_horizontally_triggered(bool checked);
    void on_actionCentering_a_string_vertically_triggered(bool checked);
    void on_action_No_change_window_size_triggered(bool checked);
    void on_actionWithout_a_question_mark_triggered(bool checked);
    void on_actionRemove_unnecessary_spaces_triggered(bool checked);
    void on_pushButton_4_clicked();  
    void on_pushButton_3_clicked();   
    void on_pushButton_2_clicked();   
    void on_pushButton_clicked();
    
    void on_actionAbout_program_triggered();

public:
    explicit main_window(QWidget *parent = 0);
    settings *app_settings;
    language *app_language;
    void set_the_buttons();
    void set_the_lang();
    void set_centering_a_string_horizontally (unsigned int centering_a_string_horizontally);
    void set_centering_a_string_vertically (unsigned int centering_a_string_vertically);
    void set_no_change_window_size (unsigned int no_change_window_size);
    void set_without_a_question_mark (unsigned int without_a_question_mark);
    void set_remove_unnecessary_spaces (unsigned int remove_unnecessary_spaces);
    ~main_window();
};

#endif // MAIN_WINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_saveButton_clicked();

    void on_resetButton_clicked();

    void on_author_text_textChanged(const QString &arg1);

    void on_name_text_textChanged(const QString &arg1);

    void on_id_text_textChanged(const QString &arg1);

    void on_book_filling_textChanged(const QString &arg1);

    void on_paper_button_clicked();

    void on_electronic_button_toggled(bool checked);


    void on_genre1_checkBox_stateChanged(int arg1);

    void on_genre2_checkBox_stateChanged(int arg1);

    void on_genre3_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QButtonGroup *publicationGroup;
};
#endif // MAINWINDOW_H

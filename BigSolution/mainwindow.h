#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "./FindDialog/FindDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_findDlg_clicked();

private:
    Ui::MainWindow *ui;
    CFindDialog *m_pFindDlg;
};

#endif // MAINWINDOW_H

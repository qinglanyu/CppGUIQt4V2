#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pFindDlg(NULL)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findDlg_clicked()
{

    if(!m_pFindDlg)
    {
        m_pFindDlg = new CFindDialog;
    }
    m_pFindDlg->show();
}

#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class CFindDialog;
}

class CFindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CFindDialog(QWidget *parent = 0);
    ~CFindDialog();

private slots:
    void enableFindButton(const QString&);
    void findClicked();

signals:
    void findPrevious(const QString &, Qt::CaseSensitivity);
    void findNext(const QString &, Qt::CaseSensitivity);

private:
    Ui::CFindDialog *ui;
};

#endif // FINDDIALOG_H

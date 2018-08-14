#include "FindDialog.h"
#include "ui_FindDialog.h"

#include <QLayout>

CFindDialog::CFindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CFindDialog)
{
    ui->setupUi(this);

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(ui->label);
    topLeftLayout->addWidget(ui->lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(ui->caseChkBox);
    leftLayout->addWidget(ui->backwardChkBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(ui->findButton);
    rightLayout->addWidget(ui->closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setFixedHeight(sizeHint().height());
}

CFindDialog::~CFindDialog()
{
    delete ui;
}

void CFindDialog::enableFindButton(const QString &text)
{
    ui->findButton->setEnabled(!text.isEmpty());
}

void CFindDialog::findClicked()
{
    QString text = ui->lineEdit->text();
    Qt::CaseSensitivity cs = ui->caseChkBox->isChecked()? Qt::CaseSensitive:Qt::CaseInsensitive;

    if(ui->backwardChkBox->isChecked())
    {
        emit findPrevious(text, cs);
    }
    else
    {
        emit findNext(text, cs);
    }

}

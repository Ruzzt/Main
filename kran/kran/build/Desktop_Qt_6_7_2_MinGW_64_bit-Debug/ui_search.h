/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label_Search;
    QLineEdit *lineEdit_Search;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName("Search");
        Search->resize(350, 80);
        Search->setMaximumSize(QSize(16777215, 80));
        Search->setWindowTitle(QString::fromUtf8("Dialog"));
        gridLayout = new QGridLayout(Search);
        gridLayout->setObjectName("gridLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_Search = new QLabel(Search);
        label_Search->setObjectName("label_Search");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_Search);

        lineEdit_Search = new QLineEdit(Search);
        lineEdit_Search->setObjectName("lineEdit_Search");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_Search);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Search);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(Search);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Search, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Search, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        label_Search->setText(QCoreApplication::translate("Search", "Search:", nullptr));
        (void)Search;
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H

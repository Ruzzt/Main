/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QDialogButtonBox *buttonBox;
    QFormLayout *formLayout;
    QLabel *iDLabel;
    QSpinBox *iDSpinBox;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QLabel *maxweightLabel;
    QSpinBox *maxweightSpinBox;
    QLabel *ratingLabel;
    QSpinBox *ratingSpinBox;
    QLabel *peopleLabel;
    QSpinBox *peopleSpinBox;
    QLabel *contactNumberLabel;
    QLineEdit *contactNumberLineEdit;
    QLabel *yearsLabel;
    QSpinBox *yearsSpinBox;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName("EditDialog");
        EditDialog->resize(542, 300);
        EditDialog->setMaximumSize(QSize(16777215, 300));
        EditDialog->setWindowTitle(QString::fromUtf8("Dialog"));
        verticalLayout = new QVBoxLayout(EditDialog);
        verticalLayout->setObjectName("verticalLayout");
        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        iDLabel = new QLabel(EditDialog);
        iDLabel->setObjectName("iDLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, iDLabel);

        iDSpinBox = new QSpinBox(EditDialog);
        iDSpinBox->setObjectName("iDSpinBox");

        formLayout->setWidget(0, QFormLayout::FieldRole, iDSpinBox);

        nameLabel = new QLabel(EditDialog);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(EditDialog);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, nameLineEdit);

        addressLabel = new QLabel(EditDialog);
        addressLabel->setObjectName("addressLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, addressLabel);

        addressLineEdit = new QLineEdit(EditDialog);
        addressLineEdit->setObjectName("addressLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, addressLineEdit);

        maxweightLabel = new QLabel(EditDialog);
        maxweightLabel->setObjectName("maxweightLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, maxweightLabel);

        maxweightSpinBox = new QSpinBox(EditDialog);
        maxweightSpinBox->setObjectName("maxweightSpinBox");

        formLayout->setWidget(3, QFormLayout::FieldRole, maxweightSpinBox);

        ratingLabel = new QLabel(EditDialog);
        ratingLabel->setObjectName("ratingLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, ratingLabel);

        ratingSpinBox = new QSpinBox(EditDialog);
        ratingSpinBox->setObjectName("ratingSpinBox");

        formLayout->setWidget(4, QFormLayout::FieldRole, ratingSpinBox);

        peopleLabel = new QLabel(EditDialog);
        peopleLabel->setObjectName("peopleLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, peopleLabel);

        peopleSpinBox = new QSpinBox(EditDialog);
        peopleSpinBox->setObjectName("peopleSpinBox");

        formLayout->setWidget(5, QFormLayout::FieldRole, peopleSpinBox);

        contactNumberLabel = new QLabel(EditDialog);
        contactNumberLabel->setObjectName("contactNumberLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, contactNumberLabel);

        contactNumberLineEdit = new QLineEdit(EditDialog);
        contactNumberLineEdit->setObjectName("contactNumberLineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, contactNumberLineEdit);

        yearsLabel = new QLabel(EditDialog);
        yearsLabel->setObjectName("yearsLabel");

        formLayout->setWidget(7, QFormLayout::LabelRole, yearsLabel);

        yearsSpinBox = new QSpinBox(EditDialog);
        yearsSpinBox->setObjectName("yearsSpinBox");

        formLayout->setWidget(7, QFormLayout::FieldRole, yearsSpinBox);


        verticalLayout->addLayout(formLayout);


        retranslateUi(EditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        iDLabel->setText(QCoreApplication::translate("EditDialog", "ID", nullptr));
        nameLabel->setText(QCoreApplication::translate("EditDialog", "Name", nullptr));
        addressLabel->setText(QCoreApplication::translate("EditDialog", "Address", nullptr));
        maxweightLabel->setText(QCoreApplication::translate("EditDialog", "Maxweight", nullptr));
        ratingLabel->setText(QCoreApplication::translate("EditDialog", "Rating", nullptr));
        peopleLabel->setText(QCoreApplication::translate("EditDialog", "People", nullptr));
        contactNumberLabel->setText(QCoreApplication::translate("EditDialog", "ContactNumber", nullptr));
        yearsLabel->setText(QCoreApplication::translate("EditDialog", "Years", nullptr));
        (void)EditDialog;
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H

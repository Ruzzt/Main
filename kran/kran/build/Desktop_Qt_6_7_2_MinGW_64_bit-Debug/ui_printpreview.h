/********************************************************************************
** Form generated from reading UI file 'printpreview.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTPREVIEW_H
#define UI_PRINTPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PrintPreview
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PrintPreview)
    {
        if (PrintPreview->objectName().isEmpty())
            PrintPreview->setObjectName("PrintPreview");
        PrintPreview->resize(800, 800);
        verticalLayout = new QVBoxLayout(PrintPreview);
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(PrintPreview);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        buttonBox = new QDialogButtonBox(PrintPreview);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PrintPreview);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PrintPreview, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PrintPreview, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PrintPreview);
    } // setupUi

    void retranslateUi(QDialog *PrintPreview)
    {
        PrintPreview->setWindowTitle(QCoreApplication::translate("PrintPreview", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrintPreview: public Ui_PrintPreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTPREVIEW_H

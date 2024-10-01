/********************************************************************************
** Form generated from reading UI file 'clientmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMANAGERFORM_H
#define UI_CLIENTMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientManagerForm
{
public:
    QHBoxLayout *horizontalLayout_4;
    QSplitter *splitter;
    QListWidget *listWidget;
    QToolBox *toolBox;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_4;
    QLabel *labelID;
    QLabel *labelName;
    QLabel *labelAddress;
    QLabel *labelPhoneNumber;
    QLineEdit *lineEditID;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPhoneNumber;
    QLineEdit *lineEditAddress;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButtonModify;
    QWidget *SearchPage;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidgetSearch;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditSearch;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ClientManagerForm)
    {
        if (ClientManagerForm->objectName().isEmpty())
            ClientManagerForm->setObjectName("ClientManagerForm");
        ClientManagerForm->resize(430, 300);
        horizontalLayout_4 = new QHBoxLayout(ClientManagerForm);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        splitter = new QSplitter(ClientManagerForm);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(splitter);
        listWidget->setObjectName("listWidget");
        splitter->addWidget(listWidget);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName("toolBox");
        inputPage = new QWidget();
        inputPage->setObjectName("inputPage");
        inputPage->setGeometry(QRect(0, 0, 207, 240));
        verticalLayout = new QVBoxLayout(inputPage);
        verticalLayout->setObjectName("verticalLayout");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        labelID = new QLabel(inputPage);
        labelID->setObjectName("labelID");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, labelID);

        labelName = new QLabel(inputPage);
        labelName->setObjectName("labelName");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, labelName);

        labelAddress = new QLabel(inputPage);
        labelAddress->setObjectName("labelAddress");

        formLayout_4->setWidget(3, QFormLayout::LabelRole, labelAddress);

        labelPhoneNumber = new QLabel(inputPage);
        labelPhoneNumber->setObjectName("labelPhoneNumber");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, labelPhoneNumber);

        lineEditID = new QLineEdit(inputPage);
        lineEditID->setObjectName("lineEditID");
        lineEditID->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEditID);

        lineEditName = new QLineEdit(inputPage);
        lineEditName->setObjectName("lineEditName");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEditName);

        lineEditPhoneNumber = new QLineEdit(inputPage);
        lineEditPhoneNumber->setObjectName("lineEditPhoneNumber");

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEditPhoneNumber);

        lineEditAddress = new QLineEdit(inputPage);
        lineEditAddress->setObjectName("lineEditAddress");

        formLayout_4->setWidget(3, QFormLayout::FieldRole, lineEditAddress);


        verticalLayout->addLayout(formLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(inputPage);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButtonModify = new QPushButton(inputPage);
        pushButtonModify->setObjectName("pushButtonModify");

        horizontalLayout->addWidget(pushButtonModify);


        verticalLayout->addLayout(horizontalLayout);

        toolBox->addItem(inputPage, QString::fromUtf8("Input"));
        SearchPage = new QWidget();
        SearchPage->setObjectName("SearchPage");
        SearchPage->setGeometry(QRect(0, 0, 207, 240));
        verticalLayout_2 = new QVBoxLayout(SearchPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        listWidgetSearch = new QListWidget(SearchPage);
        listWidgetSearch->setObjectName("listWidgetSearch");

        verticalLayout_2->addWidget(listWidgetSearch);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_5 = new QLabel(SearchPage);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        lineEditSearch = new QLineEdit(SearchPage);
        lineEditSearch->setObjectName("lineEditSearch");

        horizontalLayout_2->addWidget(lineEditSearch);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_3 = new QPushButton(SearchPage);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        toolBox->addItem(SearchPage, QString::fromUtf8("Search"));
        splitter->addWidget(toolBox);

        horizontalLayout_4->addWidget(splitter);

#if QT_CONFIG(shortcut)
        labelID->setBuddy(lineEditID);
        labelName->setBuddy(lineEditName);
        labelAddress->setBuddy(lineEditAddress);
        labelPhoneNumber->setBuddy(lineEditPhoneNumber);
        label_5->setBuddy(lineEditSearch);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ClientManagerForm);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ClientManagerForm)
    {
        ClientManagerForm->setWindowTitle(QCoreApplication::translate("ClientManagerForm", "Form", nullptr));
        labelID->setText(QCoreApplication::translate("ClientManagerForm", "&ID", nullptr));
        labelName->setText(QCoreApplication::translate("ClientManagerForm", "&Name", nullptr));
        labelAddress->setText(QCoreApplication::translate("ClientManagerForm", "&Address", nullptr));
        labelPhoneNumber->setText(QCoreApplication::translate("ClientManagerForm", "&Phone Number", nullptr));
        pushButton->setText(QCoreApplication::translate("ClientManagerForm", "&Add", nullptr));
        pushButtonModify->setText(QCoreApplication::translate("ClientManagerForm", "&Modify", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ClientManagerForm", "Input", nullptr));
        label_5->setText(QCoreApplication::translate("ClientManagerForm", "&ID", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ClientManagerForm", "Search", nullptr));
        toolBox->setItemText(toolBox->indexOf(SearchPage), QCoreApplication::translate("ClientManagerForm", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientManagerForm: public Ui_ClientManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMANAGERFORM_H

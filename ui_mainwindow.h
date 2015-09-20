/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *open_pushButton;
    QLabel *label;
    QSlider *brightness_horizontalSlider;
    QPushButton *grayscale_pushButton;
    QLabel *label_2;
    QSlider *red_horizontalSlider;
    QSlider *green_horizontalSlider;
    QSlider *blue_horizontalSlider;
    QPushButton *blur_pushButton;
    QPushButton *save_pushButton;
    QPushButton *negative_pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *contrast_horizontalSlider;
    QLabel *label_6;
    QPushButton *clear_pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(818, 594);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        open_pushButton = new QPushButton(centralWidget);
        open_pushButton->setObjectName(QStringLiteral("open_pushButton"));
        open_pushButton->setGeometry(QRect(20, 10, 111, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 90, 450, 300));
        brightness_horizontalSlider = new QSlider(centralWidget);
        brightness_horizontalSlider->setObjectName(QStringLiteral("brightness_horizontalSlider"));
        brightness_horizontalSlider->setGeometry(QRect(590, 290, 160, 22));
        brightness_horizontalSlider->setMinimum(-255);
        brightness_horizontalSlider->setMaximum(255);
        brightness_horizontalSlider->setOrientation(Qt::Horizontal);
        grayscale_pushButton = new QPushButton(centralWidget);
        grayscale_pushButton->setObjectName(QStringLiteral("grayscale_pushButton"));
        grayscale_pushButton->setGeometry(QRect(530, 40, 111, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(500, 290, 81, 21));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        red_horizontalSlider = new QSlider(centralWidget);
        red_horizontalSlider->setObjectName(QStringLiteral("red_horizontalSlider"));
        red_horizontalSlider->setGeometry(QRect(590, 350, 160, 22));
        red_horizontalSlider->setMinimum(-255);
        red_horizontalSlider->setMaximum(255);
        red_horizontalSlider->setOrientation(Qt::Horizontal);
        green_horizontalSlider = new QSlider(centralWidget);
        green_horizontalSlider->setObjectName(QStringLiteral("green_horizontalSlider"));
        green_horizontalSlider->setGeometry(QRect(590, 430, 160, 22));
        green_horizontalSlider->setMinimum(-255);
        green_horizontalSlider->setMaximum(255);
        green_horizontalSlider->setOrientation(Qt::Horizontal);
        blue_horizontalSlider = new QSlider(centralWidget);
        blue_horizontalSlider->setObjectName(QStringLiteral("blue_horizontalSlider"));
        blue_horizontalSlider->setGeometry(QRect(590, 390, 160, 22));
        blue_horizontalSlider->setContextMenuPolicy(Qt::NoContextMenu);
        blue_horizontalSlider->setMinimum(-255);
        blue_horizontalSlider->setMaximum(255);
        blue_horizontalSlider->setOrientation(Qt::Horizontal);
        blur_pushButton = new QPushButton(centralWidget);
        blur_pushButton->setObjectName(QStringLiteral("blur_pushButton"));
        blur_pushButton->setGeometry(QRect(670, 40, 110, 41));
        save_pushButton = new QPushButton(centralWidget);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));
        save_pushButton->setGeometry(QRect(190, 10, 111, 41));
        negative_pushButton = new QPushButton(centralWidget);
        negative_pushButton->setObjectName(QStringLiteral("negative_pushButton"));
        negative_pushButton->setEnabled(true);
        negative_pushButton->setGeometry(QRect(530, 110, 111, 41));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(530, 340, 50, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_5);

        contrast_horizontalSlider = new QSlider(centralWidget);
        contrast_horizontalSlider->setObjectName(QStringLiteral("contrast_horizontalSlider"));
        contrast_horizontalSlider->setGeometry(QRect(590, 240, 160, 22));
        contrast_horizontalSlider->setToolTipDuration(-1);
        contrast_horizontalSlider->setMinimum(1);
        contrast_horizontalSlider->setMaximum(100);
        contrast_horizontalSlider->setValue(1);
        contrast_horizontalSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(520, 230, 61, 41));
        label_6->setFont(font);
        clear_pushButton = new QPushButton(centralWidget);
        clear_pushButton->setObjectName(QStringLiteral("clear_pushButton"));
        clear_pushButton->setGeometry(QRect(350, 10, 111, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 818, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        open_pushButton->setText(QApplication::translate("MainWindow", "\351\226\213\345\225\237\346\252\224\346\241\210", 0));
        label->setText(QString());
        grayscale_pushButton->setText(QApplication::translate("MainWindow", "\347\201\260\351\232\216\345\214\226", 0));
        label_2->setText(QApplication::translate("MainWindow", " \344\272\256\345\272\246\357\274\232", 0));
        blur_pushButton->setText(QApplication::translate("MainWindow", "\346\250\241\347\263\212\345\214\226", 0));
        save_pushButton->setText(QApplication::translate("MainWindow", "\345\204\262\345\255\230\346\252\224\346\241\210", 0));
        negative_pushButton->setText(QApplication::translate("MainWindow", "\350\262\240\347\211\207\346\225\210\346\236\234", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\264\205\350\211\262\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\350\227\215\350\211\262\357\274\232", 0));
        label_5->setText(QApplication::translate("MainWindow", "\347\266\240\350\211\262\357\274\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\260\215\346\257\224\345\272\246\357\274\232", 0));
        clear_pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

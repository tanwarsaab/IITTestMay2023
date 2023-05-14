/********************************************************************************
** Form generated from reading UI file 'CameraTest.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERATEST_H
#define UI_CAMERATEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_CameraTest
{
public:
    QWidget *centralwidget;
    QComboBox *comboBoxCamerList;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QSlider *horizontalSliderBrightness;
    QSlider *horizontalSliderContrast;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QCameraViewfinder *camView;
    QMenuBar *menubar;
    QMenu *menuDevices;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CameraTest)
    {
        if (CameraTest->objectName().isEmpty())
            CameraTest->setObjectName(QString::fromUtf8("CameraTest"));
        CameraTest->resize(600, 356);
        centralwidget = new QWidget(CameraTest);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBoxCamerList = new QComboBox(centralwidget);
        comboBoxCamerList->setObjectName(QString::fromUtf8("comboBoxCamerList"));
        comboBoxCamerList->setEnabled(true);
        comboBoxCamerList->setGeometry(QRect(10, 80, 151, 22));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setEnabled(false);
        pushButtonStart->setGeometry(QRect(15, 120, 67, 23));
        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setEnabled(false);
        pushButtonStop->setGeometry(QRect(90, 120, 67, 23));
        horizontalSliderBrightness = new QSlider(centralwidget);
        horizontalSliderBrightness->setObjectName(QString::fromUtf8("horizontalSliderBrightness"));
        horizontalSliderBrightness->setEnabled(false);
        horizontalSliderBrightness->setGeometry(QRect(10, 170, 141, 19));
        horizontalSliderBrightness->setMinimum(-100);
        horizontalSliderBrightness->setMaximum(100);
        horizontalSliderBrightness->setOrientation(Qt::Horizontal);
        horizontalSliderContrast = new QSlider(centralwidget);
        horizontalSliderContrast->setObjectName(QString::fromUtf8("horizontalSliderContrast"));
        horizontalSliderContrast->setEnabled(false);
        horizontalSliderContrast->setGeometry(QRect(10, 210, 141, 20));
        horizontalSliderContrast->setMinimum(-100);
        horizontalSliderContrast->setMaximum(100);
        horizontalSliderContrast->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 150, 61, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 200, 47, 13));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(170, 10, 421, 291));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(22, 22, 22);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        camView = new QCameraViewfinder(frame);
        camView->setObjectName(QString::fromUtf8("camView"));
        camView->setGeometry(QRect(0, 0, 421, 291));
        camView->setStyleSheet(QString::fromUtf8(""));
        CameraTest->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CameraTest);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
        menuDevices = new QMenu(menubar);
        menuDevices->setObjectName(QString::fromUtf8("menuDevices"));
        CameraTest->setMenuBar(menubar);
        statusbar = new QStatusBar(CameraTest);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CameraTest->setStatusBar(statusbar);

        menubar->addAction(menuDevices->menuAction());

        retranslateUi(CameraTest);

        QMetaObject::connectSlotsByName(CameraTest);
    } // setupUi

    void retranslateUi(QMainWindow *CameraTest)
    {
        CameraTest->setWindowTitle(QCoreApplication::translate("CameraTest", "CameraTest", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("CameraTest", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("CameraTest", "Stop", nullptr));
        label->setText(QCoreApplication::translate("CameraTest", "Brightness", nullptr));
        label_2->setText(QCoreApplication::translate("CameraTest", "Contrast", nullptr));
        menuDevices->setTitle(QCoreApplication::translate("CameraTest", "Devices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraTest: public Ui_CameraTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERATEST_H

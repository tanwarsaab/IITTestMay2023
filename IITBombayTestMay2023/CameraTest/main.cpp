#include "CameraTest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication qApplication(argc, argv);
    CameraTest obj_CameraTest;
    obj_CameraTest.show();
    return qApplication.exec();
}

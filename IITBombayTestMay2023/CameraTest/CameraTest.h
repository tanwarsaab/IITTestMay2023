#ifndef CAMERATEST_H
#define CAMERATEST_H

#include <QMainWindow>
#include <QCameraInfo>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QMessageBox>
#include <QVideoEncoderSettings>


QT_BEGIN_NAMESPACE
namespace Ui { class CameraTest; }
QT_END_NAMESPACE

class CameraTest : public QMainWindow
{
    Q_OBJECT
    QScopedPointer<QCamera> mptr_QCamera;
    QScopedPointer<QMediaRecorder> mptr_MediaRecorder;
    QCameraInfo selectedCamera;
    QMessageBox *msg;
public:
    CameraTest(QWidget *parent = nullptr);
    ~CameraTest();
    void loadCameraList();
    void setCamera(QCameraInfo);
    void showRecorderTimings();
    void confVideoSettings();

private slots:
    void on_comboBoxCamerList_currentIndexChanged(int index);
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void on_horizontalSliderBrightness_sliderMoved(int position);

    void on_horizontalSliderContrast_sliderMoved(int position);

private:
    Ui::CameraTest *ui;
};
#endif // CAMERATEST_H

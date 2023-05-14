#include "CameraTest.h"
#include "ui_CameraTest.h"
#include <QUrl>
#include <QMediaMetaData>
CameraTest::CameraTest(QWidget *parent)  : QMainWindow(parent) , ui(new Ui::CameraTest)
{
    ui->setupUi(this);
    loadCameraList();
}

CameraTest::~CameraTest()
{
    delete ui;
    delete msg;
}

void CameraTest::loadCameraList()
{
    QList<QCameraInfo> cameraList = QCameraInfo::availableCameras();
    ui->comboBoxCamerList->clear();
    ui->comboBoxCamerList->addItem("none");
    for(QCameraInfo cam:cameraList)
    {
        ui->comboBoxCamerList->addItem(cam.description());
    }
}

void CameraTest::on_comboBoxCamerList_currentIndexChanged(int index)
{
    if(index ==0)
    {
        ui->pushButtonStart->setEnabled(false);
        ui->pushButtonStop->setEnabled(false);
        ui->horizontalSliderBrightness->setEnabled(false);
        ui->horizontalSliderContrast->setEnabled(false);
        return;
    }
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonStop->setEnabled(true);
    ui->horizontalSliderBrightness->setEnabled(true);
    ui->horizontalSliderContrast->setEnabled(true);
    QList<QCameraInfo> cameraList = QCameraInfo::availableCameras();
    for(QCameraInfo cam:cameraList)
    {
        if(cam.description() == ui->comboBoxCamerList->currentText())
        {
            selectedCamera = cam;
        }
    }
    setCamera(selectedCamera);
}

void CameraTest::setCamera(QCameraInfo selectedCamera)
{
    mptr_QCamera.reset(new QCamera(selectedCamera));
    mptr_MediaRecorder.reset(new QMediaRecorder(mptr_QCamera.data()));
    mptr_MediaRecorder->setMetaData(QMediaMetaData::Title, QVariant(QLatin1String("CameraTest")));
    mptr_QCamera->isCaptureModeSupported(QCamera::CaptureVideo);
    confVideoSettings();
    mptr_MediaRecorder->setOutputLocation(QUrl("d:\\CameraTest\\videos\\CameraTest.mp4"));
    mptr_QCamera->setCaptureMode(QCamera::CaptureVideo);
    connect(mptr_MediaRecorder.data(), &QMediaRecorder::durationChanged, this, &CameraTest::showRecorderTimings);
    ui->camView->setVisible(true);
    mptr_QCamera->setViewfinder(ui->camView);
    mptr_QCamera->start();
    mptr_MediaRecorder->record();}

void CameraTest::showRecorderTimings()
{
    int ss = mptr_MediaRecorder->duration()/1000;
    int mm = ss/ 60;
    ss = ss % 60;
    int hh = mm / 60;
    mm = mm % 60;
    QString str = QString::number(hh)+":"+QString::number(mm)+":"+QString::number(ss);
    ui->statusbar->showMessage(str);
}

void CameraTest::confVideoSettings()
{
    QVideoEncoderSettings videoSettings =  mptr_MediaRecorder->videoSettings();
    videoSettings.setResolution(640,480);
    videoSettings.setCodec("video/mp4");
    videoSettings.setFrameRate(30.0);
    videoSettings.setQuality(QMultimedia::VeryHighQuality);
    mptr_MediaRecorder->setVideoSettings(videoSettings);
    mptr_MediaRecorder->setContainerFormat("mp4");
}

void CameraTest::on_pushButtonStart_clicked()
{
    mptr_MediaRecorder->record();
}

void CameraTest::on_pushButtonStop_clicked()
{
    mptr_QCamera->stop();
    ui->comboBoxCamerList->setCurrentIndex(0)    ;
    ui->camView->repaint();
    ui->camView->setVisible(false);
}

void CameraTest::on_horizontalSliderBrightness_sliderMoved(int position)
{
    mptr_QCamera->imageProcessing()->setBrightness(position);
    ui->camView->setBrightness(position);
    qDebug()<<"brightness"<<ui->camView->brightness();
}

void CameraTest::on_horizontalSliderContrast_sliderMoved(int position)
{
    mptr_QCamera->imageProcessing()->setContrast(position);
    ui->camView->setContrast(position);
    qDebug()<<"contrast"<<ui->camView->contrast();
}

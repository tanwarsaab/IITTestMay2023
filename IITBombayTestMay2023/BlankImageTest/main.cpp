#include <QGuiApplication>
#include <iostream>
#include <qpixmap.h>
#include <QDir>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    std::string path;
    std::cout<<"Enter complete path of the folder or directory : ";
    std::cin>>path;
    const QDir dir(QString::fromStdString(path));
    QStringList filters;
    filters<<"*.jpg"<<"*.jpeg"<<"*.png"<<"*.tiff";//<<"*."<<"*."<<"*.";
    QStringList list = dir.entryList(filters,QDir::Files);
    QPixmap *pixmap;
    bool isBlank = true;
    int r = 0,g = 0,b = 0;
    QColor color;
    for(const QString &fileName:list)
    {
        std::string stdFile = fileName.toStdString();
        pixmap = new QPixmap(dir.absoluteFilePath(fileName));
        QImage img = pixmap->toImage();
        isBlank = true;
        for(int x =0;x < img.width();x++)
        {
            for(int y=0;y < img.height();y++)
            {
                color = img.pixelColor(x,y);
                color.getRgb(&r,&g,&b);
                if(!(r==255 && g == 255 && b == 255))
                {
                    isBlank = false;
                    break;
                }
            }
        }
        if(isBlank)
        {
            std::cout<<stdFile<<": Blank Image"<<std::endl;
        }
        else
        {
            std::cout<<stdFile<<": Non-Blank Image"<<std::endl;
        }
    }
    return a.exec();
}

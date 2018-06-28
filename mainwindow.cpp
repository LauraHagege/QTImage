#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#undef UNICODE
#undef _UNICODE
#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <QPixmap>
#include <QLabel>
#include <QImageReader>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //int sizeX = 600;
   // int sizeY = 600;


    //initialize random seed
    //srand (time(NULL));


    //QImage image = QImage( sizeX, sizeY, QImage::Format_RGB32 );

    /*for( int l=0; l<sizeX; l++ )
    {
        for( int c=0; c<sizeY; c++ )
        {
            ///Random color for each pixel
            //image.setPixel( l, c, qRgb(rand() % 256, rand() % 256, rand() % 256) );

            ///Fixed color for each pixel
            image.setPixel( l, c, qRgb(100, 150, 200) );
        }
    }*/
    const char *file = "C:\\Users\\simms\\Desktop\\Laura\\CTAbdomen\\DICOMDAT\\SDY00000\\SRS00000\\IMG00000";
    DicomImage *image = new DicomImage(file);


    if (image != NULL)
        {
          if (image->getStatus() == EIS_Normal)
          {
            Uint8 *pixelData = (Uint8 *)(image->getOutputData(8 )); // bits per sample
            // Uint8 is a pointer to internal memory buffer
            if (pixelData != NULL)
            {
                // do something useful with the pixel data
                QImage img(pixelData,image->getWidth(), image->getHeight(), QImage::Format_Indexed8 );
                /*QColor color;
                QImage *img;
                void *pDicomDibits;
                uchar *px;
               // uchar pixel[4];
                const int width = (int)(image->getWidth());
                const int height = (int)(image->getHeight());
                if (image->isMonochrome()){
                    img = new QImage(width, height, QImage::Format_Indexed8);
                    img->setColorCount(256);
                    // define gray palette here
                    for (int i=0; i<256; i++) {
                        color.setRgb(i, i, i);
                        img->setColor(i, color.rgb());
                    }

                    image->createWindowsDIB(pDicomDibits, 0, 0, 8, 0, 1);
                    unsigned char * pd;
                    pd=(unsigned char *)pDicomDibits;

                    for (int y=0; y < (long) height; y++)
                    {
                        px = img->scanLine(y);
                        for (int x=0; x < (long) width; x++)
                        {
                            px[x] = (unsigned char) (*pd);
                            pd++;
                        }
                    }*/


                    QGraphicsScene * graphic = new QGraphicsScene( this );

                    graphic->addPixmap( QPixmap::fromImage( img ) );

                    ui->graphicsView->setScene(graphic);

               /* }else
                    cout << "Non monochrome image" << endl;*/


            }
          } else
            cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
        }








}

MainWindow::~MainWindow()
{
    delete ui;
}

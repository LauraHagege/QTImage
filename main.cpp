#include "mainwindow.h"
#include <QApplication>
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const char *file = "C:\\Users\\simms\\Desktop\\Laura\\CTAbdomen\\DICOMDAT\\SDY00000\\SRS00000\\IMG00000";
    DicomImage *image = new DicomImage(file);


    //int sizeX = 600;
   // int sizeY = 600;
   // QImage image = QImage( sizeX, sizeY, QImage::Format_RGB32 );

    /*if (image != NULL)
        {
          if (image->getStatus() == EIS_Normal)
          {
            cout << "size" << image->getOutputDataSize() << endl;
            image->setMinMaxWindow();

            Uint8 *pixelData = (Uint8 *)(image->getOutputData(8 )); // bits per sample
            // Uint8 is a pointer to internal memory buffer
            if (pixelData != NULL)
            {

               // QImage img(pixelData,image->getWidth(), image->getHeight(), QImage::Format_Grayscale8);


                MainWindow w(img, image->getWidth(),image->getHeight());
                w.show();
            }
          } else
                cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
        }
        //delete image;

*/

    MainWindow w;
    w.show();

    return a.exec();
}

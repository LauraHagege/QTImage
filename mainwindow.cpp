#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QImage image, int sizeX, int sizeY,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //int sizeX = 600;
   // int sizeY = 600;


    //initialize random seed
    srand (time(NULL));


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

    QGraphicsScene * graphic = new QGraphicsScene( this );

    graphic->addPixmap( QPixmap::fromImage( image ) );

    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}

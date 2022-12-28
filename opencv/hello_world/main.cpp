#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    Mat greyMat;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }

    cv::cvtColor(image, greyMat, COLOR_BGR2GRAY);
    imwrite("grey.jpg", greyMat); 

    // greyMat = greyMat.reshape (1, greyMat.rows, greyMat.cols);
    int size_1[3] = { 1, greyMat.rows, greyMat.cols };
    cv::Mat input_(3, size_1, greyMat.type(), greyMat.data);
    std::cout << "new shape: " << input_.size << std::endl;
    
    // namedWindow("Display Image", WINDOW_AUTOSIZE );
    // imshow("Display Image", image);
    // waitKey(0);
    return 0;
}
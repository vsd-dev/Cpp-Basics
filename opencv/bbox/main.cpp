#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/dnn.hpp>

#include <unistd.h>
#include <string>
#include <array>

#define show 1

struct Points{
        int x1;
        int y1;
        int h;
        int w;
    } bb;

int main(){

    cout << "BBOX Example" << endl;
    cv::Mat ColorMat;
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    std::cout << "The current working directory is: " << cwd << std::endl;
    
    ColorMat = cv::imread(cwd + string("/../image.jpg"));
    
    bb.x1 = 220;
    bb.y1 = 4;
    bb.w = 460;
    bb.h = 550;
    
    cv::Point pt1(bb.x1, bb.y1);
    cv::Point pt2(bb.x1 + bb.w, bb.y1 + bb.h);
    cv::rectangle(ColorMat, pt1, pt2, cv::Scalar(0, 255, 0));
    
    #ifdef show
        cv::namedWindow("image", cv::WINDOW_NORMAL);
        cv::imshow("image", ColorMat);
        cv::waitKey(10);
    #endif

    cv::Mat face_image;
    face_image = ColorMat(cv::Range(bb.y1,bb.y1+bb.h), cv::Range(bb.x1,bb.x1+bb.w));
    
    #ifdef show
        cv::namedWindow("crop", cv::WINDOW_NORMAL);
        cv::imshow("crop", face_image);
        cv::waitKey(10);
    #endif

    int resize_width = 224;
    int resize_height = 224;
    cv::Mat resized;
    //resize down
    cv::resize(face_image, resized, cv::Size(resize_width, resize_height), cv::INTER_LINEAR);

    #ifdef show
        cv::namedWindow("resized", cv::WINDOW_NORMAL);
        cv::imshow("resized", resized);
        cv::waitKey(0);
    #endif
    
    cv::Mat blob = cv::dnn::blobFromImage(resized, 1.0, cv::Size(), cv::Scalar(0, 0, 0), true, false);


    cout << "Shape of array is\n";

    for (int i = 0; i < blob.dims; i++)
        {
        std::cout << blob.size[i] << " ";
        }
        std::cout << std::endl;


    // Open a file for writing
    cv::FileStorage fs("matrix.yml", cv::FileStorage::WRITE);
    if (!fs.isOpened())
    {
        cout << "ERROR: Could not open file for writing." << endl;
        return -1;
    }

    // Write the 4D matrix to the file
    fs << "matrix" << blob;

    // Close the file
    fs.release();

    cout << "Matrix was successfully saved to file." << endl;



    return 0;
}










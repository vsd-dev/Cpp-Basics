#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
if (argc != 2)
    {
        printf("Provide Image path!");
        return -1;
    }
Mat colorMat;
colorMat = imread(argv[1], 1);

if (!colorMat.data)
    {
        printf("No image data!");
        return -1;
    }

int height;
int width;
height = colorMat.cols;
width = colorMat.rows;

cout << "Height " << height <<" Width "<< width <<endl;
namedWindow("Out", WINDOW_NORMAL);
imshow("Out", colorMat);
waitKey(0);

Mat new_shape;

// new_shape = colorMat.reshape (1, colorMat.rows , colorMat.cols);
// cout << "New shape " << new_shape.size <<endl;

int size_1[3] = {1, colorMat.rows, colorMat.cols};
Mat output_(3, size_1, colorMat.type(), colorMat.data);

cout << "output_ : " << output_ .size << endl;
return 0 ;    
}
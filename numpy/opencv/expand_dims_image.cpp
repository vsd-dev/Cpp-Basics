#include <opencv2/opencv.hpp>

// Expand the dimensions of a grayscale image by inserting a new
// dimension at the specified `axis`
cv::Mat expand_dims(const cv::Mat& img, int axis) {
  // Get the number of rows and columns in the image
  int rows = img.rows;
  int cols = img.cols;

  // Reshape the image data to add a new dimension at the specified axis
  cv::Mat expanded_img;
  if (axis == 0) {
    expanded_img = img.reshape(1, 1);
  } else {
    expanded_img = img.reshape(1, rows * cols);
  }

  return expanded_img;
}

int main() {
  // Load the image
  cv::Mat img = cv::imread("/home/vishnu/workspace/learn/Cpp-Basics/numpy/opencv/image.png", cv::IMREAD_GRAYSCALE);

  // Expand the dimensions of the image by adding a new dimension at the beginning
  cv::Mat expanded_img = expand_dims(img, 0);

  // Save the expanded image
  cv::imwrite("expanded_image.png", expanded_img);

  return 0;
}

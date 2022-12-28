#include <iostream>
#include <vector>

// Reshape a 1D array of size `size` into a 2D array of size (`new_rows`, `new_cols`)
std::vector<std::vector<int>> reshape(const std::vector<int>& arr, int new_rows, int new_cols) {
  std::vector<std::vector<int>> reshaped_array;

  // Resize the new array to have the desired number of rows and columns
  reshaped_array.resize(new_rows);
  for (int i = 0; i < new_rows; i++) {
    reshaped_array[i].resize(new_cols);
  }

  // Populate the new array with the data from the original array
  int index = 0;
  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < new_cols; j++) {
      reshaped_array[i][j] = arr[index];
      index++;
    }
  }

  return reshaped_array;
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6};

  // Reshape the array to have 2 rows and 3 columns
  std::vector<std::vector<int>> reshaped_array = reshape(arr, 2, 3);

  // Print the reshaped array
  for (int i = 0; i < reshaped_array.size(); i++) {
    for (int j = 0; j < reshaped_array[i].size(); j++) {
      std::cout << reshaped_array[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

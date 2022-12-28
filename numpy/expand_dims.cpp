#include <iostream>
#include <vector>

// Expand the dimensions of a 1D array of size `size` by inserting a new
// dimension at the specified `axis`
std::vector<std::vector<int>> expand_dims(const std::vector<int>& arr, int axis) {
  std::vector<std::vector<int>> expanded_array;

  // Insert a new dimension at the specified axis
  for (int i = 0; i < arr.size(); i++) {
    std::vector<int> new_dim = {arr[i]};
    if (axis == 0) {
      expanded_array.insert(expanded_array.begin(), new_dim);
    } else {
      expanded_array.push_back(new_dim);
    }
  }

  return expanded_array;
}

int main() {
  std::vector<int> arr = {224, 224, 3};

  // Expand the dimensions of the array by adding a new dimension at the beginning
  std::vector<std::vector<int>> expanded_array = expand_dims(arr, 0);

  // Print the expanded array
  for (int i = 0; i < expanded_array.size(); i++) {
    for (int j = 0; j < expanded_array[i].size(); j++) {
      std::cout << expanded_array[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

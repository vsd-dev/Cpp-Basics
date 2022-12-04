#include <iostream>
#include <experimental/iterator>

int SumOfarr(int arr[], int size){
    int sum {0};
    for (int i=0; i < size; i++)
        {
            sum+=arr[i];
        }
    return sum;
}
int main(){
    int arr [] = {2, 4, 3, 2, 10};
    int sum;
    int size = sizeof(arr)/sizeof(arr[0]);
    sum = SumOfarr(arr, size);
    
    std::cout << "Sum Of array is : " << sum << std::endl;
    return 0;
}
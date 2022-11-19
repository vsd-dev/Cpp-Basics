#include <iostream>
using namespace std;
int main(){
cout << "array example \n";

int _data[630];
const int sizeOfData = sizeof(_data)/sizeof(int);
for (int i=0;i < sizeOfData;i++)
{
cout << "inserting " << i <<endl;
_data[i] = i;
}



cout << _data;

return 0;
}

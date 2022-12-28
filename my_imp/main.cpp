#include <iostream>
using namespace std;


#pragma once
  
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray/NdArrayCore.hpp"
#include "NumCpp/NdArray/NdArrayOperators.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    template<typename dtype>
    NdArray<uint32> argmax(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.argmax(inAxis);
    }
} // namespace nc

int main(){
    cout << "Hello" <<endl;
    return 0;
}
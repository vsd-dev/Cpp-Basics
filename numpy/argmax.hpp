#pragma once
  
#include "Types.hpp"
#include "NdArray.hpp"
#include"NumCpp.hpp"
  
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
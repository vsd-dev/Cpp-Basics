#pragma once
#include "LivingBeing.h"

class Frog: public LivingBeing {
    public:
        Frog(const LivingBeingInfo& info);
        float JumpPower = 1.f;
    private:
        
};
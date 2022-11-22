#pragma once
#include "LivingBeing.h"

class Frog final: public LivingBeing {
    public:
        Frog(const LivingBeingInfo& info);
        float JumpPower = 1.f;
    private:
        
};
#pragma once
#include <string>
struct LivingBeingInfo 
{
    std::string species_name;
};

class LivingBeing{
    public:
        LivingBeing() = delete;
        LivingBeing(const LivingBeingInfo& info);
        int HitPoints{1};
        std::string SpeciesName;
    private:

    protected:
};
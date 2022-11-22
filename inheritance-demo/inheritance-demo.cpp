#include <iostream>
#include "inheritance-demo.h"

int main(int, char**) {
    LivingBeingInfo frog_info;
    frog_info.species_name = "Tree";
    Frog frog(frog_info);
    std::cout << "Type:       " << typeid(frog).name() << std::endl;
    std::cout << "Species:    " << frog.SpeciesName << std::endl;
    std::cout << "HP:         " << frog.HitPoints << std::endl;
    std::cout << "Jump Power: " << frog.JumpPower << std::endl;
    return 0;
}

#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    Dragon d("Draco");
    Creature *c = &d;
    
    d.speak();
    d.wound();
    d.wound();
    d.print();
    
    d.speak();
    c->wound();
    c->print();
    d.print();

    Creature tempCreature = *c;
    tempCreature.speak();
    
    Dragon edgecase = d;
    Creature *c2 = &edgecase;
    
    c->wound();
    c->print();
    edgecase.print();
    
    return 0;
}
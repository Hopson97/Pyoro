#ifndef SEED1_H
#define SEED1_H

#include "seed.h"

class NormSeed : public Seed //"Seed" inherits from "PyoroSprite.
{
    public:
        NormSeed(ResourceManager &manager, std::string textureName);

    private:
        void setUpAnimation() override;
        void uniqueLogic() override;
        void uniqueSetUp(ResourceManager& resourceManager) override;

};

#endif // SEED1_H

#include "active.h"

class Player : public pi::Active
{
private:
    void initializeAnimationReel() override;

    int speed;
public:
    Player();

    void readKey();

    void stop();
    void run();
};
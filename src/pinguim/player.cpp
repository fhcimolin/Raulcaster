#include "player.h"

Player::Player() :
    speed{11}
{
    initializeAnimationReel();

    stop();
}

void Player::initializeAnimationReel()
{
    animationReel = std::vector<pi::animation>(
    {
        pi::animation
        {1,0},
        {3,speed}
    }); 
}

void Player::readKey()
{
    run();
}

void Player::stop()
{
    changeReel(0);
}

void Player::run()
{
    changeReel(1);
}
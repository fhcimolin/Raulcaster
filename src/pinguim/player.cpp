#include "player.h"

Player::Player() :
    speed{4}
{
    initializeAnimationReel();
}

void Player::initializeAnimationReel()
{
    animationReel = std::vector<pi::animation>(
    {
        pi::animation
        {1,0},
        {3,speed/2}
    }); 
}

void Player::readKey()
{
    run();
}

void Player::stop()
{
    changeAnimationReel(0);
}

void Player::run()
{
    changeAnimationReel(1);
}

void Player::move(v::direction direction)
{
    if(direction == v::direction::left)
    {
        setPosition(x - speed, y);
    }
    else if(direction == v::direction::right)
    {
        setPosition(x + speed, y);
    }
}
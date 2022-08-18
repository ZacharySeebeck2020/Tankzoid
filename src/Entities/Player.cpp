#include "Entities/Player.hpp"
#include "Sprite.hpp"
#include "Logger.h"

Player::Player(SDL_Rect p_screenPosition, SDL_Renderer* p_renderer):
Tank(p_screenPosition, p_renderer, Sprites["PlayerTankBase"], Sprites["PlayerTankTurret"])
{
    Logger::getInstance().log("Player::Player()");
}

// Player::~Player() {}

void Player::HandleEvents(SDL_Event event)
{
    Tank::HandleEvents(event);
}

void Player::Update()
{
    Tank::Update();
}

void Player::Draw()
{
    Tank::Draw();
}
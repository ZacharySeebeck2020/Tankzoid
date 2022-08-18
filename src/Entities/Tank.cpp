#include "Entities/Tank.hpp"
#include "Logger.h"

Tank::Tank(SDL_Rect p_screenPosition, SDL_Renderer* p_renderer, SDL_Point p_tankBodySprite, SDL_Point p_tankTurretSprite):
 Entity("Tank", p_tankBodySprite, p_screenPosition, p_renderer), 
 turretEntity("TurretEntity", p_tankTurretSprite, p_screenPosition, p_renderer)
{

}

void Tank::HandleEvents(SDL_Event event)
{
	turretEntity.HandleEvents(event);
}

void Tank::Update()
{
	turretEntity.Update();
}

void Tank::Draw()
{
	Logger::getInstance().log("Drawing Tank", LogLevel::LOG_INFO);
	turretEntity.Draw();
}

void Tank::TakeDamage(int damage)
{
	health -= damage;
}

void Tank::Heal(int heal)
{
	health += heal;
}

void Tank::SetSpeed(int p_speed)
{
	speed = p_speed;
}

void Tank::SetWallBounceCount(int p_wallBounceCount)
{
	wallBounceCount = p_wallBounceCount;
}

void Tank::SetMaxDamage(int p_maxDamage)
{
	maxDamage = p_maxDamage;
}

void Tank::SetMinDamage(int p_minDamage)
{
	minDamage = p_minDamage;
}

void Tank::SetMaxHealth(int p_maxHealth)
{
	maxHealth = p_maxHealth;
}

void Tank::SetMinHealth(int p_minHealth)
{
	minHealth = p_minHealth;
}

void Tank::SetHealth(int p_health)
{
	health = p_health;
}

int Tank::GetSpeed()
{
	return speed;
}

int Tank::GetWallBounceCount()
{
	return wallBounceCount;
}

int Tank::GetMaxDamage()
{
	return maxDamage;
}

int Tank::GetMinDamage()
{
	return minDamage;
}

int Tank::GetMaxHealth()
{
	return maxHealth;
}

int Tank::GetMinHealth()
{
	return minHealth;
}

int Tank::GetHealth()
{
	return health;
}
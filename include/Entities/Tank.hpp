#include <SDL.h>
#include "Entity.hpp"

class Tank: public Entity {
private:
	int health = 10;
	int maxHealth = 10;
	int minHealth = 1;
	
	int speed = 1;
	int wallBounceCount = 1;

	int maxDamage = 1;
	int minDamage = 1;

	Entity turretEntity;
public:
	Tank(SDL_Rect p_screenPosition, SDL_Renderer* p_renderer, SDL_Point p_tankBodySprite, SDL_Point p_tankTurretSprite);
	~Tank();
	
	void HandleEvents(SDL_Event event);
	void Update();
	void Draw();
	void TakeDamage(int damage);
	void Heal(int heal);
	void SetSpeed(int p_speed);
	void SetWallBounceCount(int p_wallBounceCount);
	void SetMaxDamage(int p_maxDamage);
	void SetMinDamage(int p_minDamage);
	void SetMaxHealth(int p_maxHealth);
	void SetMinHealth(int p_minHealth);
	void SetHealth(int p_health);
	int GetSpeed();
	int GetWallBounceCount();
	int GetMaxDamage();
	int GetMinDamage();
	int GetMaxHealth();
	int GetMinHealth();
	int GetHealth();
};
#include <SDL.h>
#include <vector>
#include "Entity.hpp"

class EntityManager
{
private:
	std::vector<Entity*> entities;
	SDL_Window* window;
public:
	EntityManager();

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);
	void Draw();
	void Update();
	void HandleEvent(SDL_Event event);

	~EntityManager();
};
#include "EntityManager.hpp"
#include "Logger.h"

EntityManager::EntityManager()
{
}

void EntityManager::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}

void EntityManager::RemoveEntity(Entity* entity)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i] == entity)
		{
			entities.erase(entities.begin() + i);
		}
	}
}

void EntityManager::Draw()
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->Draw();
	}
}

void EntityManager::HandleEvent(SDL_Event event) {
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->HandleEvents(event);
	}
}

void EntityManager::Update() {
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->Update();
	}
}

EntityManager::~EntityManager()
{
}

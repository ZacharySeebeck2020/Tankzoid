#pragma once
#include "Entities/Tank.hpp"

class Player : public Tank {
private:

public: 
    Player(SDL_Rect p_screenPosition, SDL_Renderer* p_renderer);
    ~Player();
    void HandleEvents(SDL_Event event) override;
    void Update() override;
    void Draw() override;
};
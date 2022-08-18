#include "Game.hpp"
#include "Logger.h"
#include "Entities/Tank.hpp"
// #include "Entities/Player.hpp"
#include "Sprite.hpp"

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"

Game::Game() {}
Game::~Game() {}

void Game::Init(int width, int height, const std::string title) {
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		Logger::getInstance().log("SDL_Init Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		Logger::getInstance().log("IMG_Init Error: " + std::string(IMG_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		Logger::getInstance().log("Failed to create window", LogLevel::LOG_FATAL);
		Logger::getInstance().log("SDL_CreateWindow Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(-1);
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		Logger::getInstance().log("Failed to create renderer", LogLevel::LOG_FATAL);
		Logger::getInstance().log("SDL_CreateRenderer Error: " + std::string(SDL_GetError()), LogLevel::LOG_FATAL);
		exit(1);
	}
	
	Spritesheet::getInstance()->LoadSpritesheet("./assets/default_spritesheet1.png", 16, 16, renderer);
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);

	IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui::StyleColorsDark();

	entityManager.AddEntity(new Tank({640,320,64,64}, renderer, Sprites["PlayerTankBase"], Sprites["PlayerTankTurret"]));
	// entityManager.AddEntity(new Player({140,140,64,64}, renderer));
	// entityManager.AddEntity(new Entity("Player Turret", Sprites["PlayerTankTurret"], {640,320,64,64}, renderer));

	// entityManager.AddEntity(new Entity("Enemy Tank", Sprites["DarkBlueTankBase"], {300,320,64,64}, renderer));
	// entityManager.AddEntity(new Entity("Enemy Turret", Sprites["DarkBlueTankTurret"], {300,320,64,64}, renderer));

	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer_Init(renderer);

	isRunning = true;
}

void Game::HandleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		entityManager.HandleEvent(event);
		switch (event.type)
		{
			case SDL_QUIT:
				isRunning = false;
				break;
			
			default:
				break;
		}	
	}
}

void Game::Update() {
	entityManager.Update();
}

void Game::Render() {
	SDL_RenderClear(renderer);

	entityManager.Draw();

	// Start the Dear ImGui frame
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::ShowDemoWindow();
	
	ImGui::Render();
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
	SDL_RenderPresent(renderer);
}

void Game::Clean() {
	ImGui_ImplSDLRenderer_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	Logger::getInstance().log("Goodbye! :) ", LogLevel::LOG_INFO);
}


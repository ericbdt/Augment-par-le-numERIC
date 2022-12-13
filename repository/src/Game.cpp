#include "Game.hpp"

// Private functions
void Game::init_var() // initializes all pointers and variables
{
    this->window = nullptr;
    this->fire_timer_max = 120.f;
    this->fire_timer = 0.f;
    this->spawn_timer_max = 30.f;
    this->spawn_timer = 0.f;
    this->max_enemies = 20;
}

void Game::init_win() // initializes all window parameters
{
    // this->videomode.getDesktopMode to get Desktop resolution
    this->videomode.height = 1024;
    this->videomode.width = 1024;

    // /!\ Dynamic Allocation
    this->window = new sf::RenderWindow(this->videomode, "Le Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

    // Center Window on the desktop
    auto desktop = sf::VideoMode::getDesktopMode();
    sf::Vector2i v(desktop.width / 2 - window->getSize().x / 2, desktop.height / 2 - window->getSize().y / 2);
    this->window->setPosition(v);
}

void Game::init_world() // initailizes world background
{
    if (!this->world_background_texture.loadFromFile("../repository/data/textures/background.png"))
    {
        std::cout << "ERROR::GAME::Could not load background image" << std::endl;
    }
    this->world_background_sprite.setTexture(this->world_background_texture);
}

// Ctors & Dtors
Game::Game()
{
    // /!\ IN THIS ORDER
    this->init_var();
    this->init_win();
    this->init_world();
}

Game::~Game()
{
    // /!\ Dynamic allocation
    delete this->window;
}

// Getters
bool Game::isRunning() const
{
    return this->window->isOpen();
}

// Functions

// Update : Updates the game state
void Game::update()
{
    this->updateEvents();
    this->spawnEnemies();
    this->playerFire();
    this->player.update(this->window);

    // Update enemies
    for (unsigned int i = 0; i < this->enemies.size(); ++i)
    {
        enemies[i].update(&this->player, this->enemies, this->window);
    }

    // Update projectiles
    for (unsigned int i = 0; i < this->friendly_projectiles.size(); ++i)
    {
        friendly_projectiles[i].update();
    }
}

// Event updating/polling : Scanning events and stocking them in ev
void Game::updateEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
            break;
        }
    }
}

// Render : Draw the new game state
void Game::render()
{
    this->window->clear(sf::Color(200, 174, 40, 255)); // Clears last image

    // Draw World BG
    this->renderWorld();

    // Draw here
    this->player.render(this->window);

    for (auto e : this->enemies)
    {
        e.render(this->window);
    }

    for (auto p : this->friendly_projectiles)
    {
        p.render(this->window);
    }
    // End Draw

    this->window->display(); // Displays the new frame
}

void Game::renderWorld()
{
    this->window->draw(this->world_background_sprite);
}

// Spawns new enemies
void Game::spawnEnemies()
{
    // Timer
    if (this->spawn_timer < this->spawn_timer_max)
        this->spawn_timer += 1.f;
    else
    {
        if (this->enemies.size() < this->max_enemies)
        {
            this->enemies.push_back(Enemy(*this->window));
            std::cout << "new enemy yay" << std::endl;
            this->spawn_timer = 0.f;
        }
    }
}

// Fires Player projectiles
void Game::playerFire()
{
    // Timer
    if (this->fire_timer < this->fire_timer_max)
        this->fire_timer += 1.f;
    else
    {
        if (this->friendly_projectiles.size() < 10)
        {
            this->friendly_projectiles.push_back(
                Projectile(this->player.getCenter(),                               // Position
                           this->player.getDirectionToNearestEnemy(this->enemies), // Direction
                           5.f,                                                    // Speed
                           10.f,                                                   // Damage
                           true));                                                 // Friendly
            std::cout << "fire !" << std::endl;
            this->fire_timer = 0.f;
        }
    }
}
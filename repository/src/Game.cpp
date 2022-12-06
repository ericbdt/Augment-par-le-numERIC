#include "Game.hpp"

// Private functions
void Game::init_var() // initialise tous les pointeurs et variables
{
    this->window = nullptr;
    this->spawn_timer_max = 30.f;
    this->spawn_timer = this->spawn_timer_max;
    this->max_enemies = 5;
}

void Game::init_win()
{
    // this->videomode.getDesktopMode pour obtenir la résolution pc
    this->videomode.height = 600;
    this->videomode.width = 800;
    // /!\ Allocation dynamique il faudra supprimer dans le Dtor
    this->window = new sf::RenderWindow(this->videomode, "Le Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

// Ctors & Dtors
Game::Game()
{
    // /!\ dans cet ordre là
    this->init_var();
    this->init_win();
}

Game::~Game()
{
    // /!\ Allocation dynamique
    delete this->window;
}

// Getters
const bool Game::isRunning() const
{
    return this->window->isOpen();
}

// Functions

// Update : Mise à jour de l'état du jeu
void Game::update()
{
    this->updateEvents();
    this->spawnEnemies();
    this->player.update(this->window);

    // for (auto e : this-> enemies) { 
    //     e.update(&this->player, this->window);
    // }

    for (int i = 0; i< this->max_enemies;++i)
    {
        enemies[i].update(&this->player, this->window);
    }



}

// Event updating/polling : on scan pour les évènements et on stocke dans ev
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

// Render : Dessiner le nouvel état
void Game::render()
{
    this->window->clear(sf::Color(200, 174, 40, 255)); // Clear la dernière image

    // Draw here
    this->player.render(this->window);

    for (auto e : this->enemies)
    {
        e.render(this->window);
    }

    // End Draw

    this->window->display(); // Display : Afficher la nouvelle frame
}

// invoque de nouveaux ennemis
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
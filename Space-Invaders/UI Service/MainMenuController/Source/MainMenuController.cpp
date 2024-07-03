#include "../../UI Service/MainMenuController/Header/MainMenuController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"
#include <iostream>

namespace UI {
    namespace MainMenu {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;

        MainMenuController::MainMenuController() : game_window(nullptr) {}

        void MainMenuController::initialize() {
            auto graphicService = ServiceLocator::getInstance()->getGraphicService();
            if (graphicService != nullptr) {
                game_window = graphicService->getGameWindow();
                if (game_window != nullptr) {
                    initializeBackgroundImage();
                    initializeButtons();
                }
                else {
                    // Log error or handle the case when game_window is nullptr
                    std::cerr << "Error: game_window is nullptr." << std::endl;
                }
            }
            else {
                // Log error or handle the case when graphicService is nullptr
                std::cerr << "Error: GraphicService is nullptr." << std::endl;
            }
        }

        void MainMenuController::initializeBackgroundImage() {
            if (background_texture.loadFromFile(background_texture_path)) {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void MainMenuController::scaleBackgroundImage() {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuController::initializeButtons() {
            if (loadButtonTexturesFromFile()) {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool MainMenuController::loadButtonTexturesFromFile() {
            return play_button_texture.loadFromFile(play_button_texture_path) &&
                instructions_button_texture.loadFromFile(instructions_button_texture_path) &&
                quit_button_texture.loadFromFile(quit_button_texture_path);
        }

        void MainMenuController::setButtonSprites() {
            play_button_sprite.setTexture(play_button_texture);
            instructions_button_sprite.setTexture(instructions_button_texture);
            quit_button_sprite.setTexture(quit_button_texture);
        }

        void MainMenuController::scaleAllButttons() {
            scaleButton(&play_button_sprite);
            scaleButton(&instructions_button_sprite);
            scaleButton(&quit_button_sprite);
        }

        void MainMenuController::scaleButton(sf::Sprite* button_to_scale) {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void MainMenuController::positionButtons() {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
            play_button_sprite.setPosition({ x_position, 500.f });
            instructions_button_sprite.setPosition({ x_position, 700.f });
            quit_button_sprite.setPosition({ x_position, 900.f });
        }

        void MainMenuController::update() {
            // Perform update logic here
        }

        void MainMenuController::render() {
            if (game_window != nullptr) {
                game_window->draw(background_sprite);
                game_window->draw(play_button_sprite);
                game_window->draw(instructions_button_sprite);
                game_window->draw(quit_button_sprite);
            }
        }
    }
}

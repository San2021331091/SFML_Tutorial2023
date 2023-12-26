#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;


static const float VIEW_HEIGHT = 512.0f;


void resizeView(RenderWindow &window,View &view)
{
   float aspectRatio = float(window.getSize().x)/float(window.getSize().y);
  view.setSize(VIEW_HEIGHT*aspectRatio,VIEW_HEIGHT);

}

int main() {

    RenderWindow window(VideoMode(512, 512), "Cadillacs and Dinosaurs Game", Style::Close | Style ::Resize | Style::Titlebar);

    //RectangleShape player(Vector2f(100.0f, 150.0f));
    //player.setOrigin(206.0f, 206.0f);
    View view(Vector2f(0.0f,0.0f),Vector2f(VIEW_HEIGHT,VIEW_HEIGHT));
    Texture playerTexture;
    if (!playerTexture.loadFromFile("E:/ClionProjects/Cadillacs_and_Dinosaur_Game/images/penguin.png")) {
        // Handle error loading texture
        return EXIT_FAILURE;
    }
    //player.setTexture(&playerTexture);

    float delayTime;
    Clock clock;

    Player player(&playerTexture, Vector2u(3, 9), 0.3f,100.0f);

    while (window.isOpen()) {
        delayTime = clock.restart().asSeconds();
        Event event{};

        while (window.pollEvent(event)) {

            switch(event.type){

                case Event :: Closed :
                    window.close();
                    break;
                case Event::Resized:
                    resizeView(window,view);
                    break;

                case Event::LostFocus:
                    break;
                case Event::GainedFocus:
                    break;
                case Event::TextEntered:
                    break;
                case Event::KeyPressed:
                    break;
                case Event::KeyReleased:
                    break;
                case Event::MouseWheelMoved:
                    break;
                case Event::MouseWheelScrolled:
                    break;
                case Event::MouseButtonPressed:
                    break;
                case Event::MouseButtonReleased:
                    break;
                case Event::MouseMoved:
                    break;
                case Event::MouseEntered:
                    break;
                case Event::MouseLeft:
                    break;
                case Event::JoystickButtonPressed:
                    break;
                case Event::JoystickButtonReleased:
                    break;
                case Event::JoystickMoved:
                    break;
                case Event::JoystickConnected:
                    break;
                case Event::JoystickDisconnected:
                    break;
                case Event::TouchBegan:
                    break;
                case Event::TouchMoved:
                    break;
                case Event::TouchEnded:
                    break;
                case Event::SensorChanged:
                    break;
                case Event::Count:
                    break;
            }
        }

        // Handle player movement
//        if (Keyboard::isKeyPressed(Keyboard::Key::F)) {
//            player.move(-0.1f, 0.5f);
//        }
//
//        if (Keyboard::isKeyPressed(Keyboard::Key::H)) {
//            player.move(0.4f, 0.5f);
//        }
//
//        if (Keyboard::isKeyPressed(Keyboard::Key::J)) {
//            player.move(0.7f, -0.5f);
//        }
//
//        if (Mouse::isButtonPressed(Mouse::Left)) {
//            Vector2i mousePos = Mouse::getPosition(window);
//            player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
//        }

        // Update game animation
     player.Update(delayTime);
     view.setCenter(player.GetPosition());

     window.clear(Color(150,150,150));
     window.setView(view);
     player.draw(window);
     window.display();


    }

    return 0;
}

#include "../Headers/Control.h"

#include <iostream>

using namespace CGB;

int score = 0;
bool isEnd = false;

void checkTouchApple(WorldObject& apple, WorldObject& player, Map& map) {
    if (player.touchCheck(apple)) {//TODO:
        Position randPosApple = Position(rand() % map.getSizeMap().x, rand() % map.getSizeMap().y);

        apple.setPosition(randPosApple);
        ++score;
    }
}

void control(Control &playerControl, WorldObject& player) {
    playerControl.pressKey();

    if (playerControl.isKeyPressed(Control::Keyboard::W))
        playerControl.move(Control::Direction::UP, player, "player");
    if (playerControl.isKeyPressed(Control::Keyboard::D))
        playerControl.move(Control::Direction::RIGHT, player, "player");
    if (playerControl.isKeyPressed(Control::Keyboard::S))
        playerControl.move(Control::Direction::DOWN, player, "player");
    if (playerControl.isKeyPressed(Control::Keyboard::A))
        playerControl.move(Control::Direction::LEFT, player, "player");

    playerControl.checkWall(player, Control::ControlMode::SOLID_WALL);
}

int main() {

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Map map(SizeMap(20, 15));
    Control playerControl(map);

    WorldObject player(Symbol::PLAYER, Color::RED, Position(5, 5));
    WorldObject apple(Symbol::APPLE, Color::GREEN, Position(8, 8));

    while(!isEnd) {
        map.update();

        map.objectReset(player.getPosition(), player, "player");
        map.objectReset(apple.getPosition(), apple, "apple");

        map.draw();
        std::cout << "SCORE:" << score << "\t";
        control(playerControl, player);
        checkTouchApple(apple, player, map);
    }

    return 0;
}
#include "../Headers/Control.h"

#include <iostream>

using namespace CGB;

int score = 0;
bool isEnd = false;

void checkTouchApple(WorldObject& apple, WorldObject& player, Map& map) {
    if (player.touchCheck(apple)) {
        Position randPosApple = Position(rand() % map.getSizeMap().x, rand() % map.getSizeMap().y);

        apple.setPosition(randPosApple);//TODO
        ++score;
    }
}

void control(ControlPlayer &controlPlayer, WorldObject& player) {
    controlPlayer.pressKey();

    if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::W))
        controlPlayer.move(ControlPlayer::Direction::UP, player, "player");
    if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::D))
        controlPlayer.move(ControlPlayer::Direction::RIGHT, player, "player");
    if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::S))
        controlPlayer.move(ControlPlayer::Direction::DOWN, player, "player");
    if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::A))
        controlPlayer.move(ControlPlayer::Direction::LEFT, player, "player");

    controlPlayer.checkWall(player, ControlPlayer::ControlMode::SOLID_WALL);
}

int main() {

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Map map(SizeMap(20, 15));
    ControlPlayer controlPlayer(map);

    WorldObject player(Symbol::PLAYER, Color::RED, Position(5, 5));
    WorldObject apple(Symbol::APPLE, Color::GREEN, Position(8, 8));

    while(!isEnd) {
        map.update();

        map.objectReset(player.getPosition(), player, "player");
        map.objectReset(apple.getPosition(), apple, "apple");

        map.draw();
        std::cout << "SCORE:" << score << "\t";
        control(controlPlayer, player);
        checkTouchApple(apple, player, map);
    }

    return 0;
}
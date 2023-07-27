#include <iostream>

#include "../Headers/Control.h"
#include "../Headers/Map.h"

using namespace CGB;

int main() {

    Map map(SizeMap(15, 10));
    ControlPlayer controlPlayer(map);
    controlPlayer.setPlayerControlMode(ControlPlayer::ControlMode::DEFAULT);

    WorldObject player(Symbol::PLAYER, Color::CYAN, Position(3, 3));
    map.objectReset(player.getPosition(), player, "player");

    map.setObjectColor(Color::BLUE, Map::wallCode);

    map.setObjectColor(Color::RED, "player");

    while(true) {
        map.update();
        map.draw();

        controlPlayer.pressKey();

        if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::D))
            controlPlayer.move(ControlPlayer::Direction::RIGHT, "player");
        if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::A))
            controlPlayer.move(ControlPlayer::Direction::LEFT, "player");
        if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::S))
            controlPlayer.move(ControlPlayer::Direction::DOWN, "player");
        if (controlPlayer.isKeyPressed(ControlPlayer::Keyboard::W))
            controlPlayer.move(ControlPlayer::Direction::UP, "player");
    }

    return 0;
}

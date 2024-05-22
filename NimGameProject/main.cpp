#include <iostream>
#include "src/client/Client.h"
#include "src/io/ConsoleWriter.h"
#include "src/game/nimgame/NimGameImpl.h"
#include "src/game/nimgame/player/HumanPlayer.h"
#include "src/game/nimgame/player/ComputerPlayer.h"
int main() {


    ConsoleWriter writer;
    atlas::game::player::HumanPlayer human{"Fritz"};
    atlas::game::player::ComputerPlayer hal{"HAL"};

    atlas::game::NimGameImpl impl{writer};
    impl.addPlayer(&human);
    impl.addPlayer(&hal);
    atlas::client::Client client{impl};
    client.go();

    return 0;
}

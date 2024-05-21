#include <iostream>
#include "src/client/Client.h"
#include "src/game/nimgame/NimGameImpl.h"

int main() {

    atlas::game::NimGameImpl impl;
    atlas::client::Client client{impl};
    client.go();

    return 0;
}

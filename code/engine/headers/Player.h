#include "../../utility/headers/FirstPersonController.h"

class Player
{
public:
    FirstPersonController* controller;
    Player(FirstPersonController* controller);
    void update();
};

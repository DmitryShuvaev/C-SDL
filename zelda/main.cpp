//pong

#include "GameManager.h"
int main(int argc, char* argv[]) {
    srand (time(NULL));
GameManager* game=GameManager::Instance();
game->Run();
GameManager::Release();
game=NULL;
    return 0;
}


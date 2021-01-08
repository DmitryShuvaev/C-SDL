//
#include <iostream>
#include <fstream>
#include "GameManager.h"
using namespace std;
//Data points
Sint32 gData[ 10 ];
int main(int argc, char* argv[]) {
    srand (time(NULL));
//string line;
//SDL_RWops *rw1 = SDL_RWFromFile("example.txt", "w");
//if(rw1 != NULL) {
//     char *str = "CTO   2000\n";
//    size_t len = SDL_strlen(str);
//    if (SDL_RWwrite(rw1, str, 1, len) != len) {
//        printf("Couldn't fully write string\n");
//    } else {
//        printf("Wrote %d 1-byte blocks\n", len);
//    }
//    str="CTO   ";
//    //str=str+"1000";
//    len = SDL_strlen(str);
//    if (SDL_RWwrite(rw1, str, 1, len) != len) {
//        printf("Couldn't fully write string\n");
//    } else {
//        printf("Wrote %d 1-byte blocks\n", len);
//    }
//    SDL_RWclose(rw1);
//}
//
//
//        SDL_RWops *rw = SDL_RWFromFile("example.txt", "rb");
//        if (rw == NULL) return NULL;
//
//        Sint64 res_size = SDL_RWsize(rw);
//        char* res = (char*)malloc(res_size + 1);
//
//        Sint64 nb_read_total = 0, nb_read = 1;
//        char* buf = res;
//        while (nb_read_total < res_size && nb_read != 0) {
//                nb_read = SDL_RWread(rw, buf, 1, (res_size - nb_read_total));
//                nb_read_total += nb_read;
//                buf += nb_read;
//                //line=buf;
//        }
//        SDL_RWclose(rw);
//        if (nb_read_total != res_size) {
//                free(res);
//                return NULL;
//        }
//
//        res[nb_read_total] = '\0';
//        cout<<res;
//  ofstream myfile1;
//  myfile1.open ("example.txt");
//  myfile1 << "100.\n";
//  myfile1 << "1000.\n";
//  myfile1 << "2000.\n";
//  myfile1.close();
//  //
//  char*str;
//  ifstream myfile ("example.txt");
//  if (myfile.is_open())
//  {
//    while ( getline (myfile,line) )
//    {
//
//      cout << line << '\n';
//    }
//    myfile.close();
//  }
//
//  else cout << "Unable to open file";
GameManager* game=GameManager::Instance();
game->Run();
GameManager::Release();
game=NULL;
//

    return 0;
}


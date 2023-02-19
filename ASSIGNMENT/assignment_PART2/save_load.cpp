#include <iostream>
#include <fstream>

using namespace std;

struct GameState {
    int alienLife;
    int alienAttack;
};

void saveGame(GameState state, string filename) {
    ofstream file(filename);
    file << state.alienLife << endl;
    file << state.alienAttack << endl;
    file.close();
    cout << "Game saved!" << endl;
}

void loadGame(GameState &state, string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> state.alienLife;
        file >> state.alienAttack;
        file.close();
        cout << "Game loaded!" << endl;
    } else {
        cout << "Unable to open file " << filename << endl;
    }
}

int main() {
    GameState state;

    cout << "Enter initial alien life: ";
    cin >> state.alienLife;

    cout << "Enter initial alien attack: ";
    cin >> state.alienAttack;

    saveGame(state, "savegame.txt");

    // Modify the game state
    state.alienLife = 250;
    state.alienAttack = 2;

    // Load the saved game
    loadGame(state, "savegame.txt");

    cout << "alienLife: " << state.alienLife << endl;
    cout << "alienAttack: " << state.alienAttack << endl;

    return 0;
}
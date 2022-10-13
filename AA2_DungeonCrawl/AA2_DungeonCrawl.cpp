#include <iostream>
#include "InputManager.h"
#include "ConsoleControl.h"

int main()
{
    InputManager* inputManager = new InputManager(std::vector<int>({ KB_UP, KB_DOWN, KB_LEFT, KB_RIGHT, KB_SPACE }));
    std::thread* listenerThread = new std::thread(&InputManager::StartListener, inputManager);
    listenerThread->detach();

    while (true) {
        if (inputManager->GetKey(KB_SPACE)) {
            
            cout << "Espacio presionado";

        }
    }
}

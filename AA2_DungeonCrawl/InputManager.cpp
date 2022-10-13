#include "InputManager.h"
#include "ConsoleControl.h"
#include <algorithm>

InputManager::InputManager(vector<int> validKeyCodes)
{
    this->validKeyCodes = validKeyCodes;
}

void InputManager::StartListener()
{
    activatedMutex->lock();
    bool isActivated = false;

    if (activated) //Aseguramos que la funcion de escuchar solo este activada 1 vez, si ya esta activada la finalizo con un return
    {
        activatedMutex->unlock();
        return;
    }
    else
    {
        activated = true;
        isActivated = activated;
        activatedMutex->unlock();
    }

    while (isActivated) //El bucle funcionara hasta que paremos el listener con la funcion StopListener
    {
        int keyCode = ConsoleControl::WaithForReadNextKey(); //Nos esperamos hasta que obtengamos una tecla pulsada

        if (find(validKeyCodes.begin(), validKeyCodes.end(), keyCode) != validKeyCodes.end()) //Compromavmos si esta en la lista de teclas validas
        {
            inputsReadMutex->lock();
            inputsRead->push_back(keyCode);
            inputsReadMutex->unlock();
        }

        activatedMutex->lock();
        isActivated = activated;
        activatedMutex->unlock();
    }
}

void InputManager::StopListener()
{
    activatedMutex->lock();
    activated = false;
    activatedMutex->unlock();
}

bool InputManager::GetKey(int keyCode)
{
    bool isReaded = false;

    inputsReadMutex->lock();
    for (int i = 0; i < inputsRead->size(); i++)
    {
        if ((*inputsRead)[i] == keyCode)
        {
            isReaded = true;
            inputsRead->erase(inputsRead->begin() + i);
            i--;
        }
    }
    inputsReadMutex->unlock();

    return isReaded;
}

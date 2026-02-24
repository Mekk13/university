#define _CRTDBG_MAP_ALLOC
#pragma once
#include <crtdbg.h>
#include "UI.h"

/*
(d) Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.!!!
*/

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Repository* repo = create_repo();
    Service* serv = create_service(repo);
    UI* ui = createUI(serv);

    generate_10_entries(serv);

    startUI(ui);
    destroyUI(ui);
    
    _CrtDumpMemoryLeaks();
    
    return 0;
}




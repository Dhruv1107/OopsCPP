#ifndef DESKTOPDIRECTOR
#define DESKTOPDIRECTOR

#include "desktopBuilder.hpp"

class DesktopDirector {
private:
    DesktopBuilder* desktopBuilder;
public:
    DesktopDirector(DesktopBuilder* pDesktopBuilder) {
        desktopBuilder = pDesktopBuilder;
    }

    Desktop* getDesktop() {
        return desktopBuilder->getDesktop();
    }

    Desktop* BuildDesktop() {
        desktopBuilder->buildMonitor();
        desktopBuilder->buildMouse();
        desktopBuilder->buildRam();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildKeyBoard();
        desktopBuilder->buildSpeaker();
        desktopBuilder->buildMotherBoard();
        return desktopBuilder->getDesktop();
    }
};

#endif // DESKTOPDIRECTOR

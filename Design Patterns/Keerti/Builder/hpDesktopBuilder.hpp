#ifndef HPDESKTOPBUILDER_HPP
#define HPDESKTOPBUILDER_HPP

#include "desktopBuilder.hpp"

class HpDesktopBuilder : public DesktopBuilder {
    void buildMonitor();
    void buildKeyBoard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();
};

#endif // HPDESKTOPBUILDER_HPP

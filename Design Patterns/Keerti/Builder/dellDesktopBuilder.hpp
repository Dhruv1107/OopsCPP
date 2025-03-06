#ifndef DELLDESKTOPBUILDER_HPP
#define DELLDESKTOPBUILDER_HPP

#include "desktopBuilder.hpp"

class DellDesktopBuilder : public DesktopBuilder {
    void buildMonitor();
    void buildKeyBoard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();
};

#endif // DELLDESKTOPBUILDER_HPP

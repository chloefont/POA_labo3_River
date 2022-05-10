/*
-----------------------------------------------------------------------------------
Nom du fichier  : ConsoleRenderer.hpp
Auteur(s)       : lucac
Date creation   : 10.05.2022
Description     : <à compléter>
Remarque(s)     : <à compléter>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------

*/

#ifndef LABO4_RIVER_CONSOLERENDERER_HPP
#define LABO4_RIVER_CONSOLERENDERER_HPP


#include "Renderer.hpp"

class ConsoleRenderer : public Renderer {
   void drawBoat(Boat boat) override;
   void drawContainer(Container &container) override;
   void drawMenu() override;
   void showWinMessage() override;
};


#endif //LABO4_RIVER_CONSOLERENDERER_HPP

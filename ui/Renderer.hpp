/*
-----------------------------------------------------------------------------------
Nom du fichier  : Renderer.hpp
Auteur(s)       : lucac
Date creation   : 10.05.2022
Description     : <à compléter>
Remarque(s)     : <à compléter>
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------

*/

#ifndef LABO4_RIVER_RENDERER_HPP
#define LABO4_RIVER_RENDERER_HPP

#include "../Container/Container.h"
#include "../Container/Boat.h"

class Renderer{
public:
   virtual void drawMenu() = 0;
   virtual void showWinMessage() = 0;
   virtual void drawContainer(Container& container) = 0;
   virtual void drawBoat(Boat boat) = 0;

   virtual ~Renderer() = default;
};
#endif //LABO4_RIVER_RENDERER_HPP

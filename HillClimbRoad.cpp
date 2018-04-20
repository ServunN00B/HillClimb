//Includes 

#include <vector>
#include "HillClimbRoad.h"
#include "HillClimbUtility.h"
#include "HillClimbLayer.h"

namespace hillclimb {

   double ROAD_LENGHT_FACTOR = 2;
   double DEFAULT_ROAD_LENGTH = 3;
   std::vector<Coordinates> partCoords(Coordinates);

   HillClimbRoad::HillClimbRoad(const int winWidth, const int winHeight){}

   int HillClimbRoad::getPartCount() {
       return this->partCoords.size();
   }

   Coordinates HillClimbRoad::getPartCoords() {
       return this->partCoords.back();
   }

   void HillClimbRoad::addPart(double x, double y) {
       Coordinates partCoord = {
           .x = x,
           .y = y
       };
       this->partCoords.push_back(partCoord);
   }

   double HillClimbRoad::calculateNewPartX() {
       if (HillClimbRoad::getPartCount()< 1) {
            return static_cast<double>(std::rand() % 10);
       } else {
            return static_cast<double>(std::rand() % 10) + HillClimbRoad::getPartCoords().x;
       }
       //randomize length of the new part using some factor
   }

   double HillClimbRoad::calculateNewPartY() {
       return static_cast<double>(std::rand() % 50 +1);
       //randomize y position of the end point of the new part
   }

   void HillClimbRoad::generatePartsAhead() {
       if (HillClimbRoad::getPartCount()< HillClimbRoad::MAX_PART_COUNT) {
           int partsNeeded = HillClimbRoad::MAX_PART_COUNT - HillClimbRoad::getPartCount();
           while(partsNeeded > 0) {
               HillClimbRoad::addPart(HillClimbRoad::calculateNewPartX(),HillClimbRoad::calculateNewPartY());
               partsNeeded -= 1;
           }
       }
      //generate parts as many as MAX_PART_COUNT - currentPartCount
   }

   void HillClimbRoad::deletePartsBehind() {
       for(int i = 0; i < HillClimbRoad::getPartCount(); ++i) {
            double roadMin = HillClimbRoad::DEFAULT_ROAD_LENGTH * HillClimbRoad::ROAD_LENGHT_FACTOR;
            if (HillClimbRoad::partCoords.front().x < roadMin) {
                HillClimbRoad::partCoords.erase(HillClimbRoad::partCoords.begin());
            }
       }
      //delete parts whose x < -DEFAULT_ROAD_LENGTH * ROAD_LENGTH_FACTOR
   }
/*
   move(x) {
       move the x's of parts
       deletePartsBehind
       generatePartsAhead
   }

   reset {
       clear partCoords
       add two horizontal parts
       generatePartsAhead
   }
*/
}

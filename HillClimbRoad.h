
//Guards

//Includes
#include <vector>
#include "HillClimbUtility.h"

namespace hillclimb {
    
    class HillClimbRoad {
        public:
            int MAX_PART_COUNT;
            int X_ROAD_START;
            int Y_ROAD_START;
            double ROAD_LENGHT_FACTOR;
            double DEFAULT_ROAD_LENGTH;
            std::vector<Coordinates> partCoords;
            

            HillClimbRoad(const int, const int);
            //move(const int);
            Coordinates getPartCoords();
            int getPartCount();
            void addPart(double x, double y);
            //reset();
        private:
            double calculateNewPartX();
            double calculateNewPartY();
            void generatePartsAhead();
            void deletePartsBehind();
    };
}
//Guards end


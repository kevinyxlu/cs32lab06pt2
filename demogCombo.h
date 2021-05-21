#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"

/*
  class to represent combined demographic data 
*/
class demogCombo : public demogData {
  public:
    demogCombo(string inS, std::vector<shared_ptr<demogData>> inDemogData);

    //gets percents for the demogCombo
    double getPopOver65() const { return popOver65; }
    double getPopUnder18() const { return popUnder18; }
    double getPopUnder5() const { return popUnder5; }
    double getPopBAPlus() const { return popBachelorEduPlus; }
    double getPopHSPlus() const { return popHighSchoolEduPlus; }
    double getPopPoverty() const { return popInPoverty; }
    //gets counts for the demogCombo
    int getCountOver65() const { return countOver65; }
    int getCountUnder18() const { return countUnder18; }
    int getCountUnder5() const { return countUnder5; }
    int getCountBAPlus() const { return countBAPlus; }
    int getCountHSPlus() const { return countHSPlus; }
    int getCountPoverty() const { return countPoverty; }

  friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

private:
    int numData = 0;
    
    int countOver65 = 0;
    int countUnder18 = 0;
    int countUnder5 = 0;
    int countBAPlus = 0;
    int countHSPlus = 0;
    int countPoverty = 0;
};
#endif

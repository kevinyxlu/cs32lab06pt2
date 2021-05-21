#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here
demogCombo::demogCombo(string inS, std::vector<shared_ptr<demogData>> inDemogData) : demogData(inS, inS) {
    numData = inDemogData.size();

    for (auto entry : inDemogData) {
        setPop(population + entry->getPop());
        countOver65 += entry->getCountOver65();
        countUnder18 += entry->getCountUnder18();
        countUnder5 += entry->getCountUnder5();
        countBAPlus += entry->getCountBAPlus();
        countHSPlus += entry->getCountHSPlus();
        countPoverty += entry->getCountPoverty();
        raceData += entry->getRaceData();

        popOver65 = (countOver65 / double(population)) * 100; 
        popUnder18 = (countUnder18 / double(population)) * 100; 
        popUnder5 = (countUnder5 / double(population)) * 100; 
        popBachelorEduPlus = (countBAPlus / double(population)) * 100; 
        popHighSchoolEduPlus = (countHSPlus / double(population)) * 100; 
        popInPoverty = (countPoverty / double(population)) * 100; 
    }
}

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {
    out << std::setprecision(2) << std::fixed;
    out << "State Demographic Info: State Info: " << ComboD.getState() << endl; 
    out << "Number of Counties: " << ComboD.numData << endl; 
    out << "Population Info:\n";
    out << "(over 65): " << ComboD.popOver65 << "% and total: " << ComboD.countOver65 << endl;
    out << "(under 18): " << ComboD.popUnder18 << "% and total: " << ComboD.countUnder18 << endl; 
    out << "(under 5): " << ComboD.popUnder5 << "% and total: " << ComboD.countUnder5 << endl; 
    out << "Education info:\n"; 
    out << "(Bachelor or more): " << ComboD.popBachelorEduPlus << "% and total: " << ComboD.countBAPlus << endl; 
    out << "(high school or more): " << ComboD.popHighSchoolEduPlus << "% and total: " << ComboD.countHSPlus << endl;
    out << "persons below poverty: " << ComboD.popInPoverty << "% and total: " << ComboD.countPoverty << endl;
    
    out << "community racial demographics: ";
    out << ComboD.raceData << endl;
    out << "Total population: " << ComboD.population;
    return out;
}

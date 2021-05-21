#include <iomanip>
#include "psCombo.h"

psCombo::psCombo(string inS, vector<shared_ptr<psData>> inPSData) : regionData(inS, inS) {
    int whiteCount = 0;
    for (auto entry : inPSData) {
        if (entry->getState() == inS) {
            if (entry->getSignsMIll()) numMentalIllness++;
            if (entry->getFlee() != "Not fleeing" && entry->getFlee().length()) fleeingCount++;
            if (entry->getAge() >= 65) casesOver65++;
            else if (entry->getAge() <= 18) casesUnder18++;
            if (entry->getGender() == 'M') numMales++;
            else if (entry->getGender() == 'F') numFemales++;
            
            if(entry->getRace() != '\0' && entry->getRace() != ')')
            {
                if (entry->getRace() == 'W') { 
                    racialData.addWhiteCount(1);
                    racialData.addWhiteNHCount(1);
                    whiteCount = whiteCount + 1;
                }
                else if (entry->getRace() == 'A') racialData.addAsianCount(1);
                else if (entry->getRace() == 'B') racialData.addBlackCount(1);
                else if (entry->getRace() == 'H') racialData.addLatinxCount(1);
                else if (entry->getRace() == 'N') racialData.addFirstNationCount(1);
                else racialData.addOtherCount(1);
                numCases++;
            }
        }
    }
    racialData.addCommunityCount(numCases + whiteCount);
}

/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.getCasesOver65();
    out << "\n(19 to 64): " << PD.getNumberOfCases() - PD.getCasesOver65() - PD.getCasesUnder18();
    out << "\n(under 18): " << PD.getCasesUnder18();
    out << "\nIncidents involving fleeing: " << PD.getFleeingCount();
    out << "\nIncidents involving mental illness: " << PD.getNumMentalI();
    out << "\nMale incidents: " <<  PD.getnumMales() << " female incidents: " << PD.getnumFemales();
    out << "\nRacial demographics of state incidents: " << PD.getRacialData();
    return out;
}
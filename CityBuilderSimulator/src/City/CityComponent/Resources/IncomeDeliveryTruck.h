#ifndef INCOMEDELIVERYTRUCK_H
#define INCOMEDELIVERYTRUCK_H
#include "IncomeTruck.h"
#include "Gold.h"
#include "Oil.h"
#include "Diamonds.h"
#include "Coal.h"

class IncomeDeliveryTruck: public IncomeTruck{
public:

    void update();
protected:
    Gold* goldSubject;
    Oil* oilSubject;
    Diamonds* diamondSubject;
    Coal* coalSubject;

};
#endif
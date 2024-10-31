#include "IncomeDeliveryTruck.h"
#include <iostream>
using namespace std;

void IncomeDeliveryTruck::update(){
    if(goldSubject->isReadyForCollection()){
        cout<< "Collecting Gold "<<"\n";
        goldSubject->consumeResources(120);
    }else if(coalSubject->isReadyForCollection()){
        cout<< "Collect Coal "<<"\n";
        coalSubject->consumeResources(120);

    }else if(oilSubject->isReadyForCollection()){
        cout<<"Collecting Oil "<<"\n";
        oilSubject->consumeResources(120);
    }else{
        if(diamondSubject->isReadyForCollection()){
            cout<<"Collecting Diamond "<<"\n";
            diamondSubject->consumeResources(120);
        }
    }
}

#ifndef INCOMERESOURCEPROCESSOR_H
#define INCOMERESOURCEPROCESSOR_H

#include "ResourceProcessor.h"
#include "IncomeResourceProduct.h"
#include "Government.h"
#include <memory>

class IncomeResourceProcessor : public ResourceProcessor {
private:
    std::shared_ptr<IncomeResourceProduct> resource;
    int currentStorage;
    const int maxStorage;
public:
    IncomeResourceProcessor(std::shared_ptr<IncomeResourceProduct> res, int maxStorage = 200);
    void process(int amount);
    void store(int amount);
    void display() const;
    int getCurrentStorage() const;

};

#endif
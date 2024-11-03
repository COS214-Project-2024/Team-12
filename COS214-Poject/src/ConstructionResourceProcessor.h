#ifndef CONSTRUCTIONRESOURCEPROCESSOR_H
#define CONSTRUCTIONRESOURCEPROCESSOR_H

#include "ResourceProcessor.h"
#include "ConstructionResourceProduct.h"
#include "Government.h"
#include <memory>

class ConstructionResourceProcessor : public ResourceProcessor {
private:
    std::shared_ptr<ConstructionResourceProduct> resource;
    int currentStorage;
    const int maxStorage;
public:
    ConstructionResourceProcessor(std::shared_ptr<ConstructionResourceProduct> res, int maxStorage);

    void process(int amount);
    void store(int amount);
    void display() const;
    int getCurrentStorage() const;

};

#endif
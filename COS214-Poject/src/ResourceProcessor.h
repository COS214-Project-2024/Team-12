#ifndef RESOURCEPROCESSOR_H
#define RESOURCEPROCESSOR_H

class ResourceProcessor {
public:
    virtual void process(int amount) = 0;
    virtual void store(int amount) = 0;
    virtual void display() const = 0;
    virtual int getCurrentStorage() const = 0;
    virtual ~ResourceProcessor() = default;
};

#endif
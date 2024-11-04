#include "HospitalFactory.h"
#include "Hospital.h"

/**
 * @file HospitalFactory.cpp
 * @brief Implementation of the HospitalFactory class.
 *
 * This file contains the implementation of the methods defined in the
 * HospitalFactory class, specifically the method for creating
 * Hospital objects.
 */

/**
 * @brief Creates a new Hospital instance.
 * 
 * This method creates and returns a unique pointer to a newly
 * instantiated Hospital object. The Hospital is constructed using
 * the default constructor, which initializes its attributes.
 *
 * @return A unique pointer to the created Hospital object.
 */
std::unique_ptr<PublicService> HospitalFactory::createPublicService() {
    return std::make_unique<Hospital>();
}

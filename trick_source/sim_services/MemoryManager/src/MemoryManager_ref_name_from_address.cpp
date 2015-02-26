/*
 @file
 $Id$
 */
#include "sim_services/MemoryManager/include/MemoryManager.hh"
#include "sim_services/CheckPointAgent/include/ClassicCheckPointAgent.hh"

/**
 @par Detailed Description:
 */
std::string Trick::MemoryManager::ref_name_from_address( void* address) {

    std::string result;

    Trick::ClassicCheckPointAgent* agent = dynamic_cast<Trick::ClassicCheckPointAgent*>(defaultCheckPointAgent);
    if (agent) {
        result = agent->ref_string_from_ptr( address, NULL, 0);
    } else {
        result.clear();
    }
    return (result);
}

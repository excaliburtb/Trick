#include "sim_services/CheckPointAgent/include/CheckPointAgent.hh"

// MEMBER FUNCTION
void Trick::CheckPointAgent::push_basename( const char* name) {

    VarNameElement *part = new VarNameElement;

    part->type = BASE_NAME;
    part->name = name;
    leftside_stack.push_back( part);
}

// MEMBER FUNCTION
void Trick::CheckPointAgent::push_struct_elem( const char* name) {

    VarNameElement *part = new VarNameElement;

    part->type = ELEM_NAME;
    part->name = name;
    leftside_stack.push_back( part);
}

// MEMBER FUNCTION
void Trick::CheckPointAgent::push_array_elem( int index) {

    VarNameElement *part = new VarNameElement;

    part->type = ARRAY_INDEX;
    part->index = index;
    leftside_stack.push_back( part);
}

// MEMBER FUNCTION
void Trick::CheckPointAgent::pop_elem() {

    leftside_stack.pop_back();
    // FIXME Memory leak here?

}

void Trick::CheckPointAgent::set_debug_level(int level) {
    debug_level = level;
}

void Trick::CheckPointAgent::set_reduced_checkpoint(bool flag) {
    reduced_checkpoint = flag;
}

void Trick::CheckPointAgent::set_hexfloat_checkpoint(bool flag) {
    hexfloat_checkpoint = flag;
}


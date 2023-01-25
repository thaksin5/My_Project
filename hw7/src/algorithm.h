#ifndef ALGORITHM
#define ALGORITHM

#include "alcohol.h"
#include <iostream>
#include <algorithm>
#include <vector>


// sort_alcohol_content
bool compare_content(Alcohol *a, Alcohol *b){
    if(a->get_alcohol_content() != b->get_alcohol_content()){
        return a->get_alcohol_content() < b->get_alcohol_content();
    }else{
        return a->get_name() < b->get_name();
    }
    return false;
}

void sort_alcohol_by_content(std::vector<Alcohol*> &alcohol){
    std::sort(alcohol.begin(), alcohol.end(), compare_content);
}

// sort_alcohol_name
bool compare_name(Alcohol *a, Alcohol *b){
    return a->get_name() < b->get_name();
}

void sort_alcohol_by_name(std::vector<Alcohol*> &alcohol){
    std::sort(alcohol.begin(), alcohol.end(), compare_name);
}

// get_greatest_content_of_alcohol
// lexicographical order
Alcohol* get_greatest_content_of_alcohol(std::vector<Alcohol*> alcohol){
    std::sort(alcohol.rbegin(), alcohol.rend(), compare_content);
    return alcohol[0];
}

// get_smallest_content_of_alcohol
// lexicographical reverse order
Alcohol* get_smallest_content_of_alcohol(std::vector<Alcohol*> alcohol){
    std::sort(alcohol.begin(), alcohol.end(), compare_content);
    return alcohol[0];
}


#endif
#include <iostream>
#include "user/user.h"
#include "teacher/teacher.h"

int main(){
    Teacher t;
    User &u = t;
    
    u.output();

    return 0;
}
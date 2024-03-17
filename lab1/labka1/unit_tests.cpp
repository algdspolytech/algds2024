#include "header.h"


void Test_way_pay  (){  
    
    int num_array[1][1] = { 10 };
    assert(way_pay(&num_array[0][0], 1, 0, 0) == 10); 

 
    int special_array[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    assert(way_pay(&special_array[0][0], 3, 2, 0) == 0); 

    int zero_cost_array[3][3] = {{1,2,3}, {0,0,0}, {7,8,9} };
    assert(way_pay(&zero_cost_array[0][0], 3, 2, 0) == 10);

    int empty_array[SIZE][SIZE] = { {} };
    assert(way_pay(&empty_array[0][0], 0, 0, 0) == NULL);

    int boundary_array[3][3] = { {1,2,3}, {4,5,6},{7,8,9} };
    assert(way_pay(&boundary_array[0][0], 3, 2, 0) == 15);
    assert(way_pay(&boundary_array[0][0], 3, 2, 2) == 18);


    int different_array[3][3] = { {1,2,-6}, {-3,0,15},{-2,-48,4} };
    assert(way_pay(&different_array[0][0], 3, 2, 1) == -31);


    assert(way_pay(&boundary_array[0][0], -2, 0, 0) == NULL);
    assert(way_pay(&boundary_array[0][0], 3, -4, 0) == NULL);
    assert(way_pay(&boundary_array[0][0], 3, 0, 6) == NULL);
    assert(way_pay(&boundary_array[0][0], 3, 2, -4) == NULL);


    printf("All tests passed!\n");

}

#include "main.h"
#include <gtest/gtest.h>

TEST(min_in_array, usual_array)
{
    int input[10] = {2, 4, 7, -1, 1, -2, 0, 4, 2, 1};
    
    int_pair p = min_in_array(input, 10);

    ASSERT_EQ(p.value, -2);
    ASSERT_EQ(p.shift, 5);
}

TEST(min_in_cell, central_column)
{
    matrix input;
    int i[6] = { 0, 0, 0, 
                2, 1, 3};
    input.coeff = i;
    input.line_size = 3;
    input.column_size = 2;

    int_pair p = min_in_cell(&input, 0, 1);

    ASSERT_EQ(p.value, 1);
    ASSERT_EQ(p.shift, 1);
}

TEST(min_in_cell, left_column)
{
    matrix input;
    int i[6] = { 0, 0, 0, 
                2, 1, 3};
    input.coeff = i;
    input.line_size = 3;
    input.column_size = 2;

    int_pair p = min_in_cell(&input, 0, 0);

    ASSERT_EQ(p.value, 1);
    ASSERT_EQ(p.shift, 1);
}

TEST(min_in_cell, right_column)
{
    matrix input;
    int i[6] = { 0, 0, 0, 
                2, 1, 3};
    input.coeff = i;
    input.line_size = 3;
    input.column_size = 2;

    int_pair p = min_in_cell(&input, 0, 1);

    ASSERT_EQ(p.value, 1);
    ASSERT_EQ(p.shift, 1);
}

TEST(create_sptable, first_case)
{
    matrix input;
    int i[9] = { -1, 3, 1,
                2, 1, 3,
                0, 1, 4};
    input.coeff = i;
    input.line_size = 3;
    input.column_size = 3;

    matrix res = create_sptable(&input);

    EXPECT_EQ(MII(res, 0, 0), 0);
    EXPECT_EQ(MII(res, 0, 1), 4);
    EXPECT_EQ(MII(res, 0, 2), 2);
    free(res.coeff);
}

TEST(create_sptable, second_case)
{
    matrix input;
    int i[12] = { 0, 0, 0,
                10, 100, 0, 
                0, 100, 10,
                0, 100, 10};
    input.coeff = i;
    input.line_size = 3;
    input.column_size = 4;

    matrix res = create_sptable(&input);

    EXPECT_EQ(MII(res, 0, 0), 10);
    EXPECT_EQ(MII(res, 0, 1), 10);
    EXPECT_EQ(MII(res, 0, 2), 20);
    free(res.coeff);
}

TEST(find_path, first_case)
{
    matrix input;
    int i[9] = { 0, 4, 2,
                2, 1, 4, 
                0, 1, 4 };
    input.coeff = i;
    input.line_size = 3;
    input.column_size = 3;

    int* res = find_path(&input, 0);

    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 1);
    EXPECT_EQ(res[2], 0);
    free(res);
}

TEST(Shortest_way_price, trivial_case)
{
    matrix input;
    int i[3] = { 20,
                 10,
                  2};
    input.coeff = i;
    input.line_size = 1;
    input.column_size = 3;

    path res = Shortest_way_price(&input);

    EXPECT_EQ(res.min_price, 32);
    EXPECT_EQ(res.path_coor[0], 0);
    EXPECT_EQ(res.path_coor[1], 0);
    EXPECT_EQ(res.path_coor[2], 0);
    free(res.path_coor);
}

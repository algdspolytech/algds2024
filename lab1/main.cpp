#include <stdio.h>
#include <string.h>
#include <gtest/gtest.h>
using namespace std;

int  max_len_array (int array[], int B[], int number_of_elements)
{
    int answer=0;                   // ������������ ����� ������������ ������������������
    int max_len_i;                  // ����. ����� ������������ ������������������, ��������������� �� �[i]
    for (int i = 0; i < number_of_elements; i++){
        max_len_i=0;
        for (int k=0; k < i; k++){
            if (array[k]<array[i]){
                    if (max_len_i < B[k])
                        {max_len_i=B[k];
                    }
            }
        }
        B[i]=max_len_i+1;

        if (B[i]>answer){answer=B[i];}
    }

    return answer;
}

int max(int array[], int number_of_elements)
{
    int maximum=array[0];
    for (int i=0; i<number_of_elements; i++){
        if (array[i]>maximum){maximum=array[i];}
    }
    return maximum;
}

void print_max_array (int array[], int B[], int number_of_elements)
{
    int max_element, max_len, new_array[number_of_elements], k=0;
    max_len=max_len_array(array, B, number_of_elements);
    max_element=max(array, number_of_elements)+1;


    for (int i=number_of_elements; i>=0; i--){
        if (B[i]==max_len && array[i] < max_element){
            max_len-=1;
            max_element=array[i];
            new_array[k]=array[i];
 
            k+=1;
        }
    }
    for (int i=k-1; i>=0; i--){
        printf("%d ", new_array[i]);
    }

}
TEST(MaxLenARRAY, empty){
	int n=0;
	int A[n], B[n];
	EXPECT_EQ(0, max_len_array(A,B,n));
}
TEST(MaxLenARRAY, strictly_increasing){
	int n=4;
	int A[n], B[n];
	A[0]=1; A[1]=2; A[2]=3; A[3]=4;
	EXPECT_EQ(4, max_len_array(A,B,n));		
}
TEST(MaxLenARRAY, stationary_sequence){
	int n=4;
	int A[n], B[n];
	A[0]=1; A[1]=1; A[2]=1; A[3]=1;
	EXPECT_EQ(1, max_len_array(A,B,n));		
}
TEST(MaxLenARRAY,1_5_6_2_7_3_4_5){
	int n=8;
	int A[n], B[n];
	 A[0]=1;
	 A[1]=5; 
	 A[2]=6;
	 A[3]=2;
	 A[4]=7;
	 A[5]=3; 
	 A[6]=4;
	 A[7]=5;
	EXPECT_EQ(5, max_len_array(A,B,n));		
}
TEST(Max, one_element){
	int n=1;
	int A[n];
	A[0]=1;
	EXPECT_EQ(1, max(A,n));
}
TEST(Max, random){
	int n=8;
	int A[n];
	A[0]=7; A[1]=2; A[2]=-7; A[3]=10; A[4]=1; A[5]=7; A[6]=0; A[7]=4;
	EXPECT_EQ(10,max(A, n));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();


   /* int number_of_elements, answer; // ����� �������� ������������������
    scanf("%d", &number_of_elements);
    int array[number_of_elements];
    int B[number_of_elements];
    for (int i = 0; i < number_of_elements; i++) { //�������� ������������������
            scanf("%d", &array[i]);
    }
    printf("The longest strictly increasing sequence:\n");
    print_max_array(array, B, number_of_elements);
    printf("\n");
    printf("%d number(s) crossed out\n", number_of_elements-max_len_array(array, B, number_of_elements));
    */
}

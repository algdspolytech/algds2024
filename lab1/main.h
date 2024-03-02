#include <stdlib.h>

#define STRUCT typedef struct

STRUCT {
    int* coeff;
    int line_size;
    int column_size;
} matrix;

matrix create_matrix(int line_size, int column_size)
{
    matrix m;
    m.coeff = (int*)malloc(sizeof(int)*line_size*column_size);
    if(m.coeff == NULL) abort();
    m.line_size = line_size;
    m.column_size = column_size;
    return m;
}

#define MII(m, i, j) *((m).coeff + (i)*(m).line_size + (j))
#define MIIP(m, i, j) *((m)->coeff + (i)*(m)->line_size + (j))
#define MSH(m, i, j) (m).coeff + (i)*(m).line_size + (j)
#define MSHP(m, i, j) (m)->coeff + (i)*(m)->line_size + (j)

STRUCT {
    int value;
    size_t shift;
} int_pair;

STRUCT {
    int min_price;
    int* path_coor;
} path;

matrix create_sptable(matrix* prices);
int_pair min_in_array(int* array, int length);
int_pair min_in_cell(matrix* table, size_t row, size_t column);
int* find_path(matrix* table, size_t start);
path Shortest_way_price(matrix* prices);

int_pair min_in_array(int* array, int length)
{
    int_pair m ;
    m.value = array[0];
    m.shift = 0;
    for(size_t i = 1; i != length; ++i){
        if(array[i] < m.value){
            m.value = array[i];
            m.shift = i;
        } 
    }
    return m;
}

int_pair min_in_cell(matrix* table, size_t row, size_t column)
{
    int_pair m;
    if( column == 0){
        m = min_in_array(MSHP(table, row+1, 0), 2);
        return m;
    }
    if( column == table->line_size-1){
        m = min_in_array(MSHP(table, row+1, column-1), 2);
        m.shift += column -1;
        return m;
    }
    m = min_in_array(MSHP(table, row+1, column-1), 3);
    m.shift += column -1;
    return m;
}

matrix create_sptable(matrix* prices)
{
    matrix sptable = create_matrix(prices->line_size, prices->column_size);
    for(size_t column = 0; column != sptable.line_size; ++column){
            MII(sptable,sptable.column_size-1, column) = MIIP(prices,sptable.column_size-1, column) ;
        }
    for(size_t row = sptable.column_size-2; row != -1; --row){
        for(size_t column = 0; column != sptable.line_size; ++column){
            MII(sptable, row, column) = MIIP(prices, row, column) + min_in_cell(&sptable, row, column).value;
        }
    }
    return sptable;
}

int* find_path(matrix* table, size_t start)
{
    int* path = (int*)malloc(sizeof(int)*table->column_size);
    if(path == NULL) abort();
    path[0] = start;
    for(size_t i = 1; i != table->column_size; ++i ){
        path[i] = min_in_cell(table, i-1, path[i-1]).shift;
    }
    return path;
}

path Shortest_way_price(matrix* prices)
{   
    path p;
    p.min_price = 0;
    if(prices->line_size == 1){
        p.path_coor = (int*)malloc(sizeof(int)*prices->column_size);
        for( size_t i = 0; i != prices->column_size; ++i){
            p.min_price += MIIP(prices, 0, i);
            p.path_coor[i] = 0;
        }
    }
    else{
    matrix sptable = create_sptable(prices);
    int_pair m = min_in_array(MSH(sptable, 0, 0), sptable.line_size);
    p.min_price = m.value;
    p.path_coor = find_path(&sptable, m.shift);
    free(sptable.coeff);
    }
    return p;
}

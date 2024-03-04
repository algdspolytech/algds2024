#include "framework.h"

FILE* OpenFile(char* name, char* mode) {
    FILE* fp;

    if ((fp = fopen(name, mode)) == NULL) {
        printf("Failed to open %s", name);
        exit(1);
    }

    return fp;
}

void CloseFile(const FILE* file) {
    fclose(file);
}

int Compare(const Thing* a, const Thing* b) {
    if (a->weight < b->weight) return -1;
    else if (a->weight > b->weight) return 1;
    else return 0;
}

int MaxSum(const Thing* f, const int size, const int sum_before) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += (f[i].cost * f[i].weight);
    }

    if (sum < sum_before) {
        return sum_before;
    }
    else return sum;
}

int FindSum(const struct Data* data) {
    size_t F_size = 0;
    Thing* f = NULL;
    size_t f_size = 0;
    int w_sum = 0;

    int sum = 0;

    for (size_t i = 0; i < data->size; ++i) {
        if (w_sum + data->t[i].weight <= data->a) {
            w_sum += data->t[i].weight;
            ++f_size;
            f = (Thing*)realloc(f, f_size * sizeof(Thing));
            f[f_size - 1].weight = data->t[i].weight;
            f[f_size - 1].cost = data->t[i].cost;
        }
        else {
            sum = MaxSum(f, f_size, sum);

            w_sum -= f[f_size - 1].weight;
            --f_size;

            while (w_sum + data->t[i].weight > data->a && f_size > 0) {
                --f_size;
                w_sum -= f[f_size].weight;
            }

            w_sum += data->t[i].weight;
            ++f_size;
            f = (Thing*)realloc(f, f_size * sizeof(Thing));
            f[f_size - 1].weight = data->t[i].weight;
            f[f_size - 1].cost = data->t[i].cost;
        }
    }

    if (f_size > 0) {
        sum = MaxSum(f, f_size, sum);
    }
    free(f);

    return sum;
}

int Finder(struct Data data) {
    for (size_t i = 0; i < data.size; ++i) {
        if (data.t[i].weight > data.a || data.t[i].weight <= 1) return 0;
    }
    qsort(data.t, data.size, sizeof(Thing), Compare);
    return FindSum(&data);
}

void Init(const FILE* file, Data* data) {
    fscanf(file, "%d %d", &(*data).a, &(*data).size);

    (*data).t = (Thing*)malloc((*data).size * sizeof(Thing));
    for (int i = 0; i < (*data).size; ++i) {
        fscanf(file, "%d", &(*data).t[i].weight);
    }

    for (int i = 0; i < (*data).size; ++i) {
        fscanf(file, "%d", &(*data).t[i].cost);
    }
}
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

int Compare(const void* a, const void* b) {
    Thing* thing1 = (Thing*)a;
    Thing* thing2 = (Thing*)b;

    if (thing1->weight < thing2->weight) return -1;
    else if (thing1->weight > thing2->weight) return 1;
    else return 0;
}

void AddToResult(Thing*** F, size_t* F_size, Thing* f, size_t f_size, int data_size) {
    ++(*F_size);
    *F = (Thing**)realloc(*F, *F_size * sizeof(Thing*));

    // Используем calloc для выделения памяти и автоматического заполнения нулями
    (*F)[*F_size - 1] = (Thing*)calloc(f_size, data_size * sizeof(Thing));
    memcpy((*F)[*F_size - 1], f, f_size * sizeof(Thing));
}

void FMatrix(Thing** F, Data data) {
    size_t F_size = 0;
    Thing* f = NULL;
    size_t f_size = 0;
    int w_sum = 0;

    for (size_t i = 0; i < data.size; ++i) {
        if (w_sum + data.t[i].weight <= data.a) {
            w_sum += data.t[i].weight;
            ++f_size;
            f = (Thing*)realloc(f, f_size * sizeof(Thing));
            f[f_size - 1].weight = data.t[i].weight;
            f[f_size - 1].cost = data.t[i].cost;
        }
        else {
            AddToResult(&(*F), &F_size, f, f_size, data.size);

            w_sum -= f[f_size - 1].weight;
            --f_size;

            while (w_sum + data.t[i].weight > data.a && f_size > 0) {
                --f_size;
                w_sum -= f[f_size].weight;
            }

            w_sum += data.t[i].weight;
            ++f_size;
            f = (Thing*)realloc(f, f_size * sizeof(Thing));
            f[f_size - 1].weight = data.t[i].weight;
            f[f_size - 1].cost = data.t[i].cost;
        }
    }

    if (f_size > 0) {
        AddToResult(&(*F), &F_size, f, f_size, data.size);
    }
    free(f);
}

int FindingI(Thing** F, Data data) {
    int max_sum_c = 0;
    Thing* max_subset = (Thing*)calloc(data.size, sizeof(Thing));
    for (size_t i = 0; i < sizeof(F) / sizeof(F[0]) + 1; ++i) {
        int max_sum_line_c = 0;
        for (size_t j = 0; j < sizeof(F[i]); ++j) {
            if (F[i][j].cost == 0) break;
            max_sum_line_c += F[i][j].cost;
        }
        if (max_sum_line_c > max_sum_c) {
            max_sum_c = max_sum_line_c;
            memcpy(max_subset, F[i], sizeof(F[i]) * sizeof(Thing));
        }
    }
    return max_sum_c;
}

int Finder(struct Data data) {
    for (size_t i = 0; i < data.size; ++i) {
        if (data.t[i].weight > data.a || data.t[i].weight <= 1) return 0;
    }

    qsort(data.t, data.size, sizeof(Thing), Compare);

    Thing** F = NULL;
    FMatrix(&F, data);

    int sum = FindingI(F, data);

    free(F);
    return sum;
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
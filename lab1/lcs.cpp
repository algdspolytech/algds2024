/* 2023/2024 - 2 semester, Data design in applications
 * Author: Pavel Dvas, 5030102/20002
 * File Name: lcs.cpp
 * Last Updated: 13.02.2024
 */

/* Necessary includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lcs.h"

/* Print the longest common subsequence function.
 * ARGUMENTS:
 *   - the 'direction' array:
 *       int *Dir;
 *   - the sequence itself:
 *       char *X;
 *   - the output buffer:
 *       char *Buf;
 *   - the coordinates:
 *       int i, j;
 *   - start flag:
 *       int StartFlag;
 * RETURNS: None.
 */
void PrintLCS( int *Dir, char *X, char *Buf, int i, int j, int StartFlag )
{
    int n = strlen(X);
    static int Length;

    if (StartFlag)
        Length = 0;

    if (i == 0 || j == 0)
        return;
    if (Dir[(i - 1) * n + (j - 1)] == 0)
    {
        PrintLCS(Dir, X, Buf, i - 1, j - 1, 0);
        Length += sprintf(Buf + Length, "%c", X[j - 1]);
    }
    else if (Dir[(i - 1) * n + (j - 1)] == 1)
        PrintLCS(Dir, X, Buf, i - 1, j, 0);
    else
        PrintLCS(Dir, X, Buf, i, j - 1, 0);
} /* End of 'PrintLCS' function */

/* Find the longest common subsequence function.
 * ARGUMENTS:
 *   - the first sequence:
 *       char *X;
 *   - the second sequence:
 *       char *Y;
 * RETURNS:
 *   - (char *) - output buffer;
 */
char * FindLCS( char *X, char *Y )
{
    int XLen = strlen(X), YLen = strlen(Y);
    int *Dir, *Lens, i, j, max_len = 0;
    char *Buf;

    if ((Dir = (int *)malloc(XLen * YLen * sizeof(int))) == NULL)
        return NULL;
    if ((Lens = (int *)malloc((XLen + 1) * (YLen + 1) * sizeof(int))) == NULL)
        return NULL;

    for (i = 1; i <= XLen; i++)
        Lens[i * (YLen + 1)] = 0;
    for (j = 0; j <= YLen; j++)
        Lens[j] = 0;

    for (i = 1; i <= XLen; i++)
        for (j = 1; j <= YLen; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                Lens[i * (YLen + 1) + j] = Lens[(i - 1) * (YLen + 1) + j - 1] + 1;
                if (Lens[i * (YLen + 1) + j] > max_len)
                    max_len = Lens[i * (YLen + 1) + j];
                Dir[(i - 1) * YLen + j - 1] = 0;
            }
            else if (Lens[(i - 1) * (YLen + 1) + j] >= Lens[i * (YLen + 1) + j - 1])
            {
                Lens[i * (YLen + 1) + j] = Lens[(i - 1) * (YLen + 1) + j];
                Dir[(i - 1) * YLen + j - 1] = 1;
            }
            else
            {
                Lens[i * (YLen + 1) + j] = Lens[i * (YLen + 1) + j - 1];
                Dir[(i - 1) * YLen + j - 1] = 2;
            }
        }


    if ((Buf = (char *)malloc(max_len + 1)) == NULL)
        return NULL;
    PrintLCS(Dir, Y, Buf, XLen, YLen, 1);

    Buf[max_len] = 0;

    if (Dir != NULL)
        free(Dir), Dir = NULL;
    if (Lens != NULL)
        free(Lens), Lens = NULL;
    return Buf;
} /* End of 'FindLCS' function */

/* END OF 'lcs.cpp' FILE */

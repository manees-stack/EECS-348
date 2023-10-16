#include <stdio.h>

void combinations(int score)
{
    int numTD, numTDFG, numTDTD, numTDthree, safety;
    for (numTD = 0; score >= (8 * numTD); numTD++)
    {
        for (numTDFG = 0; score >= (8 * numTD + 7 * numTDFG); numTDFG++)
        {
            for (numTDTD = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD); numTDTD++)
            {
                for (numTDthree = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD + 3 * numTDthree); numTDthree++)
                {
                    for (safety = 0; score >= (8 * numTD + 7 * numTDFG + 6 * numTDTD + 3 * numTDthree + 2 * safety); safety++)
                    {
                        if (score == (8 * numTD + 7 * numTDFG + 6 * numTDTD + 3 * numTDthree + 2 * safety))
                        {
                            printf("%d TD +2pt, %d TD + FG,%d TD + %d 3pt FG , %d Safety\n", numTD, numTDFG, numTDTD, numTDthree, safety);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int score;

    while (1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("NFL score: ");
        scanf("%d", &score);

        if (score <= 1)
        {
            printf("Program ended.\n");
            break;
        }
        else
        {
            printf("Possible combinations of scoring plays:\n");
            combinations(score);
        }
    }

    return 0;
}
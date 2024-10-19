#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

double error = 192837465.192873645;

double readDouble(int positeve)
{

    char input[30];
    int dotFlag = 0;
    fgets(input, 30, stdin);
    fflush(stdin);
    for (int i = 0; i <= strlen(input); i++)
    {
        if (input[i] == '.')
        {
            dotFlag++;
        }
        if (positeve == 1)
        {
            if (input[i] == '-')
            {
                printf("Некоректные данные\n");
                return error;
            }
        }
        if (isalpha(input[i]) || (input[i] == '-' && i != 0) || dotFlag > 1)
        {
            printf("Некоректные данные\n");
            return error;
        }
    }

    return atof(input);
}

double Inputer(int positeve)
{
    double answer = error;

    while (answer == error)
    {
        printf("Введите число: ");
        answer = readDouble(positeve);
    }
    return answer;
}

double Integral(double E, double a, double b)
{

    int N = 1;
    double h, x, Sumi, Sum, prevSum;
    prevSum = 0;
    while (1)
    {
        Sum = 0;
        N = N * 2;
        h = (b - a) / N;
        x = a;
        for (int i = 0; i < N; i++)
        {
            x += h;
            Sumi = h * (log(x) + log(x - h)) / 2;
            Sum += Sumi;
        }
        if (fabs(prevSum - Sum) <= E)
        {
            return Sum;
            break;
        }
        prevSum = Sum;
    }
}

double InfiniteRow(double E)
{

    float n = 1;
    double prevIteration, currentIteration, summary, prevSummary;
    prevIteration = 1;
    currentIteration = 0;
    summary = 0;
    prevSummary = prevIteration;
    while (1)
    {
        n++;
        currentIteration = 1 / n;
        summary = prevSummary + currentIteration;
        if ((summary - prevSummary) <= E)
        {
            return summary;
            break;
        }
        prevSummary = summary;
        prevIteration = currentIteration;
    }
    return 0;
}

int main()
{
    double E, a, b, Itgral, Infrow;
    printf("*** Нахождение интеграла ***\n");
    printf("Введите погрешность\n");
    E = Inputer(1);
    printf("Введите a\n");
    a = Inputer(0);
    printf("Введите b\n");
    b = Inputer(0);
    Itgral = Integral(E, a, b);
    printf(">>> %f\n", Itgral);
    printf("*** Нахождение суммы бесконечного ряда ***\n");
    printf("Введите погрешность\n");
    E = Inputer(1);
    Infrow = InfiniteRow(E);
    printf(">>> %f\n", Infrow);
    return 0;
}
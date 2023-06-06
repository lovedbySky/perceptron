#include <iostream>

#define data_size 3
double w[data_size];


double neural_result(double res)
{
    return (res <= 0) ? 0 : 1;
}


double neural_calculate(double inputs[data_size])
{
    double result = 0;
    for (int i = 0; i < data_size; i++)
        result += w[i] * inputs[i];
    return result;
}


void neural_education(int data[4][data_size], int exp[4])
{
    const double LR = 0.1, EPOCH = 150;    
    double error;
    for (int i = 0; i < EPOCH; i++)
    {
        system("clear");
        std::cout << "Обучение: " << i + 1 << "/" << EPOCH << " Эпох";
        std::cout << " | " << (int) ((i + 1) * 100 / EPOCH) << "%" << std::endl;
        for (int j = 0; j < 4; j++)
        {
            error = exp[j] - neural_result(neural_calculate((double*) data[j]));
            for (int n = 0; n < data_size; n++)
                w[n] += LR * error * data[j][n];
        }
    }    
}


int main()
{
    int data[4][3] { {1,1,1}, {0,1,1}, {0,1,0}, {1,1,0} }; // Данные для обучения
    int exp[4] {1, 1, 0, 0}; // Правильные ответы для обучения

    for (int i = 0; i < data_size; i++) { w[i] = 0.1; }

    neural_education(data, exp);
    for (int i = 0; i < data_size; i++)
    {
        w[i] = (w[i] < 0) ? 0 : w[i];
    }

    std::cout << "Нейросеть обучена" << std::endl;

    double inputs[3];

    for (;;) 
    {
        for (int i = 0; i < 3; i++) std::cin >> inputs[i];
        std::cout << "result = " << neural_result(neural_calculate(inputs)) << std::endl;
    }
    return 0;
}

#include <iostream>
#define DEBUG_MODE


//void processors(double* data, int size);

void oper1(double* data, int size){
    for (int i = 0; i < size; i++)
    {
        data[i] = data[i] - (data[i] / 100) * 20;
    }
}

void oper2(double* data, int size) {
    for (int i = 0; i < size; i++)
    {
        data[i] = data[i] + (data[i] / 100) * 20;
    }
}

void oper3(double* data, int size) {
    int max;
    std::cout << "Введите максимальное время задачи\n";
    std::cin >> max;
    for (int i = 0; i < size; i++)
    {
        if (data[i] > max) data[i] = max;
    }
}

void oper4(double* data, int size) {
    int max;
    std::cout << "Введите максимальное время задачи\n";
    std::cin >> max;
    for (int i = 0; i < size; i++)
    {
        if (data[i] > max) data[i] = 0;
    }
}

void copy(double* ish, double* data) {
    for (int i = 0; i < 8; i++) {
        ish[i] = data[i];
    }
}
void print(double* data) {
    std::cout << "////////////////" << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << i + 1 << ": " << data[i] << std::endl;
    }
    std::cout << "////////////////" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double data[8];
    double ish[8];
    srand(time(NULL));

    void(*processors[])(double*, int) = {
        oper1,
        oper2,
        oper3,
        oper4
    };

    int ans=0;

    while (ans != 5) 
    {
        std::cout << "1. Ввести данные" << std::endl;
        std::cout << "2. Показать данные" << std::endl;
        std::cout << "3. Выбрать и выполнить обработку" << std::endl;
        std::cout << "4. Восстановить исходные данные" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cin >> ans;
        switch (ans) 
        {
            case 1:
            {
                for (int i = 0; i < 8; i++) {
                    data[i] = rand() % 10000;
                }
                copy(ish, data);
#ifdef DEBUG_MODE
                print(data);
#endif
                break;
            }

            case 2:
            {
                print(data);
                break;
            }
            case 3:
            {
                int ans2 = 0;
                std::cout << "////////////////" << std::endl;
                while (ans2 != 5)
                {
                    std::cout << "1. Уменьшить время выполнения на 20%" << std::endl;
                    std::cout << "2. Увеличить время выполнения на 20%" << std::endl;
                    std::cout << "3. Ограничить максимальное время задачи" << std::endl;
                    std::cout << "4. Слишком долгие задачи заменить значением 0" << std::endl;
                    std::cout << "5. Выход" << std::endl;
                    std::cin >> ans2;

                    if(ans2!=5)
                        processors[ans2 - 1](data, 8);

#ifdef DEBUG_MODE
                    print(data);
#endif
                   
                    
                }
                break;
            }
            case 4:
            {
                copy(data, ish);
#ifdef DEBUG_MODE
                std::cout << "Массив после восстановления:\n";
                print(data);
#endif
                break;
            }
            case 5:
            { break; }
        }
    }
}




#include <iostream>
#include <vector>
#include <algorithm>

struct Citizen {
    char name[20];
    int age;
    union {
        int childrensCount;
    } adult;
    union {
        struct {
            char fatherName[20];
            char motherName[20];
        } parents;
    } teenage;

    Citizen(int a, const char* n, int childerns) {
        age = a;
        strncpy_s(name, n, sizeof(name));
        adult.childrensCount = childerns;
    }
    Citizen(int a, const char* n, const char* mName, const char* fName) {
        age = a;
        strncpy_s(name, n, sizeof(name));
        strncpy_s(teenage.parents.fatherName, fName, sizeof(teenage.parents.fatherName));
        strncpy_s(teenage.parents.motherName, mName, sizeof(teenage.parents.motherName));
    }
    Citizen() {};
};

bool CompareByChildernsCount(const Citizen& first, const Citizen& second) {
    return first.adult.childrensCount > second.adult.childrensCount;
}


int main() {
    setlocale(LC_ALL, "ru");
    Citizen citizens[] = {
        Citizen(25,"Валерий",5),
        Citizen(59,"Анна",2),
        Citizen(43,"Евгения",8),
        Citizen(13,"Никита","Анджелла","Ибрагим"),
        Citizen(16,"Екатерина","Людмила","Авраам"),
        Citizen(52,"Игорь",4),
        Citizen(35,"Валерия",9),
        Citizen(12,"Ника","Юлия","Лев"),        
        Citizen(9,"Михаил","Ульяна","Людвик"),
        Citizen(3,"Елизавета","Алина","Иван")
    };

    Citizen adultCitizens[15];
    int adultsCount=0;
    for (const auto& citizen:citizens) {
        if (citizen.age >= 18) {
            adultCitizens[adultsCount++] = citizen;
        }
    }
    std::sort(adultCitizens, adultCitizens + adultsCount, CompareByChildernsCount);
    for (int i = 0; i < adultsCount; i++)
        std::cout << "Имя: " << adultCitizens[i].name << ", возраст: " << adultCitizens[i].age << ", количество детей: " << adultCitizens[i].adult.childrensCount<<"\n";

    return 0;
}

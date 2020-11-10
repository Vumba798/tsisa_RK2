#include <func.hpp>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>

using std::endl;
using std::cout;
using std::cin;
using std::setw;

Person::Person(const double& val1, const double &val2) {
    x = val1;
    y = val2;
    value = func(x, y);
    bool operator>(const Person& left, const Person& right);
}

bool operator>(const Person& left, const Person& right) {
    return left.value > right.value;
}

void insert(std::vector<Person> &vec, Person &&p) {
    if (vec.empty()) {
        vec.emplace_back(p);
        return;
    }
    auto iter = vec.begin();
    while (iter != vec.end()) {
        if (p > *iter) {
            vec.emplace(iter, p);
            break;
        }
        ++iter;
    }
    if (iter == vec.end()) {
        vec.emplace_back(p);
    }
}

double func(const double &x, const double &y) {
    return 1 / (1 + x*x + y*y);
}

double calculate_avg(const std::vector<Person>& vec) {
    double sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec[i].value;
    }
    return sum / vec.size();
}

// Tournament selection
std::vector<Person> crossing_over(const std::vector<Person> &vec) {
    std::vector<Person> crossOver;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            // Sorted insert
            insert(crossOver, Person(vec[i].x, vec[j].x));
            insert(crossOver, Person(vec[i].x, vec[j].y));
            insert(crossOver, Person(vec[i].y, vec[j].x));
            insert(crossOver, Person(vec[i].y, vec[j].y));
        }
    }
    return crossOver;
    //cout << "CROSS OVER" << endl;
    //print(1,crossOver); return crossOver;
}

void mutation(std::vector<Person> &crossOver) {
    for (size_t i = 0; i < crossOver.size(); ++i) {
        // Percent of mutation is 40%
        if (std::rand() % 10000 > 4000) {

            if (std::rand() % 10000 > 5000) {
                //crossOver[i].x = fmod(crossOver[i].x, 4) - 2;
                crossOver[i].x = static_cast<double>(rand())/
                                 static_cast<double>(RAND_MAX / 4) - 2;
            }else{
                //crossOver[i].y = fmod(crossOver[i].y, 4) - 2;
                crossOver[i].y = static_cast<double>(rand())/
                        static_cast<double>(RAND_MAX / 4) - 2;
            }
            crossOver[i].value = func(crossOver[i].x, crossOver[i].y);
        }
    }
    std::sort(crossOver.begin(), crossOver.end(), [](Person& left, Person& right){
        return left.value > right.value;
    });
    //cout << "MUTATION" << endl;
    //print(1, crossOver);
}

void print(const size_t& N, const std::vector<Person> &population) {
    cout << "Iteration " << N << endl;
    for (size_t i = 0; i < population.size(); ++i) {
        cout << endl;
        cout << setw(5) << i+1 << setw(18) << population[i].x <<
            setw(18) << population[i].y << setw(18) << population[i].value;
    }
    cout << "\n\tMAX: " << population[0].value <<
        "\t\tAVG: " << calculate_avg(population) << endl;
    cout << endl << "=====================================" << endl;
}

void genetic_algorithm(size_t N) {
    size_t iteration = 0;
    std::vector<Person> population;
    for (size_t i = 0; i < 4; ++i) {
        insert(population, Person(static_cast<double>(std::rand())/
                                  static_cast<double>(RAND_MAX/4) - 2,
                                  static_cast<double>(std::rand())/
                                  static_cast<double>(RAND_MAX/4) - 2));
    }
    while (iteration < N) {
       print(iteration, population);
       auto crossOver = crossing_over(population);
       mutation(crossOver);
       for (size_t i = 0; i < 4; ++i) {
           population[i] = crossOver[i];
       }
       ++iteration;
    }
    print(N, population);
}
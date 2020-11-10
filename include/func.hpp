#include <vector>
struct Person {
    double x;
    double y;
    double value;

    Person(const double& val1, const double &val2);
};
void insert(std::vector<Person>& vec, Person&& p);
double func(const double &x, const double &y);
double calculate_avg(const std::vector<Person>& vec);

// Tournament selection
std::vector<Person> crossing_over(const std::vector<Person> &vec);
void mutation(std::vector<Person> &crossOver);

/*
void choose_best_persons(std::vector<Person> &population,
    std::vector<Person> &newPopulation) {
    for (size_t i = 0; i < 4; ++i) {
        population[i] = newPopulation[i];
    }
}
 */

void print(const size_t &N, const std::vector<Person> &population);

void genetic_algorithm(size_t N);
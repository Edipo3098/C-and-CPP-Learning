#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
    int student_count = 0;
    int grade_count = 0;
    std::cout << "Number of students: ";
    if (!(std::cin >> student_count) || student_count <= 0) {
        std::cerr << "Student count must be positive.\n";
        return 1;
    }
    std::cout << "Number of grades per student: ";
    if (!(std::cin >> grade_count) || grade_count <= 0) {
        std::cerr << "Grade count must be positive.\n";
        return 1;
    }
    for (int i = 0; i < student_count; ++i) {
        std::string name;
        std::cout << "Student name: ";
        if (!(std::cin >> name)) return 1;
        std::vector<double> grades;
        for (int j = 0; j < grade_count; ++j) {
            double grade = 0.0;
            std::cout << "Grade: ";
            if (!(std::cin >> grade)) {
                std::cerr << "Expected a numeric grade.\n";
                return 1;
            }
            grades.push_back(grade);
        }
        std::sort(grades.begin(), grades.end());
        const double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
        const std::size_t middle = grades.size() / 2;
        const double median = grades.size() % 2 == 0
            ? (grades[middle - 1] + grades[middle]) / 2.0 : grades[middle];
        std::cout << name << "\nSum: " << sum
                  << "\nMean: " << sum / grades.size()
                  << "\nMedian: " << median << '\n';
    }
    return 0;
}

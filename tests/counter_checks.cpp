#include <iostream>
#include <limits>

// Reuse the class from the exercise without running its demonstration main.
#define main practice_main
#ifdef TEST_LESSON_12
#include "../examples/lesson-12/main.cpp"
#else
#include "../examples/lesson-11/main.cpp"
#endif
#undef main

int main() {
    counter value;
    if (value.getvalue() != 0) return 1;

    const counter positive(8);
    if (positive.getvalue() != 8) return 2;

    counter negative(-1);
    counter minimum(std::numeric_limits<int>::min());
    if (negative.getvalue() != 0 || minimum.getvalue() != 0) return 3;

    if (!value.setvalue(4) || value.getvalue() != 4) return 4;
    if (value.setvalue(-1) || value.getvalue() != 4) return 5;
    if (!value.crease() || value.getvalue() != 5) return 6;
    if (!value.setvalue(0) || value.getvalue() != 0) return 7;

    counter maximum(std::numeric_limits<int>::max());
    if (maximum.crease()) return 8;
    if (maximum.getvalue() != std::numeric_limits<int>::max()) return 9;
    if (!maximum.setvalue(std::numeric_limits<int>::max() - 1)) return 10;
    if (!maximum.crease() || maximum.getvalue() != std::numeric_limits<int>::max()) return 11;

    std::cout << "counter checks passed\n";
    return 0;
}

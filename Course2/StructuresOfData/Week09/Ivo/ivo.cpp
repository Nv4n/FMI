#include <iostream>
#include <cmath>

void increment(int from, int to, bool rows, int constant) {
    for (int i = from; i < to + 1; i++) {
        if (rows) std::cout << i << ", " << constant;
        else std::cout << constant << ", " << i;
        std::cout << std::endl;
    }
}

void decrement(int from, int to, bool rows, int constant) {
    for (int i = from + 1; i > to; i--) {
        if (rows) std::cout << i << ", " << constant;
        else std::cout << constant << ", " << i;
        std::cout << std::endl;
    }
}

void moveVertically(int start_row, int target_row, int col) {
    if (start_row < target_row) { // move down
        increment(start_row, target_row, true, col);
    } else { // move up
        decrement(start_row, target_row, true, col);
    }
}

void moveHorizontally(int start_col, int target_col, int row) {
    if (start_col < target_col) { // move right
        increment(start_col, target_col, false, row);
    } else { // move left
        decrement(start_col, target_col, false, row);
    }
}

int main() {
#pragma region init_variables
    int matrix_size_rows = 0;
    int matrix_size_cols = 0;

    int start_position_rows = 0;
    int start_position_cols = 0;

    int key_row = 0;
    int key_col = 0;

    int phone_row = 0;
    int phone_col = 0;

    int jacket_row = 0;
    int jacket_col = 0;

    int steps_rows = 0;
    int step_cols = 0;
#pragma endregion

    /*
        std::cout << "enter matrix numer of rows and columns: "
                  << "\n";
        std::cin >> matrix_size_rows >> matrix_size_cols;

        int matrix[matrix_size_rows][matrix_size_cols];

        std::cout << "enter matrix values: " << "\n";
        for (int row = 0; row < matrix_size_rows; row++)
        {
            for (int col = 0; col < matrix_size_cols; col++)
            {
                std::cin >> matrix[row][col];
            }
            std::cout << "\n";
        }

        std::cout << "------------------"
                  << "\n";

        std::cout << "enter matrix start position for rows and columns: "
                  << "\n";
        std::cin >> start_position_rows >> start_position_cols;


        for (int row = 0; row < matrix_size_rows; row++)
        {
            for (int col = 0; col < matrix_size_cols; col++)
            {
                std::cout << matrix[row][col];
            }
            std::cout << "\n";
    }*/

    // for debug
    matrix_size_rows = 5;
    matrix_size_cols = 8;
    int matrix[5][8] = {{0, 1, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 2},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 3, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

    start_position_rows = 2;
    start_position_cols = 0;

    // end

    //find key(1), phone(2) and jacket(3)

    for (int row = 0, counter = 0; row < matrix_size_rows; row++) {
        for (int col = 0; col < matrix_size_cols; col++) {
            if (matrix[row][col] != 0) {
                counter++;

                if (matrix[row][col] == 1) {
                    key_row = row;
                    key_col = col;
                } else if (matrix[row][col] == 2) {
                    phone_row = row;
                    phone_col = col;
                } else if (matrix[row][col] == 3) {
                    jacket_row = row;
                    jacket_col = col;
                }
            }

            if (counter == 3) {
                break;
            }
        }
    }

    int steps_to_key = 0;
    int steps_to_phone = 0;
    int steps_to_jacket = 0;
    //go to each position

    for (int move = 0; move < 3; move++) {

        if (steps_to_key != -1)
            steps_to_key = std::abs(start_position_rows - key_row) +
                           std::abs(start_position_cols - key_col);

        if (steps_to_phone != -1)
            steps_to_phone = std::abs(start_position_rows - phone_row) +
                             std::abs(start_position_cols - phone_col);

        if (steps_to_jacket != -1)
            steps_to_jacket = std::abs(start_position_rows - jacket_row) +
                              std::abs(start_position_cols - jacket_col);


        if (steps_to_jacket != -1 && steps_to_jacket <= steps_to_key && steps_to_jacket <= steps_to_phone) {
            //  go to three
            moveVertically(start_position_rows, jacket_row, start_position_cols);
            start_position_rows = jacket_row;
            moveHorizontally(start_position_cols, jacket_col, start_position_rows);
            start_position_cols = jacket_col;
            steps_to_jacket = -1;
        } else if (steps_to_phone != -1 && steps_to_phone <= steps_to_key && steps_to_phone <= steps_to_jacket) {
            // go to two
            moveVertically(start_position_rows, phone_row, start_position_cols);
            start_position_rows = phone_row;
            moveHorizontally(start_position_cols, phone_col, start_position_rows);
            start_position_cols = phone_col;
            steps_to_phone = -1;
        } else if (steps_to_key != -1 && steps_to_key <= steps_to_phone && steps_to_key <= steps_to_jacket) {
            // go to one
            moveVertically(start_position_rows, key_row, start_position_cols);
            start_position_rows = key_row;
            moveHorizontally(start_position_cols, key_col, start_position_rows);
            start_position_cols = key_col;
            steps_to_jacket = -1;
            steps_to_key = -1;
        }
    }

    return 0;
}


/*
5 8

0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 3 0
0 0 0 0 0 0 0 0

2, 0
2, 0
2, 1
1, 1
0, 1
0, 2
0, 3
0, 4
0, 5
0, 6
0, 7
1, 7
1, 6
2, 6
*/
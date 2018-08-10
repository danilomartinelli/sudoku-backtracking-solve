#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define FIRST_BLOCK 1
#define SECOND_BLOCK 2
#define THIRD_BLOCK 3
#define FOURTH_BLOCK 4
#define FIFTH_BLOCK 5
#define SIXTH_BLOCK 6
#define SEVENTH_BLOCK 7
#define EIGHTH_BLOCK 8
#define NINTH_BLOCK 9

void fillSudokuMatrix(int sudokuMatrix[][9]);
void printSudokuMatrix(int sudokuMatrix[][9]);
int checkValidNumberInRow(int row, int column, int sudokuMatrix[][9]);
int checkValidNumberInColumn(int row, int column, int sudokuMatrix[][9]);
int checkValidNumberInBlock(int row, int column, int sudokuMatrix[][9]);
int checkIsValidInput(int row, int column, int sudokuMatrix[][9]);
int checkBlock(int row, int column);
int isInitialValue(int row, int column);
void solveSudoku(int sudokuMatrix[][9]);

int main() {
  int sudokuMatrix[9][9];

  fillSudokuMatrix(sudokuMatrix);
  solveSudoku(sudokuMatrix);

  return 0;
}

int checkValidNumberInRow(int row, int column, int sudokuMatrix[][9]) {
  int aux;
  int number = sudokuMatrix[row][column];

  if (column != 8) {
    for (aux = column + 1; aux < 9; aux++) {
      if (number == sudokuMatrix[row][aux]) {
        return FALSE;
      }
    }
  }
  if (column != 0){
    for (aux = column - 1; aux >= 0; aux--) {
      if (number == sudokuMatrix[row][aux]) {
        return FALSE;
      }
    }
  }

  return TRUE;
}

int checkValidNumberInColumn(int row, int column, int sudokuMatrix[][9]) {
  int aux;
  int number = sudokuMatrix[row][column];

  if (row != 8) {
    for (aux = row + 1; aux < 9; aux++) {
      if (number == sudokuMatrix[aux][column]) {
        return FALSE;
      }
    }
  }
  if (row != 0){
    for (aux = row - 1; aux >= 0; aux--) {
      if (number == sudokuMatrix[aux][column]) {
        return FALSE;
      }
    }
  }

  return TRUE;
}

int checkValidNumberInBlock(int row, int column, int sudokuMatrix[][9]) {
  int block = checkBlock(row, column);
  int number = sudokuMatrix[row][column];
  int auxRow, auxColumn, initRow, initColumn, finalRow, finalColumn;

  switch (block) {
    case FIRST_BLOCK:
      initRow = 0;
      initColumn = 0;
      finalRow = 3;
      finalColumn = 3;
      break;
    case SECOND_BLOCK:
      initRow = 0;
      initColumn = 3;
      finalRow = 3;
      finalColumn = 6;
      break;
    case THIRD_BLOCK:
      initRow = 0;
      initColumn = 6;
      finalRow = 3;
      finalColumn = 9;
      break;
    case FOURTH_BLOCK:
      initRow = 3;
      initColumn = 0;
      finalRow = 6;
      finalColumn = 3;
      break;
    case FIFTH_BLOCK:
      initRow = 3;
      initColumn = 3;
      finalRow = 6;
      finalColumn = 6;
      break;
    case SIXTH_BLOCK:
      initRow = 3;
      initColumn = 6;
      finalRow = 6;
      finalColumn = 9;
      break;
    case SEVENTH_BLOCK:
      initRow = 6;
      initColumn = 0;
      finalRow = 9;
      finalColumn = 3;
      break;
    case EIGHTH_BLOCK:
      initRow = 6;
      initColumn = 3;
      finalRow = 9;
      finalColumn = 6;
      break;
    case NINTH_BLOCK:
      initRow = 6;
      initColumn = 6;
      finalRow = 9;
      finalColumn = 9;
      break;
  }

  for (auxRow = initRow; auxRow < finalRow; auxRow++) {
    for (auxColumn = initColumn; auxColumn < finalColumn; auxColumn++) {
      if (row == auxRow && column == auxColumn) continue;
      if (number == sudokuMatrix[auxRow][auxColumn]) return FALSE;
    }
  }

  return TRUE;
}

int checkIsValidInput(int row, int column, int sudokuMatrix[][9]) {
  if (
    checkValidNumberInRow(row, column, sudokuMatrix) == TRUE &&
    checkValidNumberInColumn(row, column, sudokuMatrix) == TRUE &&
    checkValidNumberInBlock(row, column, sudokuMatrix) == TRUE
  ) {
    return TRUE;
  } else {
    return FALSE;
  }
}

int checkBlock(int row, int column) {
  if (row <= 2 && column <= 2) {
    return FIRST_BLOCK;
  } else if (row <= 2 && column <= 5) {
    return SECOND_BLOCK;
  } else if (row <= 2 && column <= 8) {
    return THIRD_BLOCK;
  } else if (row <= 5 && column <= 2) {
    return FOURTH_BLOCK;
  } else if (row <= 5 && column <= 5) {
    return FIFTH_BLOCK;
  } else if (row <= 5 && column <= 8) {
    return SIXTH_BLOCK;
  } else if (row <= 8 && column <= 2) {
    return SEVENTH_BLOCK;
  } else if (row <= 8 && column <= 5) {
    return EIGHTH_BLOCK;
  } else if (row <= 8 && column <= 8) {
    return NINTH_BLOCK;
  }
}

void fillSudokuMatrix(int sudokuMatrix[][9]) {
  int row, column;

  for (row = 0; row < 9; row++) {
    for (column = 0; column < 9; column++) {
      sudokuMatrix[row][column] = 0;
    } 
  }

  sudokuMatrix[1][5] = 3;
  sudokuMatrix[1][7] = 8;
  sudokuMatrix[1][8] = 5;
  sudokuMatrix[2][2] = 1;
  sudokuMatrix[2][4] = 2;
  sudokuMatrix[3][3] = 5;
  sudokuMatrix[3][5] = 7;
  sudokuMatrix[4][2] = 4;
  sudokuMatrix[4][6] = 1;
  sudokuMatrix[5][1] = 9;
  sudokuMatrix[6][0] = 5;
  sudokuMatrix[6][7] = 7;
  sudokuMatrix[6][8] = 3;
  sudokuMatrix[7][2] = 2;
  sudokuMatrix[7][4] = 1;
  sudokuMatrix[8][4] = 4;
  sudokuMatrix[8][8] = 9;
}

int isInitialValue(int row, int column) {
  if (
    (row == 1 && column == 5) ||
    (row == 1 && column == 7) ||
    (row == 1 && column == 8) ||
    (row == 2 && column == 2) ||
    (row == 2 && column == 4) ||
    (row == 3 && column == 3) ||
    (row == 3 && column == 5) ||
    (row == 4 && column == 2) ||
    (row == 4 && column == 6) ||
    (row == 5 && column == 1) ||
    (row == 6 && column == 0) ||
    (row == 6 && column == 7) ||
    (row == 6 && column == 8) ||
    (row == 7 && column == 2) ||
    (row == 7 && column == 4) ||
    (row == 8 && column == 4) ||
    (row == 8 && column == 8)
  ) {
    return TRUE;
  } else {
    return FALSE;
  }
}

void printSudokuMatrix(int sudokuMatrix[][9]) {
  int row, column;

  for (row = 0; row < 9; row++) {
    for (column = 0; column < 9; column++) {
      printf("%d ", sudokuMatrix[row][column]);
      if (column == 2 || column == 5) {
        printf("| ");
      }
    }
    printf("\n");
    if (row == 2 || row == 5) {
      printf("---------------------\n"); 
    }
  }
}

void solveSudoku(int sudokuMatrix[][9]) {
  int row, column, auxNumber, isReturnLoop = FALSE;

  for (row = 0; row < 9;) {
    for (column = 0; column < 9;) {
      if (isInitialValue(row, column) == FALSE) {
        auxNumber = sudokuMatrix[row][column];
        do {
          auxNumber++;
          if (auxNumber > 9) {
            sudokuMatrix[row][column] = 0;
            do {
              if (column == 0) {
              column = 8;
              row--;
              } else {
                column--;
              }
            } while(isInitialValue(row, column) == TRUE);
            isReturnLoop = TRUE;
            break;
          };
          sudokuMatrix[row][column] = auxNumber;
        } while (checkIsValidInput(row, column, sudokuMatrix) == FALSE);
      } else {
        isReturnLoop = FALSE;
        column++;
        continue;
      }
      system("clear");
      printSudokuMatrix(sudokuMatrix);
      // getchar();
      if (isReturnLoop == FALSE) {
        column++;
      } else {
        isReturnLoop = FALSE;
      }
    }
    if (isReturnLoop == FALSE) {
      row++;
    } else {
      isReturnLoop = FALSE;
    }
  }
}

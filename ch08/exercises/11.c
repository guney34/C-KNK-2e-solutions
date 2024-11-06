char checker_board[8][8];

for (int col = 0; col < 8; ++col) {
    for (int row = 0; row < 8; ++row) {
        if ((col + row) % 2 == 0)
            checker_board[col][row] = 'B';
        else
            checker_board[col][row] = 'R';
    }
}
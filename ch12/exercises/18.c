int evaluate_position(char board[8][8])
{
    int score = 0;
    for (char *p = &board[0][0]; p <= &board[7][7]; ++p)
    {
        switch (*p) {
            case 'Q':
                score += 9; break;
            case 'q':
                score -= 9; break;
            case 'R':
                score += 5; break;
            case 'r':
                score -= 5; break;
            case 'B': case 'N':
                score += 3; break;
            case 'b': case 'n':
                score -= 3; break;
            case 'P':
                ++score; break;
            case 'p':
                --score; break;
        }
    }
    return score; 
}
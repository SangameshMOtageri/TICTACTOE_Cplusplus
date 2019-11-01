struct turn_pos{
    unsigned int r, c;
};

extern char boards[3][3];

int evaluateWinner(char board[3][3], unsigned int player);

bool boardIsFull(char board[3][3]);

struct turn_pos optimalMove(char board[3][3], unsigned int  player);

int players_turn();

int computers_turn();

void printBoard();

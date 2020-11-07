
int board[8];
void print_board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i] == j)
                cout << "Q";
            else cout << "#";
        }
        cout << endl;
    }
 

}
bool valid(int r,int c)
{
    /*check the vertical ,two diagonal on the rows above the row we checking for
      *e.g first row will not enter this loop will directly return true for the first time 
     because no row above it */
    for (int i = 0; i < r; i++)
    {
        //if (board[i]==c ||(c-r)==(c-board[i])||(r+i)==(c+board[i]))
        if (board[i] == c
            || (c - r) == (board[i] - i)
            || (r + c) == (i + board[i]))
            return false;
    }
    return true;

}
int ans = -1;
int zky[8][8];
void queen(int r)
{
    if (r == 8)
    {
        int maxx=0;
        for (int i = 0; i < 8; i++)
        {    
            maxx += zky[i][board[i]];
        }
        ans = max(ans, maxx);
       
    }   
    else
    {
        for (int col = 0; col < 8; col++)
        {
            if (valid(r, col))
            {
                //r represent row and the loop here represent each colume in that row 
                board[r]=col;
                //go to the next row
                queen(r + 1);
            }
        }
    }

}
int main()
{
 
   
    int tc;
    cin >> tc;
    while (tc--) {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> zky[i][j];
        queen(0);
        cout << ans << endl;
        ans = -1;
    };

    return 0;
}

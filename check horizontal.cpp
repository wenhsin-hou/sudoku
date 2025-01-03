#include <iostream>
#include <windows.h>

using namespace std;

int board[4][4] = {
    {0, 0, 1, 0},
    {0, 4, 0, 0},
    {0, 0, 2, 0},
    {0, 1, 0, 0},
};

bool editable[4][4];

int cur_r = 0, cur_c = 0;
int i,j; 


int check_horizontal(int i)
{
	
        bool has_duplicate = false;
        bool is_complete = true;
        bool seen[5] = {false}; // 用於記錄數字 1~4 是否出現過

        for (int j = 0; j < 4; ++j) 
        {
            int num = board[i][j];

            if (num == 0)
            {
                is_complete = false; // 如果有空格，橫列不算完成
            }
            else if (seen[num] && num!=0)
            {
                has_duplicate = true; // 如果數字已經出現過，標記為有重複
            }
            else
            {
                seen[num] = true; // 記錄該數字為已出現
            }
        }
		for (int j = 0; j < 4; ++j)
        {
            if (has_duplicate)
            {
                return 1;
				 // 標記該橫列為紅色（有重複數字）
            }
            else if (is_complete)
            {
                return 2;
				 // 標記該橫列為綠色（完成且無重複）
            }
            else return 0;
            
        }
        
    
    /* TODO: Check if a horizontal line has conflict number, or is finished. */
}

int  check_vertical(int j)
{
	
        bool has_duplicate = false;
        bool is_complete = true;
        bool seen[5] = {false}; 

        for (int i = 0; i < 4; ++i) // 遍歷橫列中的每個格子
        {
            int num = board[i][j];

            if (num == 0)
            {
                is_complete = false; // 如果有空格，橫列不算完成
            }
            else if (seen[num] && num!=0)
            {
                has_duplicate = true; // 如果數字已經出現過，標記為有重複
            }
            else
            {
                seen[num] = true; // 記錄該數字為已出現
            }
        }

        
        for (int i = 0; i < 4; ++i)
        {
            if (has_duplicate)
            {
                return 1;
				 // 標記該橫列為紅色（有重複數字）
            }
            else if (is_complete)
            {
                return 2;
				 // 標記該橫列為綠色（完成且無重複）
            }
            else return 0;
            
        }
    /* TODO: Check if a vertical line has conflict number, or is finished. */

}

void check_block()
{
    /* TODO: Check if a block has conflict number, or is finished. */
}

bool is_invalid(int i, int j)
{	
	
	if(check_horizontal(i) ==1 ||check_vertical(j) ==1) return true;
	else return false;
	
    /* TODO: Check if board[i][j] is in a line that has conflict numbers. */
    
}

bool is_done(int i, int j)
{	
	if(check_horizontal(i) ==2 ||check_vertical(j) ==2) return true;
	else return false;
    /* TODO: Check if board[i][j] is in a line that has finished. */
    
}

void fill_number(int c)
{
	board[cur_r][cur_c]=c-48;
	//check_horizontal();
    //check_vertical();
    //check_block();
	return ;
    /* TODO: Fill a number in to the cell the cursor is now pointing to.
             After fill in the number, check the horizontal line, the
             vertical line and the block the cell is in.
     */
}

void move_cursor(char c)
{	
	if(c == 'W' || c == 'w' ) {
		cur_r--;
		if(cur_r>=4 || cur_r<0) cur_r++;
		if(cur_r==0 && cur_c==2 ||cur_r==1&&cur_c==1||cur_r==2&&cur_c==2||cur_r==3&&cur_c==1)cur_r--;
	}
    if( c == 'S' || c == 's' ) {
		cur_r++;
		if(cur_r>=4 || cur_r<0) cur_r--;
		if(cur_r==0 && cur_c==2 ||cur_r==1&&cur_c==1||cur_r==2&&cur_c==2||cur_r==3&&cur_c==1)cur_r++;
	}
    if( c == 'A' || c == 'a' ) {
		cur_c--;
		if(cur_r>=4 || cur_r<0) cur_c++;
		if(cur_r==0 && cur_c==2 ||cur_r==1&&cur_c==1||cur_r==2&&cur_c==2||cur_r==3&&cur_c==1)cur_c--;
	}
    if( c == 'D' || c == 'd') {
		cur_c++;
		if(cur_r>=4 || cur_r<0) cur_c--;
		if(cur_r==0 && cur_c==2 ||cur_r==1&&cur_c==1||cur_r==2&&cur_c==2||cur_r==3&&cur_c==1)cur_c++;
	}
}
    /* TODO: Move the cursor up, down, to the left or to the right.
             Remember to check if the cursor is moving out of bound.
    */



bool check_win()
{
    /* TODO: Check if the game is set. That is, every cell is finished. */
    return false;
}

bool is_moving_action(char c)
{
    return (c == 'W' || c == 'w' || c == 'S' || c == 's' ||
            c == 'A' || c == 'a' || c == 'D' || c == 'd');
}

bool is_filling_action(char c)
{
    return (c >= '0' && c <= '4');
}

string get_styled_text(string text, string style)
{
    string color = "", font = "";
    for (char c : style)
    {
        if (c == 'R')
            color = "31";
        if (c == 'G')
            color = "32";
        if (c == 'E')
            color = "41";
        if (c == 'C')
            color = "106";
        if (c == 'B')
            font = ";1";
    }
    return "\x1b[" + color + font + "m" + text + "\x1b[0m";
}

void print_board()
{
    // Flush the screen
    cout << "\x1b[2J\x1b[1;1H";

    // Print usage hint.
    cout << get_styled_text("W/A/S/D: ", "B") << "move cursor" << endl;
    cout << get_styled_text("    1-4: ", "B") << "fill in number" << endl;
    cout << get_styled_text("      0: ", "B") << "clear the cell" << endl;
    cout << get_styled_text("      Q: ", "B") << "quit" << endl;
    cout << endl;

    // Iterate through and print each cell.
    for (int i = 0; i < 4; ++i)
    {
        // Print horizontal divider.
        if (i && i % 2 == 0)
            cout << "---------------" << endl;

        // Print the first vertical divider in each line.
        cout << "|";
        for (int j = 0; j < 4; ++j)
        {
            // Set text style based on the state of the cell.
            string style = "";
            
			
			
            // Set style for the cell the cursor pointing to.
            if (cur_r == i && cur_c == j)
                style = "C";
            // Set style for the cell in an invalid line.
            else if (is_invalid(i, j))
                style = "E";
            // Set style for the cell in a finished line.
            else if (is_done(i, j))
                style = "G";

            // Set style for a the cell that is immutable.
            if (!editable[i][j])
                style += "B";
			
			
            // Print the cell out in styled text.
            // If the content is 0, print a dot, else print the number.
            if (board[i][j] == 0)
                cout << get_styled_text(" · ", style);
            else
                cout << get_styled_text(" " + to_string(board[i][j]) + " ", style);

            // Print the vertical divider for each block.
            if ((j + 1) % 2 == 0)
                cout << "|";
        }
        cout << endl;
    }
}

void initialize()
{
    // Set up styled text for Windows.
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    // Mark editable cells
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            editable[i][j] = !board[i][j];

    // Print the initial board out.
    print_board();
}

int main()
{
    char c;
    bool action_ok;

    initialize();
    while (cin >> c)
    {
        action_ok = false;
        if (is_moving_action(c))
        {
            action_ok = true;
            move_cursor(c);
        }

        if (is_filling_action(c))
        {
            action_ok = true;
            fill_number(c);
        }

        if (c == 'Q' || c == 'q')
            break;

        print_board();

        if (check_win())
        {
            cout << "YOU WIN!" << endl;
            break;
        }

        if (!action_ok)
            cout << get_styled_text("!!! Invalid action !!!", "R");
    }

    return 0;
}



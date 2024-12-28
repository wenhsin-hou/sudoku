#include<iostream>
using namespace std;

int main(){
	int board[4][4] = {
    {0, 0, 1, 0},
    {0, 4, 0, 0},
    {0, 0, 2, 0},
    {0, 1, 0, 0},
};
	
	
	
	//check horizontal
	bool ch=0;
	for(int k=0;k<4;k++){
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			if(board[0][i]==board[0][j] &&board[0][i]!=0 ) ch=1;
			//cout << get_styled_text(" " + to_string(board[i][j]) + " ", style=);
		}
	}
}
	
	cout<<ch;
	
	return 0;
} 

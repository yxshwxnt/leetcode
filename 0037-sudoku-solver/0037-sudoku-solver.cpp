class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); 
    }
    
    //created this kyuki return type bool chahiye tha
    bool solve(vector<vector<char>>& board){    //board toh pass by value kiya hai
        for(int i=0;i<board.size();i++){ 
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){           //agar board khali hai toh age bado
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c; 
                            if(solve(board)==true){   //agar condn satisty hoarai toh return true,
                                return true; 
                            }
                            else{
                                board[i][j]='.'; //agar condition false hoagai toh reset value(c)
                            }
                        }
                    } 
                    return false;    //iska dhyan dena konse bracket pe false dena hai 
                }
            }
        } 
        return true; 
    }
    
    bool isValid(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c){       //agar row me char already exist karte hai toh
                return false; 
            }  
            if(board[row][i]==c){     //agar col me char already exist karte hai toh
                return false; 
            }
            //VERY IMP STEP, see strivers vid
            //agar matrix me char already exist karte hai toh 
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){   
                return false; 
            }
        }
        return true; 
    }
};
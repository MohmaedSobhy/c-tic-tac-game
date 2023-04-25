#include <iostream>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

int main()
{
    bool turn = true;int i,choice;

    char mark;
    do
    {
        board();
        cout << "Player " << ((turn)?1:2) << " Enter a Number:  ";
        cin >> choice;
        mark= (turn) ? 'X' : 'O';
        if(square[choice]!='X' or square[choice]!='O')
            square[choice] = mark;
        else{
            cout<<"Invalid move ";
            cin.ignore();
            cin.get();
            continue;
        }
        i=checkwin();
        turn=not turn;
    }while(i==-1);
    board();
    if(i==1)
        cout << "==>Player " << ((not turn)?1:2) << " win ";
    else
        cout<<"==>Game draw";

    return 0;
}

int checkwin()
{
    // check rows
    int counter=1;
    for(int i=1;i<=8;i++){
        if(counter==3) return 1;
        if(square[i]==square[i+1]){
            counter++;
        }else
            counter=1;
    }
    if(counter==3) return 1;

    // check columns
    for(int i=1;i<=3;i++){
        if(square[i]==square[i+3] and square[i]==square[i+6]) return 1;
    }

    if (square[1] == square[5] && square[5] == square[9])
        return 1;
    if (square[3] == square[5] && square[5] == square[7])
        return 1;

    for(int i=1;i<=9;i++){
        if(square[i]!='X' or square[i]!='O') return -1;
    }

    return 0;
}


void board()
{
    //system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}

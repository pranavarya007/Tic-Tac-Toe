#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];
void draw_board(void);
int if_smart_move_possible(void);
void user_turn(void);
void comp_turn(void);
void checking_winner(void);
void smart_moves(void);
int main()
{
    int i,j,check_smart_move;
    char answer;
    for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
        matrix[i][j] = ' ';
    }
    }
    draw_board();
    printf("Are you brave enough to give computer the first chance ?(y/n) :\n ");
    scanf("%c",&answer);
    if (answer=='y') {
            comp_turn();
        for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
                while (matrix[i][j] == ' ') {

                    draw_board();
                    user_turn();
                    draw_board();
                    checking_winner();
                    check_smart_move = if_smart_move_possible();
                    if (check_smart_move == 1) {
                        smart_moves();
                    }
                    else {
                     comp_turn();
                    }
                    draw_board();
                    checking_winner();
            }
        }
    }
    }
    else {
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
                while (matrix[i][j] == ' ') {
                      user_turn();
                       draw_board();
                     checking_winner();
                    check_smart_move = if_smart_move_possible();
                    if (check_smart_move == 1) {
                               smart_moves();
                            }
                    else {
                     comp_turn();
                    }
                     draw_board();
                    checking_winner();
                }

            }
        }
    }

    printf("Draw !!!\n");
    return 0;
}

void draw_board(void) {
printf("         |    |   \n");
printf("      %c  | %c  | %c\n",matrix[0][0],matrix[0][1],matrix[0][2]);
printf("         |    |   \n");
printf("    ----------------\n");
printf("         |    |   \n");
printf("      %c  | %c  | %c\n",matrix[1][0],matrix[1][1],matrix[1][2]);
printf("         |    |   \n");
printf("    ----------------\n");
printf("         |    |   \n");
printf("      %c  | %c  | %c\n",matrix[2][0],matrix[2][1],matrix[2][2]);
printf("         |    |   \n");
printf("*****************************************************************************\n");
}

void user_turn(void) {
int a,b,c,d;
printf("enter the coordinates where you want to put 'X' : \n");
scanf("%d %d",&a ,&b);
c=a-1;
d=b-1;
    if (matrix[c][d]==' ') {
            matrix[c][d] = 'X'; }
    else if (  a>4 || b>4 ) {
        printf("invalid input\ntry again\n");
            user_turn();
        }
}

void comp_turn(void) {
int i,j,k,l;
printf("waiting for computer......\n");
for( i=0; i<3; i++) {
        for( j=0; j<3; j++)
    if (matrix[i][j]==' ') break;
    if (matrix[i][j]==' ') break;

}
if (i*j==9) {
    printf("draw\n");
}
else {
matrix[i][j] = '0';
}
}


void checking_winner(void)  {
int i,j;
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2] && matrix[i][1]=='X') {
            printf("You Won !!!\n");
            exit(0);
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i] && matrix[1][i]=='X') {
            printf("You Won !!!\n");
            exit(0);
        }
    }
    if (matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && matrix[1][1]=='X') {
            printf("You Won !!!\n");
            exit(0);
        }
    else if (matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[1][1]=='X') {
            printf("You Won !!!\n");
            exit(0);
        }
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2] && matrix[i][1]=='0') {
            printf("You Lose !!\n");
            exit(0);
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i] && matrix[1][i]=='0') {
            printf("You Lose !!\n");
            exit(0);
        }
    }
    if (matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2] && matrix[1][1]=='0') {
            printf("You Lose !!\n");
            exit(0);
        }
    else if (matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0] && matrix[1][1]=='0') {
            printf("You Lose !!\n");
            exit(0);
        }

}

int if_smart_move_possible(void) {
int i;
    ///for horizontal combinations (defense moves)
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][1] && matrix[i][2]==' ' && matrix[i][1]=='X') {
            return 1;
            break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][2] && matrix[i][1]==' ' && matrix[i][2]=='X') {
            return 1;
            break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][1]==matrix[i][2] && matrix[i][0]==' ' && matrix[i][1]=='X') {
            return 1;
            break;
        }
    }
    ///for vertical combinations  (defense moves)
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[1][i] && matrix[2][i]==' ' && matrix[1][i]=='X') {
            return 1;
            break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[2][i] && matrix[1][i]==' ' && matrix[2][i]=='X') {
            return 1;
            break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[1][i]==matrix[2][i] && matrix[0][i]==' ' && matrix[1][i]=='X') {
            return 1;
            break;
        }
    }
    ///for diagonal combinations (defense moves)
    if (matrix[0][0]==matrix[1][1] && matrix[2][2]==' ' && matrix[1][1]=='X') {
            return 1;
        }
    if (matrix[0][0]==matrix[2][2] && matrix[1][1]==' ' && matrix[2][2]=='X') {
            return 1;
        }
    if (matrix[1][1]==matrix[2][2] && matrix[0][0]==' ' && matrix[1][1]=='X') {
            return 1;
        }
    if (matrix[0][2]==matrix[1][1] && matrix[2][0]==' ' && matrix[1][1]=='X') {
            return 1;
        }
    if (matrix[0][2]==matrix[2][0] && matrix[1][1]==' ' && matrix[2][0]=='X') {
            return 1;
        }
    if (matrix[2][0]==matrix[1][1] && matrix[0][2]==' ' && matrix[1][1]=='X') {
            return 1;
        }

    ///attack moves start from here
    ///for horizontal combinations (attack moves)
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][1] && matrix[i][2]==' ' && matrix[i][1]=='0') {
           return 1;
           break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][2] && matrix[i][1]==' ' && matrix[i][2]=='0') {
            return 1;
            break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][1]==matrix[i][2] && matrix[i][0]==' ' && matrix[i][1]=='0') {
            return 1;
            break;
        }
    }
    ///for vertical combinations  (attack moves)
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[1][i] && matrix[2][i]==' ' && matrix[1][i]=='0') {
            return 1;
            break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[2][i] && matrix[1][i]==' ' && matrix[2][i]=='0') {
            return 1;
            break;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[1][i]==matrix[2][i] && matrix[0][i]==' ' && matrix[1][i]=='0') {
            return 1;
            break;
        }
    }
    ///for diagonal combinations (attack moves)
    if (matrix[0][0]==matrix[1][1] && matrix[2][2]==' ' && matrix[1][1]=='0') {
            return 1;
    }
    if (matrix[0][0]==matrix[2][2] && matrix[1][1]==' ' && matrix[2][2]=='0') {
            return 1;
        }
    if (matrix[1][1]==matrix[2][2] && matrix[0][0]==' ' && matrix[1][1]=='0') {
            return 1;
        }
    if (matrix[0][2]==matrix[1][1] && matrix[2][0]==' ' && matrix[1][1]=='0') {
            return 1;
    }
    if (matrix[0][2]==matrix[2][0] && matrix[1][1]==' ' && matrix[2][0]=='0') {
            return 1;
    }
    if (matrix[2][0]==matrix[1][1] && matrix[0][2]==' ' && matrix[1][1]=='0') {
            return 1;
    }
    /// other special cases
    if (matrix[1][1]==' ') {
        return 1;

    }
}

void smart_moves(void) {
int i;
    ///attack moves start from here
    ///for horizontal combinations (attack moves)
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][1] && matrix[i][2]==' ' && matrix[i][1]=='0') {
            matrix[i][2] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][2] && matrix[i][1]==' ' && matrix[i][2]=='0') {
            matrix[i][1] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][1]==matrix[i][2] && matrix[i][0]==' ' && matrix[i][1]=='0') {
            matrix[i][0] = '0';
            return;
        }
    }
    ///for vertical combinations  (attack moves)
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[1][i] && matrix[2][i]==' ' && matrix[1][i]=='0') {
            matrix[2][i] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[2][i] && matrix[1][i]==' ' && matrix[2][i]=='0') {
            matrix[1][i] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[1][i]==matrix[2][i] && matrix[0][i]==' ' && matrix[1][i]=='0') {
            matrix[0][i] = '0';
            return;
        }
    }
    ///for diagonal combinations (attack moves)
    if (matrix[0][0]==matrix[1][1] && matrix[2][2]==' ' && matrix[1][1]=='0') {
            matrix[2][2] = '0';
            return;
    }
    if (matrix[0][0]==matrix[2][2] && matrix[1][1]==' ' && matrix[2][2]=='0') {
            matrix[1][1] = '0';
            return;
    }
    if (matrix[1][1]==matrix[2][2] && matrix[0][0]==' ' && matrix[1][1]=='0') {
            matrix[0][0] = '0';
            return;
    }
    if (matrix[0][2]==matrix[1][1] && matrix[2][0]==' ' && matrix[1][1]=='0') {
            matrix[2][0] = '0';
            return;
    }
    if (matrix[0][2]==matrix[2][0] && matrix[1][1]==' ' && matrix[2][0]=='0') {
            matrix[1][1] = '0';
            return;
    }
    if (matrix[2][0]==matrix[1][1] && matrix[0][2]==' ' && matrix[1][1]=='0') {
            matrix[0][2] = '0';
            return;
    }
    ///for horizontal combinations (defense moves)
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][1] && matrix[i][2]==' ' && matrix[i][1]=='X') {
            matrix[i][2] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][0]==matrix[i][2] && matrix[i][1]==' ' && matrix[i][2]=='X') {
            matrix[i][1] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[i][1]==matrix[i][2] && matrix[i][0]==' ' && matrix[i][1]=='X') {
            matrix[i][0] = '0';
            return;
        }
    }
    ///for vertical combinations  (defense moves)
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[1][i] && matrix[2][i]==' ' && matrix[1][i]=='X') {
            matrix[2][i] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[0][i]==matrix[2][i] && matrix[1][i]==' ' && matrix[2][i]=='X') {
            matrix[1][i] = '0';
            return;
        }
    }
    for (i=0; i<3; i++) {
        if (matrix[1][i]==matrix[2][i] && matrix[0][i]==' ' && matrix[1][i]=='X') {
            matrix[0][i] = '0';
            return;
        }
    }
    ///for diagonal combinations (defense moves)
    if (matrix[0][0]==matrix[1][1] && matrix[2][2]==' ' && matrix[1][1]=='X') {
            matrix[2][2] = '0';
            return;
    }
    if (matrix[0][0]==matrix[2][2] && matrix[1][1]==' ' && matrix[2][2]=='X') {
            matrix[1][1] = '0';
            return;
    }
    if (matrix[1][1]==matrix[2][2] && matrix[0][0]==' ' && matrix[1][1]=='X') {
            matrix[0][0] = '0';
            return;
    }
    if (matrix[0][2]==matrix[1][1] && matrix[2][0]==' ' && matrix[1][1]=='X') {
            matrix[2][0] = '0';
            return;
    }
    if (matrix[0][2]==matrix[2][0] && matrix[1][1]==' ' && matrix[2][0]=='X') {
            matrix[1][1] = '0';
            return;
    }
    if (matrix[2][0]==matrix[1][1] && matrix[0][2]==' ' && matrix[1][1]=='X') {
            matrix[0][2] = '0';
            return;
    }


    /// other special moves
    if (matrix[1][1]==' ') {
        matrix[1][1] = '0';
        return;
    }
}
  //  if (matrix[][])


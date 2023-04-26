// N-Queen by Backtracking
#include<stdio.h>
#include<math.h>

int board[20],count;

int main()
{
    int n,i,j;
    void queen(int row,int n);







































































































































    

    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens:");
    scanf("%d",&n);
    queen(1,n);
    return 0;
}

//function for printing the solution
void print(int n)
{
    int i,j;
    printf("\n\nSolution %d:\n\n",++count);

    for(i=1;i<=n;++i)
        printf("\t%d",i);

    for(i=1;i<=n;++i)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j) //for n by n board
        {
            if(board[i]==j)
                printf("\tQ"); //queen at i,j position
            else
                printf("\t-"); //empty slot
        }
    }
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;++i)
    {
        //checking column and digonal conflicts
        if(board[i]==column)
            return 0;
        else
        if(abs(board[i]-column)==abs(i-row))
            return 0;
    }

    return 1; //no conflicts
}

//function to check for proper positioning of queen
void queen(int row,int n)
{
    int column;
    for(column=1;column<=n;++column)
    {
        if(place(row,column))
        {
            board[row]=column; //no conflicts so place queen
            if(row==n) //dead end
                print(n); //printing the board configuration
            else //try queen with next position
                queen(row+1,n);
        }
    }
}

/*
Algorithm:
N - Queens (k, n)   
{      
    For i  ←  1 to n           
        do if Place (k, i) then      
        {         
            x [k]  ←  i;         
            if (k ==n) then           
                write (x [1....n));         
            else         
                N - Queens (k + 1, n);      
        }   
}

Time Complexity:
For finding a single solution where the first queen Q has been assigned the 
first column and can be put on N positions, the second queen has been 
assigned the second column and would choose from N-1 possible positions and so on; 
the time complexity is O ( N ) * ( N - 1 ) * ( N - 2 ) * … 1 ). 
i.e The worst-case time complexity is O ( N! ). 
*/

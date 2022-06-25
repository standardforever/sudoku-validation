#include<stdbool.h>
#include<stdio.h>

/**
 * sorting - it sort a given array of numbers in ascending order and check
 * 			if no repetation of numbers
 * 
 * @param arr: pointer to the array to be sorted
 * @param num: the total number of element in the array
 * @return int: 0 if repitation of numbers else 1 
 */
int sorting(unsigned int *arr, unsigned int num){
	int j, n;
    unsigned int i;
	int status = 0;
	unsigned int hold = arr[0];
	int index1 = 0;
	int index2;

	n = num;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < n; j++)
		{
			if(hold > arr[j])
			{
				index2 = j;
				arr[index1] = arr[j];
				arr[index2] = hold;
				status = 1;
			}
			hold = arr[j];
			index1 = j;
		}
         
		if (status == 0)
			break;
		hold = arr[0];
		index1 = 0;
		n--;
        status = 0;    
	}
    for (i = 1; i <= num; i++)
	{
		if (i != arr[i - 1])
			return (0);
	}
    return (1);
}



/**
 * row_validation - it validate the row of a 9 * 9 2D array
 * 
 * @brief - it checks each row and make sure that it contains number from 1-9,
 * 			with no repetation.
 * @param board: 9*9 2D array
 * @return int: 1 if no repetation per each row else 0
 */
int row_validation(unsigned int board[9][9])
{
	int i;
    int status = 0;

	for (i = 0; i < 9; i++)
	{	
		/*sorting and making sure no repetation of digits*/	
        status = sorting(board[i], 9);
        if (status == 0)
            break;	
	}
	return (status);
}


/**
 * col_validation - it validate the column of a 9 * 9 2D array
 * 
 * @brief - it checks each column and make sure that it contains number from 1-9,
 * 			with no repetation.
 * @param board: 9*9 2D array
 * @return int: 1 if no repetation per each row else 0
 */
int col_validation(unsigned int board[9][9])
{
    int i, j, status = 0, n = 0;
    unsigned int hold[9];

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            hold[j] = board[j][n];
        }
        n++;
		/*sorting and making sure no repetation of digits*/
        status = sorting(hold, 9);
        if (status == 0)
            break;	
	}
	return (status);
}


/**
 * box_validation - it validate the box of a 9 * 9 2D array
 * 
 * @brief - it checks each box and make sure that it contains number from 1-9,
 * 			with no repetation.
 * @param board: 9*9 2D array
 * @return int: 1 if no repetation per each row else 0
 */

int box_validation(unsigned int board[9][9])
{
    int i, j, status = 0, n = 0, k = 0;
    int track = 3, track_1 = 0;
    unsigned int hold[9];

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            /*stores the value of 3*3 of the board in "hold"*/
            hold[j] = board[n][k];
            k++;
            /* checks if the k is at the 3rd column */
            /* if yes move to the next three 3*3 grid to the right*/
            if (k == track)
            {
                n++;
                k -= 3;
            }
        }
        track += 3;
        k += 3;
        n = track_1;

        /* checks if k is at the end of the column(9) */
        /* if yes move to the next three 3*3 grid below*/
        if (k == 9)
        {
            track_1 += 3;
            track = 3;
            n = track_1;
            k = 0;
        }
        /*sorting and making sure no repetation of digits*/
        status = sorting(hold, 9);
        if (status == 0)
            break;	
    }
    return (status);
}

/**
 * @brief it checks if a sudo board is valid
 * 
 * @param board: the 9*9 sudo board
 * @return true if the board is valid
 * @return false if not valid
 */
bool validSolution(unsigned int board[9][9]){
	 /* Write your code here */
	if (box_validation(board) == 0)
		return (false);
	if (col_validation(board) == 0)
		return (false);
	if (row_validation(board) == 0)
		return (false);
	return (true);
}

/**
 * @brief main function
 * 
 * @return 0
 */
int main (void)
{
unsigned int example1[9][9]={{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}}; 
    bool s = validSolution(example1);
   printf("%i\n", s);
   return (0);
}
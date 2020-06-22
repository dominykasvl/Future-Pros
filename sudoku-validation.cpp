#include <iostream>
#include <set>

using namespace std;

class ValidateSolution
{
    public:
    bool valid_solution(unsigned short int solution[10][10])
    {
        //creating the sets and variables for columns and blocks but in array of 10. The idea is to keep track of blocks, rows and columns unique members to keep number of loops minimal
            set<unsigned short int> checkSolutionCol[10];
            //set<unsigned short int> checkSolutionBlock[10];

            unsigned short int colSize[10], blockSize[10];
            for (int i = 0; i < 10; i++)
            {
                colSize[i]=checkSolutionCol[i].size();
                //blockSize[i]=checkSolutionBlock[i].size();
            }
            
        for (int row = 0; row < 9; row++)
        {
            set<unsigned short int> checkSolutionRow; //creating a set, that will allow to insert only unique numbers
            unsigned short int rowSize=checkSolutionRow.size(); //creating additional variable that will keep track whether the set size has changed or not
            

            for (int col = 0, block=0; col < 9; col++)
            {
                if(solution[row][col]==0) return false;
                checkSolutionCol[col].insert(solution[row][col]);
                checkSolutionRow.insert(solution[row][col]);

                //check if sets have changed or not - if yes, function return false, otherwise return false
                if (checkSolutionRow.size()>rowSize)
                {
                    rowSize=checkSolutionRow.size();
                }
                else
                {
                    return false;
                }

                if (checkSolutionCol[col].size()>colSize[col])
                {
                    colSize[col]=checkSolutionCol[col].size();
                }
                else
                {
                    return false;
                }

                /*if (checkSolutionBlock[block].size()>blockSize[block])
                {
                    blockSize[block]=checkSolutionBlock[block].size();
                }
                else
                {
                    return false;
                }*/
            }
            
        }

        return true;
    };
};

int main()
{
    ValidateSolution sudoku;
    unsigned short int test[10][10]={{5,3,4,6,7,8,9,1,2}, {6,7,2,1,9,5,3,4,8}, {1,9,8,3,4,2,5,6,7}, {8,5,9,7,6,1,4,2,3}, {4,2,6,8,5,3,7,9,1}, {7,1,3,9,2,4,8,5,6}, {9,6,1,5,3,7,2,8,4}, {2,8,7,4,1,9,6,3,5}, {3,4,5,2,8,6,1,7,9}};
    bool answer = sudoku.valid_solution(test); 
    if(answer==1) cout<<"true";
    else cout<<"false";
}

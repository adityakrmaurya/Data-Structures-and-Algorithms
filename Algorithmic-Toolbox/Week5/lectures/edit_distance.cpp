/*
 * Edit distance : 
 * The edit distance or Levenshtein distance is the minimum number of 
 * editing operations needed to transform a string into another string.
 * The following operations are allowed to transform one string into another:
 * 1. Insertion
 * 2. Deletion
 * 3. Substitutions
 * Example : 
 *  LOVE and MOVIE
 *  edit_distance = 2
 * 
 * Reference :
 * 1. Competitive Programmers Handbook
 * 2. http://users.monash.edu/~lloyd/tildeAlgDS/Dynamic/Edit/
 */
#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y, int z)
{
    
    return min(min(x, y), z);
}

void print(vector<vector<int>>& v)
{
    for(auto const& row : v){
        for(auto const& col : row){
            cout << col << " ";
        }
        cout << "\n";
    }
}

int edit_distance(string& a, string& b, vector<vector<int>>& dp)
{
    for(size_t i = 0; i <= a.length(); i++){
        for(size_t j = 0; j <= b.length(); j++){
            
            // Initialize the 0th row
            if(i == 0){
                dp[i][j] = j;
            }
            
            // Initialize the 0th column
            else if(j == 0){
                dp[i][j] = i;
            }
            
            // match case
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            
            // insertion, deletion, transition
            else{
                int insertion = dp[i][j-1],
                    deletion  = dp[i-1][j], 
                    transition = dp[i-1][j-1];
                dp[i][j] = min(insertion, deletion, transition) + 1;
            }
        }
    }
    return dp[a.length()][b.length()];
}

int main(void)
{
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp (a.length()+1, vector<int> (b.length()+1, 0));
    int edit = edit_distance(a, b, dp);
    print(dp);
    cout << "edit_distance : " << edit;
    return 0;
}
























// Intorduction : // alignment game
// common subsequence
// longest common subsequence

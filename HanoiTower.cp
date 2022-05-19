// Project: Hanoi Tower
// Author: Wesley
// Date: 03/17/2021
#include <iostream>

using namespace std;
 
void towerOfHanoi(int n, char from_rod,
                char to_rod, char aux_rod)
{
    if (n == 0)
        return;
    
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<
            " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    cout << "請輸入盤子數：";
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

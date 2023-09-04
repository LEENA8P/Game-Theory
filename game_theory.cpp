#include <iostream>
#include <cstdlib>
#include <ctime>  
using namespace std;

int random(int n){

	// Loop to get 5 random numbers

		
		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		int random = (rand() % n);

		// Print the random number

	

	return random;
}

int main(){

int diamonds[] = {3,1,5,4,2};
int balance[] = {5,5,5};
int bid[] = {0,0,0};
int dimOwn[] = {0 ,0 ,0};
int face[] ={ 0,0,0};


// shuffle_array(diamonds,5);
// cout <<"This time the pamel of daimonds is....";
// for (int i = 0; i < 5; ++i){
//         cout << diamonds[i] << " ";
//     }
//     cout << endl;

    srand((unsigned) time(NULL));
int n = -1;
int k = -1;
for (int p = 0; p < 5; p++){

n = -1;
k = -1;
       for (int i = 0; i < 3; i++)
        {
                int hi = rand() % balance[i];
                bid[i] = hi;
            while (bid[i] == k)
            {
                bid[i] = rand() % balance[i] ;
        
            }
            cout << "Bid is.." <<bid[i]<<endl<<endl;
            
            k = max(k,bid[i]);
            if(k == bid[i]){
                n = i;
            
        }
        }
        

        
    
        balance[n] -= k;
        dimOwn[n] += diamonds[p];
        if(k > face[n]){
            face[n] = k;
        }
        for (int j = 0; j < 3; j++)
        {
            cout << "Balance of player "<<j <<" is "<<balance[j]<<" and his dimond value is "<<dimOwn[j]<<endl;
        }
        cout <<endl;
        
}
int win = 0;
int winner = 0;
for (int i = 0; i < 3; i++)
{
        int value = balance[i] + dimOwn[i];
        if(value > win){
            winner = i;
            win = value;
        }
        else if(value == win){
            if(balance[i] > balance[winner]){
                winner = i;
            }
            else if(balance[i] < balance[winner]){
                continue;
            }
            else{
                if(face[i] > winner){
                    winner = i;
                }
                else{
                    continue;
                }
            }
        }
}

cout << "The winer of the game is player " << winner<<" whose net value is "<<win;





return 0 ;
}
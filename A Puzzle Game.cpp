/*

The puzzle is a 3x3 board consisting of numbers from 1 to 9. The objective of the puzzle is to swap the tiles until the following final state is reached:

1 2 3
4 5 6
7 8 9

At each step, swap two adjacent tiles if their sum is a prime number. Two tiles are considered adjacent if they have a common edge.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

class Matrix {
	public :
		int grid[3][3];
		int level;
		Matrix * cameFrom;
		int error;
};

bool isPrime(int value) {
	for(int i = 2 ; i < value/2 ; i++) {
		if(value % i == 0) {
			return false;
		}
	}

	return true;
}

void printMatrix(int grid[3][3]) {
	for(int i = 0 ; i < 3 ; i++) {
		for(int j = 0 ; j < 3 ; j++) {
			std :: cout << grid[i][j] << " ";
		}
		std :: cout << std :: endl;
	}
	std :: cout << std :: endl << std :: endl;
}

int getHammingError(int current[3][3], int final[3][3]) {

	int counter = 0;
	for(int i = 0 ; i < 3 ; i++) {
		for(int j = 0 ; j < 3 ; j++) {
			if(current[i][j] != final[i][j]) {
				counter++;
			}
		}

	}
	return counter;
}

Matrix * newNode(int grid[3][3], int level, Matrix * cameFrom) {

	Matrix * node = new Matrix;
	node->level = level;
	node->cameFrom = cameFrom;
	memcpy(node->grid, grid, sizeof(int) * 9);
	return node;
}

struct  cmp {
	 bool operator ()(const Matrix * lhs, const Matrix * rhs) const  {
		return ((lhs->level + lhs->error) > (rhs->level + rhs->error));
	} 
};

bool isValidMove(int x, int y) {
	return (x >= 0 && x < 3 && y >= 0 && y < 3);
}

int row[4] = {1, 0, -1 , 0};
int col[4] = {0, 1, 0 , -1};

void swapTiles(int grid[3][3], int iX, int iY, int fX, int fY) {
	std :: swap(grid[iX][iY], grid[fX][fY]);
}

void solve(int initial[3][3], int final[3][3]) {

	std :: priority_queue <Matrix * , std :: vector <Matrix *> , cmp > pq;
	Matrix * root = newNode(initial, 0, NULL);
	root->error = getHammingError(root->grid, final);
	int i = 362880; //9!
	pq.push(root);

	while(!pq.empty() && i--) {
		Matrix * min = pq.top();
	pq.pop();

		if(min->error == 0) {
			while(min != NULL) {
				printMatrix(min->grid);
				min = min->cameFrom;
			}
			return;
		}

		for(int i = 0 ; i < 3 ; i++) {
			for(int j = 0 ; j < 3 ; j++) {
				for(int k = 0 ; k < 4 ; k++) {
					if(isValidMove(i + row[k], j + col[k])) {
						if(isPrime(min->grid[i][j] + min->grid[i+row[k]][j+col[k]])) {
							Matrix * child = newNode(min->grid, min->level+1, min);
							std :: swap(child->grid[i][j], child->grid[i+row[k]][j+col[k]]);
							child->error = getHammingError(child->grid, final);
							pq.push(child);
						}
					}
				}
			}
		}
 	}

 	std :: cout << "UNSOLVED!";

}




int main() {

	int initial[3][3] = {
		{7,3,2},
		{4,1,5},
		{6,8,9}
	};

	int final[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	solve(initial, final);

	return 0;
}



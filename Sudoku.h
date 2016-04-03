#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void change();
		void printout(int arr[]);
		static const int sudokuSize = 81;

	private:
		int player_map[sudokuSize];

};

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Sudoku.h"
using namespace std;

void Sudoku::giveQuestion(){
	int ans_map[81]={8,0,0,0,0,0,0,0,0,
	                    0,0,3,6,0,0,0,0,0,
		                0,7,0,0,9,0,2,0,0,
	                    0,5,0,0,0,7,0,0,0,
	                    0,0,0,0,4,5,7,0,0,
	                    0,0,0,1,0,0,0,3,0,
		                0,0,1,0,0,0,0,6,8,
	                    0,0,8,5,0,0,0,1,0,
                        0,9,0,0,0,0,4,0,0};
	for(int i=0;i<sudokuSize;i++){
		if((i+1)%9==0){
			cout<<endl;
		}
		else cout<<ans_map[i]<<" ";
	}
}


void Sudoku::readIn(){
	for(int i=0;i<sudokuSize;i++)
		cin>>player_map[i];
}

void Sudoku::solve(){
	int i,j,k,n,m,count,tag,countcheck,firstZero,las,temp[sudokuSize]={0},a=0,check[sudokuSize]={0};
	for(i=0;i<sudokuSize;i++){
		if(player_map[i]!=0)check[i]=1;
	}

		count=1;
	for(firstZero=0;firstZero<sudokuSize;firstZero++)if(check[firstZero]==0)break;
	for(i=0;i<sudokuSize;i++){
		temp[i]=player_map[i];
	}
	for(i=0;i<sudokuSize;i++){
		if(player_map[i]!=0){
			for(j=0;j<9;j++){
				if(player_map[i]==player_map[(i/9)*9+j]){
					if(i==(i/9)*9+j)continue;
					cout<<"0"<<endl;			//check題目
					return;
				}
			}
			for(k=0;k<9;k++){
				if(player_map[i]==player_map[(i%9)+(k*9)]){
					if(i==(i%9)+(k*9))continue;
					cout<<"0"<<endl;
					return;
				}
			}
			n=i/27;
			m=(i/3)%3;
			for(k=0;k<9;k++){
				if(player_map[(27*n)+(3*m)+9*(k/3)+(k%3)]!=0&&i!=(27*n)+(3*m)+9*(k/3)){
					if(player_map[i]==player_map[(27*n)+(3*m)+9*(k/3)]){
						cout<<"0"<<endl;
						return;
					}
				}
			}
		}
	}
	for(i=0;i<sudokuSize;){
		tag=0;
		if(check[i]==0){
			while(1){
				countcheck=count;
				for(j=0;j<9;j++){					//檢驗row
					if(count==player_map[(i/9)*9+j]){
						if(i==(i/9)*9+j)continue;
						count+=1;
					}
				}
				for(k=0;k<9;k++){						//檢驗col
					if(count==player_map[(i%9)+(k*9)]){
						if(i==(i%9)+(k*9))continue;
						count+=1;
					}
				}
				n=i/27;
				m=(i/3)%3;
				for(k=0;k<9;k++){						//檢驗宮
					if(player_map[(27*n)+(3*m)+9*(k/3)+(k%3)]!=0 && i!=(27*n)+(3*m)+9*(k/3)+(k%3)){
						if(count==player_map[(27*n)+(3*m)+9*(k/3)+(k%3)])count++;
					}
				}
				if((countcheck==count)||(count>9))break;
			}


		while(1){
			if(count>9&&i>firstZero){
				tag=1;
				while(1){
					if((check[i-1]==0)||(i-1==firstZero))break;
					else i--;
				}
				i--;
				count=player_map[i]+1;
				if(i==firstZero&&count==10){
					cout<<"0"<<endl;
					return;
				}
				player_map[i]=0;
			}
			else break;
			}

			if(i==firstZero&&count==10){
				cout<<"0"<<endl;
				return;
			}	

			if((count<=9)&&(tag==0)){
				player_map[i]=count;
				i++;
				count=1;
				}
			}

		else if(check[i]==1)i++;
		}

		count=9;

		for(i=0;i<sudokuSize;i++){
			if(temp[i]==0)temp[i]=10;
		}
		for(i=0;i<sudokuSize;){
			tag=0;
		    if(check[i]==0){
		   	     while(1){
				 	countcheck=count;
					for(j=0;j<9;j++){                   //檢驗row
						if(count==temp[(i/9)*9+j]){
							if(i==(i/9)*9+j)continue;
							count--;
							}
						}
					for(k=0;k<9;k++){                       //檢驗col
						if(count==temp[(i%9)+(k*9)]){
							if(i==(i%9)+(k*9))continue;
							count--;
							}
						}
						n=i/27;
						m=(i/3)%3;
					for(k=0;k<9;k++){                       //檢驗宮
						if(temp[(27*n)+(3*m)+9*(k/3)+(k%3)]!=0 && i!=(27*n)+(3*m)+9*(k/3)+(k%3)){
							if(count==temp[(27*n)+(3*m)+9*(k/3)+(k%3)])count--;
							}
						}
						if((countcheck==count)||(count<1))break;
					}
				 while(1){
				 	if(count<1&&i>0){
						tag=1;
						while(1){
							if(check[i-1]==0||i-1==firstZero)break;
							else i--;
						}
						i--;
						count=temp[i]-1;
						temp[i]=10;
					}
					else break;
				 }
				 if((count<=9)&&(count>0)&&(tag==0)){
				 	temp[i]=count;
					count=9;
					i++;
				 }
		}
			else if(check[i]==1)i++;

		}
				for(i=0;i<sudokuSize;i++){
					if(temp[i]==player_map[i])a++;
				}
				if(a!=81){
					cout<<"2"<<endl;
					return;
				}
				else if(a==81){
					cout<<"1"<<endl;

					for(int i=0;i<sudokuSize;i++){
						if((i+1)%9==0){

						cout<<player_map[i]<<endl;
						}
						else cout<<player_map[i]<<" ";
					}

					return;
				}
}
void Sudoku::changeNum(int a,int b){
	int temp;
	for(int i=0;i<sudokuSize;i++){
		temp=player_map[i];
		if(player_map[i]==a)player_map[i]=b;
		if(temp==b)player_map[i]=a;
	}
}

void Sudoku::changeRow(int a,int b){
	int temp=0;
	for(int i=0;i<27;i++){
		temp=player_map[a*27+i];
		player_map[a*27+i]=player_map[b*27+i];
		player_map[b*27+i]=temp;
	}
}

void Sudoku::changeCol(int a,int b){
	int i,j,temp;
	for(i=0;i<9;i++)
		for(j=0;j<3;j++){
			temp=player_map[a*3+j*1+i*9];
			player_map[a*3+j*1+i*9]=player_map[b*3+j*1+i*9];
			player_map[b*3+j*1+i*9]=temp;
		}
}

void Sudoku::rotate(int n){
	int temp[sudokuSize]={0},k=0,count=0;
	while(count<n%4){
		for(int j=8;j>=0;j--){
			for(int i=0;i<9;i++){
			temp[9*i+j]=player_map[k];
			k++;
				}
		}
		for(int r=0;r<sudokuSize;r++)
			player_map[r]=temp[r];
		count++;
		k=0;
	}
}

void Sudoku::flip(int n){
	int i,j,temp;
	if(n==0){
		for(j=0;j<4;j++){
			for(i=0;i<9;i++){
				temp=player_map[i+j*9];
				player_map[i+j*9]=player_map[72+i-j*9];
				player_map[72+i-j*9]=temp;
			}
		}
	}
	else if(n==1){
		for(j=0;j<9;j++){
			for(i=0;i<4;i++){
				temp=player_map[i+j*9];
				player_map[i+j*9]=player_map[8-i+j*9];
				player_map[8-i+j*9]=temp;
			}
		}
	}
}

void Sudoku::transform(){
	readIn();
	change();
	printout(player_map);
}

void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::printout(int arr[]){
		for(int i=0;i<sudokuSize;i++){
			if((i+1)%9==0){
				cout<<endl;
		}
		else cout<<arr[i]<<" ";
	}

}







#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int rows = 15, cols = 16;

char words[rows][cols]{
    "tgbwwinterwsesn",
    "aaunttmmhfoodnb",
    "jlwcqldzmpmvdmr",
    "asagmquwvvbsohi",
    "bwplotanadtpgnc",
    "rewngodjcpnatnk",
    "eeotwosbqharrsa",
    "azcgeswewnaknpb",
    "dinnerqodlwdcar",
    "onopkwmparktzcc",
    "qbfrogmamwpweey",
    "lqzqnnmrzjjsclg",
    "mosgzczetdbooto",
    "pdcrzmsngrdnrpz",
    "ohnkzwaterjgtra"
};

char *getWordDiagonal(int row,int col);
bool searchDiagonal(char *str);
char *reverse(char *r);
char *getWordVertical(int w);
bool searchVertical(char *s);
char *getWordHorizontal(int w);
bool searchHorizontal(char *s);

int main(){
	
    int w;
    char word[16];
    cin >> w;
    cin.ignore(w,'\n');
    for (int i=0;i<w;i++){
        cin.getline(word,16,'\n');
        if (searchDiagonal(word) || searchVertical(word) || searchHorizontal(word))
            cout << "Ada\n";
        else 
            cout << "Tidak Ada\n";
    }
    return 0;
}

char *reverse(char *r){ 
    char *s = r;
	reverse(s,s+(int) strlen(r));
	return s;
}

char *getWordDiagonal(int row,int col){
    char string[16];
    if(rows - row < cols - col){
        for(int i = 0;i < rows-row;i++){
            string[i] = words[row+i][col+i];
        }
    }else{
    	for(int i = 0;i < cols-col;i++){
            string[i] = words[row+i][col+i];
        }
	}
    char *s = string;
    return s;
}

bool searchDiagonal(char *str){
    char *strcheck;
    for(int kol=0 ; kol<cols; kol++){
        for(int bar=0;bar<rows;bar++){
            strcheck = getWordDiagonal(bar,kol);
            char *check = strstr(strcheck,str);
            char *checkreverse = strstr(reverse(strcheck),str);
            if (check > 0 || checkreverse > 0){
                return true;
            }
            else{
                continue;	
            }
        }
	}
    return false;
}

char *getWordVertical(int n){
	char string[cols];
	for(int i = 0;i<rows;i++){
		string[i] = words[i][n];
	}
	char *result = string;
	return result;
}

bool searchVertical(char *s){
	for(int i = 0;i < cols;i++){
		char *strcheck = getWordVertical(i);
		char *check;
		char *reversecheck;
		check = strstr(strcheck,s);
		check = strstr(reverse(strcheck),s);
		
		if(check > 0 || reversecheck > 0){
			return true;
		}
	}
	return false;
}

char *getWordHorizontal(int n){
	char string[cols];
	for(int i = 0;i<cols;i++){
		string[i] = words[n][i];
	}
	char *s = string;
	return s;
}

bool searchHorizontal(char *s){
	for(int i = 0;i < rows;i++){
		char *strcheck = getWordHorizontal(i);	
		char *check;
		char *reversecheck;
		check = strstr(strcheck,s);
		reversecheck = strstr(reverse(strcheck),s);
		
		if(check>0 || reversecheck>0){
			return true;
		}
	}
	return false;
}

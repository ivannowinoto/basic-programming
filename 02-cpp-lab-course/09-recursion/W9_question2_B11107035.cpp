#include <iostream>
using namespace std;

struct Student
{
    char name[10];
    int mid;
    int fin;
};

void bubble_sort(int *scoreTotal, int *mid, int *fin, string *name, int n)
{
	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	string temp4 = "0";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (scoreTotal[i] < scoreTotal[j]) {
                temp1 = scoreTotal[i];
                temp2 = mid[i];
                temp3 = fin[i];
                temp4 = name[i];
                scoreTotal[i] = scoreTotal[j];
                mid[i] = mid[j];
                fin[i] = fin[j];
                name[i] = name[j];
                scoreTotal[j] = temp1;
                mid[j] = temp2;
                fin[j] = temp3;
                name[j] = temp4;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    Student st[n];
    
    for (int i = 0; i < n; i++) {
        cin >> st[i].name >> st[i].mid >> st[i].fin;
    }
    
    int mid[n];
    int fin[n];
    int scoreTotal[n];
    string name[n];
    for (int i = 0; i < n; i++) {
        mid[i] = st[i].mid;
        fin[i] = st[i].fin;
        scoreTotal[i] = st[i].mid + st[i].fin;
        name[i] = st[i].name; 
    }
    
    bubble_sort(scoreTotal, mid, fin, name, n);
    
    cout << "Name\tMidterm\tFinal\tTotal" << endl;
    for (int i = 0; i < n; i++) {
        cout << name[i] << "\t" << mid[i] << "\t" << fin[i] << "\t" << scoreTotal[i] << endl;
    }
    
}

#include <iostream>
using namespace std;

struct Student 
{
	string name;
	int midterm;
	int final;
	int total;
	int a;
	int b;
	int c;
	Student* next;
};

Student* insert(Student* head, string name, int midterm, int final, int total)
{
	if (head == NULL) {
		Student* student = new Student();
		student -> name = name;
		student -> midterm = midterm;
		student -> final = final;
		student -> total = total;
		student -> next = NULL;
		return student;
	}
	else {
		Student* current = head;
		Student* student = new Student();
		student -> name = name;
		student -> midterm = midterm;
		student -> final = final;
		student -> total = total;
		student -> next = NULL;
		while (current -> next != NULL) {
			current = current -> next;
		}
		current -> next = student;
		return head;
	}
	return head;
}

Student* swap(Student* head, int a, int b)
{
	Student* temp = head;
	Student* node1;
	Student* node2;
	Student* prev1 = NULL;
	Student* prev2 = NULL;
	int i = 1;
	
	while (temp != NULL)
	{
		if (i == a) prev1 = temp;
		if (i == a + 1) node1 = temp;
		
		if (i == b) prev2 = temp;
		if (i == b + 1) node2 = temp;
		
		temp = temp -> next;
		i++;
	}
	
	if (node1 != NULL && node2 != NULL){
		if (prev1 != NULL) prev1 -> next = node2;
		if (prev2 != NULL) prev2 -> next = node1;
		
		temp = node1 -> next;
		node1 -> next = node2 -> next;
		node2 -> next = temp;
		
		if(prev1 == NULL) head = node2;
		else if (prev2 == NULL) head = node1; 
	}
	return head;
}

Student* del(Student* head, int c)
{
	Student* temp = head;
	Student* prev = head;
	
	for (int i = 0; i <= c; i++) {
		if(i == 0 && c == 0) {
			head = head -> next;
			return head;
		}
		else {
			if(i == c && temp){
				prev -> next = temp -> next;
				return head;
			}
			else {
				prev = temp;
				if (prev == NULL)
					break;
				temp = temp -> next;
			}
		}
	}
	return head;
}


void print(Student *head)
{
	cout << "Name\tMidterm\tFinal\tTotal" << endl;
	while (head != NULL) {
		cout << head -> name << "\t";
		cout << head -> midterm << "\t";
		cout << head -> final << "\t";
		cout << head -> total << "\t\n";
		head = head -> next;
	}
	cout << endl;
}

int main()
{
	string name1 = "AAA", name2 = "BBB", name3 = "CCC";
	int mid1 = 10, mid2 = 30, mid3 = 50;
	int fin1 = 20, fin2 = 40, fin3 = 60;
	int tot1 = mid1 + fin1, tot2 = mid2 + fin2, tot3 = mid3 + fin3;
	
	Student* head = NULL;
	head = insert(head, name1, mid1, fin1, tot1);
	head = insert(head, name2, mid2, fin2, tot2);
	head = insert(head, name3, mid3, fin3, tot3);
	print(head);
	
	head = swap(head, 0, 1);
	print(head);
	
	head = del(head, 1);
	print(head);
	
	return 0;
} 

#include<iostream>
using namespace std;

// Function to check the Vowel
bool isVowel(char ch)
{
	ch = toupper(ch);
	return (ch=='A' || ch=='E' || ch=='I' ||
					ch=='O' || ch=='U');
}

// Returns count of vowels in str
int countVowels(string str)
{
	int count = 0;
	for (int i=0; i<str.length(); i++)
		if (  isVowel(str[i])) // Check for vowel
			++count;
	return count;
}


int main()
{

	string str;
    cout<<"enter the string "<<endl;
    cin>>str;

	cout <<"total number of vowels : "<< countVowels(str) << endl;
	return 0;
}

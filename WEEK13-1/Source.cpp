#include <iostream>
#include <fstream>
using namespace std;
void Error()
{
	cout << "ERROE" << endl;
}
void Readss()
{
	cout << "read suscess" << endl;

}
void Writer()  
{
	cout << "writer suscess" << endl;
}
int main()
{
	STAR:
	int score[5];
	for (int i = 0; i < 5; i++)
	{
		score[i] = 0;
	}
	int score_now;
	cin >> score_now;


	ifstream readfile("C:/Users/GP73/Desktop/score.txt");
	if (readfile.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			readfile >> score[i]  ;
			cout << i+1<<". : " << score[i] << endl;
		}
		Readss();
	}
	else
	{
		Error();
	}
	readfile.close();


	ofstream writer("C:/Users/GP73/source/repos/Test_sfml/Test_sfml/Picture/New folder/Config/scores.txt");
	if (writer.is_open())
	{
		int index_score;
		bool index_on = false;
		for (int i = 0; i < 5; i++)
		{
			if (score_now > score[i])
			{
				index_score = i; 
				index_on = true;
				break;
			}
		}
		
		if (index_on)
		{
			for (int i = 4; i > index_score; i--)
			{
				score[i] = score[i - 1];
			
			}
		
			score[index_score] = score_now;


		}
		for (int i = 0; i < 5; i++)
		{
			writer << score[i] << endl;
			cout << i + 1 << ". : " << score[i] << endl;
		}
		cout << "BEST SCORE : " << score[0] << endl;
		Writer();
	}
	else
	{
		Error();
	}
	
	writer.close();

	goto STAR;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.h"
using namespace std;

string HuffMan(string Texte, string Alphabet)
{
	string codeHuffMan;
	string Text_tab=Texte;
	string alphabet = Alphabet;
	vector<CNode> m_lstNode;
	vector<int> Text_Compt;
	vector<char> test;


	for (unsigned int j = 0; j < alphabet.size(); ++j)
	{ //affichage de la liste 
		cout <<"/n"<< "char alphabet n°" << j << " : " << alphabet[j] << endl;
		Text_Compt.push_back(count(Text_tab.begin(), Text_tab.end(), alphabet[j]));	
		test.push_back(alphabet[j]);
	}

	sort(Text_Compt.begin(), Text_Compt.end());

	for(auto a : Text_Compt)
	{
		cout << a;
	}
	for (unsigned int i = 0;i<alphabet.size();++i)
	{
		CNode(test[i], Text_Compt.front()+i);
	}

	
	return codeHuffMan;
}

int main()
{
	string Text;
	string Reponse;
	cout << "Entrez votre chaine de caractères à coder : " << endl;
	cin >> Text;

	string alphabet;
	cout << "Entrez votre alphabet : " << endl;
	cin >> alphabet;
	Reponse = HuffMan(Text, alphabet);
	cout << "La phrase codee est : " << endl;
	//cout<<Reponse;
}


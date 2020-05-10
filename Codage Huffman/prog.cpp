#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.h"
using namespace std;

string HuffMan(string Texte, string Alphabet) {
	string codeHuffMan;
	string Text_tab=Texte;
	string alphabet = Alphabet;
	vector<CNode> m_lstNode;
	vector<int> Text_Compt;


	for (size_t j = 0; j <= alphabet.size()-1; j++) { //affichage de la liste 
		cout <<"/n"<< "char alphabet n°" << j << " : " << alphabet[j] << endl;
		Text_Compt.push_back(count(Text_tab.begin(), Text_tab.end(), alphabet[j]));	
	}
	sort(Text_Compt.begin(), Text_Compt.end());
	for(auto a : Text_Compt){
		cout << a;
	}
	


	
	return codeHuffMan;
}

int main()
{
	string Text;
	//string Reponse;
	cout << "Entrez votre chaine de caractères à coder : " << endl;
	cin >> Text;

	string alphabet;
	cout << "Entrez votre alphabet : " << endl;
	cin >> alphabet;
	//Reponse = HuffMan(Text, alphabet);
	cout << "La phrase codee est : " << endl;
	//cout<<Reponse;
	HuffMan(Text,alphabet);
}


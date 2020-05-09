#include <iostream>
#include "Node.h"
using namespace std;

#include <iostream>
#include <list>
#include "Node.h"
using namespace std;

int main()
{
	string Text;
	//string Reponse;
	cout << "Entrez votre chaine de caractères à coder : " << endl;
	cin >> Text;

	string alphabet;
	cout << "Entre ton alphabet : " << endl;
	cin >> alphabet;
	//Reponse = HuffMan(Text, alphabet);
	cout << "La phrase codee est : " << endl;
	//cout<<Reponse;
}

string HuffMan(string Texte, string Alphabet) {
	string codeHuffMan;
	list<string> Text_tab;
	list<CNode> m_lstNode;

	for (size_t i = 0; i <= Texte.size(); i++) {
		Text_tab.push_back(Texte.substr(i));
	}
	for (size_t j = 0; j <= Text_tab.size(); j++) { //affichage de la liste 
		cout << "char n°" << j << " : " << Text_tab[j] << endl;
	}



	//m_lstNode.pushback(NewNode);
	return codeHuffMan;

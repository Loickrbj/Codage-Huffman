#include <iostream>
#include <vector>
#include <algorithm>
#include<list>
#include "Node.h"
using namespace std;

string HuffMan(string Texte, string Alphabet)
{
	string codeHuffMan;
	vector<string> phrase_codee;
	string Text_tab=Texte;
	string alphabet = Alphabet;
	list<CNode> m_lstNode;
	vector<int> Text_Proba;
	vector<char> alphab;
	CNode Node;
	CNode* filsdroit;
	CNode* filsgauche;


	for (unsigned int j = 0; j < alphabet.size(); ++j)
	{ //affichage de la liste de l'alphabet'
		cout <<"\nchar alphabet n°" << j << " : " << alphabet[j] << endl;
		Text_Proba.push_back(count(Text_tab.begin(), Text_tab.end(), alphabet[j]));	
		alphab.push_back(alphabet[j]);
	}
	
	//sort(Text_Compt.begin(), Text_Compt.end());

	for(auto a : Text_Proba)
	{
		cout << a;
	}
	for (unsigned int i = 0;i<alphabet.size();++i)
	{
		Node = CNode(alphab[i], Text_Proba.front()+i);
		m_lstNode.push_back(Node);
	}

	while(m_lstNode.size() >= 2)
	{
		//trie par ordre decroissant
		reverse(*m_lstNode.begin(), m_lstNode.end());


		//prendre les deux dernier noeuds et les supprimer de la liste
		filsdroit = m_lstNode.back();
		m_lstNode.pop_back();
		filsgauche = m_lstNode.back();
		m_lstNode.pop_back();

		//créer un nouveau noeud père qui aura pour fils les deux noeuds précédemment supprimés
		Node = CNode(filsdroit.Getlettre() + filsgauche.Getlettre(), filsdroit.GetProba() + filsgauche.GetProba());
		cout << Node.Getlettre();
		Node.SetFilsDroit(filsdroit);
		Node.SetFilsGauche(filsgauche);
		//mettre un code à ces deux fils (0 pour le fils droit à plus faible probabilité et 1 pour l'autre)
		filsdroit.SetCodeHuffMan("0");
		filsgauche.SetCodeHuffMan("1");

		//ajouter le noeud père à la liste
		m_lstNode.push_back(Node);
	}

	//chercher chaque lettre dans l'arbre binaire
	for(auto i : Texte)
	{

		//tant que le noeud de la lettre qu'on cherche a pas été trouvé :
		/*while(Texte[int j = 0] == m_lstNode[int i= 0].Getlettre() && m_lstNode[i].size()== 1)
		{
		for()
		
		j++;
		}
		*/
	}
		
	

	
	
	//return phrase_codee;
}

int main(){
	string Text;//chaine de caracteres que l'utilisateur rentre
	string Reponse;//Code Huffman, sera affiché à la fin
	string alphabet;//Alphabet utilisé dans la chaine de caracteres
	cout << "Entrez votre chaine de caractères à coder : " << endl;
	cin >> Text;//L'utilisateur rentre sa chaine de caractere
	cout << "Entrez votre alphabet : " << endl;
	cin >> alphabet;//L'utilisateur rentre l'alphabet utilisé
	Reponse = HuffMan(Text, alphabet);//On appel la fonction pour obtenir le code Huffman
	cout << "La phrase codee est : " << endl;
	cout<<Reponse;//On affiche le resultat
	


}
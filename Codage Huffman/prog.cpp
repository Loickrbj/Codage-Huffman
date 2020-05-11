#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include "Node.h"
using namespace std;

string HuffMan(string Texte, string Alphabet)
{
	string codeHuffMan;
	vector<string> phrase_codee;
	string Text_tab = Texte;
	string alphabet = Alphabet;
	vector<CNode> m_lstNode;
	vector<int> Text_Proba;
	string alphab;
	CNode filsdroit;
	CNode filsgauche;
	//list<CNode> Arbre;

	for (unsigned int j = 0; j < alphabet.size(); ++j)
	{ //affichage de la liste de l'alphabet'
		cout << "\nchar alphabet n°" << j << " : " << alphabet[j] << endl;
		Text_Proba.push_back(count(Text_tab.begin(), Text_tab.end(), alphabet[j]));
		alphab.push_back(alphabet[j]);
	}

	//sort(Text_Compt.begin(), Text_Compt.end());

	for (auto a : Text_Proba)
	{
		cout << a;
	}
	for (unsigned int i = 0; i < alphabet.size(); ++i)
	{
		string alpha;
		alpha.push_back(alphab[i]);
		CNode Node(alpha, Text_Proba[i]);
		m_lstNode.push_back(Node);
	}
	//trie par ordre decroissant
	unsigned int i,j;
	CNode c;
	for(i=0;i<m_lstNode.size()-1;i++)
    for( j=i+1;j<m_lstNode.size();j++)
        if ( m_lstNode[i].GetProba() > m_lstNode[j].GetProba() ) {
            c = m_lstNode[i];
            m_lstNode[i] = m_lstNode[j];
            m_lstNode[j] = c;
        }
	reverse(m_lstNode.begin(), m_lstNode.end());
	//sort(m_lstNode.begin(), m_lstNode.end());
	cout << endl << "apres tri: " << endl;
	for (auto a : m_lstNode)
	{
		cout << a.GetProba();
	}
	while (m_lstNode.size() >= 2)
	{
		//prendre les deux dernier noeuds et les supprimer de la liste
		filsdroit = m_lstNode.back();
		m_lstNode.pop_back();
		filsgauche = m_lstNode.back();
		m_lstNode.pop_back();

		//créer un nouveau noeud père qui aura pour fils les deux noeuds précédemment supprimés
		CNode Node(filsdroit.Getlettre() + filsgauche.Getlettre(), filsdroit.GetProba() + filsgauche.GetProba());
		cout << endl << Node.Getlettre()<<endl;
		cout << "-----------------------\n";
		Node.SetFilsDroit(&filsdroit);
		Node.SetFilsGauche(&filsgauche);
		//mettre un code à ces deux fils (0 pour le fils droit à plus faible probabilité et 1 pour l'autre)
		filsdroit.SetCodeHuffMan("0");
		filsgauche.SetCodeHuffMan("1");

		//ajouter le noeud père à la liste
		m_lstNode.push_back(Node);
		//Arbre.push_back(Node);
		
	}
	//chercher chaque lettre dans l'arbre binaire
	
	CNode Teste = m_lstNode.back();
	CNode FDroit();
	CNode FGauche();
	while(Teste.Has_Fils())
	{
		Teste.GetFilsDroit();
		Teste.GetFilsGauche();
	}
	

	//for (auto i : Arbre)
	//{

		//tant que le noeud de la lettre qu'on cherche a pas été trouvé :
		/*while(Texte[int j = 0] == m_lstNode[int i= 0].Getlettre() && m_lstNode[i].size()== 1)
		{
		for()

		j++;
		}
		*/
	//}
	//return phrase_codee;
	return codeHuffMan;
}

int main()
{
	string Text;//chaine de caracteres que l'utilisateur rentre
	string Reponse;//Code Huffman, sera affiché à la fin
	string alphabet;//Alphabet utilisé dans la chaine de caracteres
	cout << "Entrez votre chaine de caractères à coder : " << endl;
	cin >> Text;//L'utilisateur rentre sa chaine de caractere
	cout << "Entrez votre alphabet : " << endl;
	cin >> alphabet;//L'utilisateur rentre l'alphabet utilisé
	Reponse = HuffMan(Text, alphabet);//On appel la fonction pour obtenir le code Huffman
	cout << "La phrase codee est : " << endl;
	cout << Reponse;//On affiche le resultat
}
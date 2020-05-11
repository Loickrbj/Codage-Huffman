#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include "Node.hpp"
using namespace std;


int byWeight(CNode a,CNode b)
{
	if(a.GetProba()>b.GetProba())
	{
		return 1;
	}
	else{
		if (a.GetProba() > b.GetProba())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

/*vector<CNode> tri(vector<CNode> m_lstNode)
{
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
	return m_lstNode;
}*/

string Find_Letter(CNode* Noeud, char lettre, string alphabet)
{
	cout<<"Test: "<<Noeud->GetFilsGauche()->GetFilsDroit()->Getlettre()<<endl;
	bool CheckGauche=false;
	string Huff;
	int compteurv2 = 0;
	while (Noeud->GetFilsGauche()!=nullptr)
	{

		for (auto car : Noeud->GetFilsGauche()->Getlettre()) {

			if (car == lettre) {
				CheckGauche = true;
			}
		}

		if (CheckGauche) {
			//insérer commande Huffman '1'
			Noeud = Noeud->GetFilsGauche();
			Huff += '0';

		}
		else {
			//insérer commande Huffman '0'
			Noeud = Noeud->GetFilsDroit();
			Huff += '1';
		}
		CheckGauche = false;
		Huff += ' ';
		compteurv2++;
		return Huff; // return ici car sinon boucle infini et on peut rien voir 
	}

}

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


	for (unsigned int j = 0; j < alphabet.size(); ++j)
	{ //affichage de la liste de l'alphabet'
		cout << "\nchar alphabet n°" << j << " : " << alphabet[j] << endl;
		Text_Proba.push_back(count(Text_tab.begin(), Text_tab.end(), alphabet[j]));
		alphab.push_back(alphabet[j]);
	}
	
	for (auto a : Text_Proba)
	{
		cout << a;
	}
	for (unsigned int i = 0; i < alphabet.size(); ++i)
	{
		string alpha;
		alpha.push_back(alphab[i]);
		CNode Node(alpha,"","", Text_Proba[i]);
		m_lstNode.push_back(Node);
	}
	//trie par ordre decroissant
	//tri(m_lstNode);
	

	//------------------------------------------------------
	while (m_lstNode.size() >= 2)
	{
		sort(m_lstNode.begin(), m_lstNode.end(), byWeight);
		//m_lstNode=tri(m_lstNode);
		/*cout << endl << "apres tri: " << endl;
	for (auto a : m_lstNode)
	{
		cout << a.GetProba();
	}*/
		//cout << "AVANT\n";
		//prendre les deux dernier noeuds et les supprimer de la liste
		/*for(auto i: m_lstNode)
		{
			cout << endl << i.Getlettre();
		}*/
		filsdroit = m_lstNode.back();
		m_lstNode.pop_back();
		filsgauche = m_lstNode.back();
		m_lstNode.pop_back();
		//cout << "APRES\n";
		for(auto i: m_lstNode)
		{
			cout << endl << i.Getlettre() << endl;
		}
		//créer un nouveau noeud père qui aura pour fils les deux noeuds précédemment supprimés
		CNode Node("",filsdroit.Getlettre() , filsgauche.Getlettre(), filsdroit.GetProba() + filsgauche.GetProba());
		cout << endl << Node.Getlettre()<<endl;
		//cout << endl << Node.GetProba()<<endl;
		cout << "-----------------------\n";
		Node.SetFilsDroit(&filsdroit);
		Node.SetFilsGauche(&filsgauche);
		cout << "Fils droit"<<endl;
		cout<<Node.GetFilsDroit()->Getlettre()<<endl;
		cout << "Fils gauche"<<endl;
		cout << Node.GetFilsGauche()->Getlettre()<<endl;
		
		//ajouter le noeud père à la liste
		m_lstNode.push_back(Node);
		
	}
	

	//chercher chaque lettre dans l'arbre binaire
	CNode* Noeud= &m_lstNode.back();
	string code;
	code = Find_Letter(Noeud, 'p', alphabet);
	return code;
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

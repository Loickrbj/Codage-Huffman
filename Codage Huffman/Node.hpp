#pragma once
#include <iostream>
#include <string>


class CNode {

private:
	//Creation des variables:
	int proba; //nombre apparition lettre
	std::string CodeHuffMan; // code HuffMan de la lettre
	std::string lettre; // c'est la lettre
	CNode* filsdroit =nullptr; // pointeur vers le fils droit
	CNode* filsgauche=nullptr; //Pointeur vers le fils gauche
	CNode* pere= nullptr; //pointeur v	using pNode
	//std::shared_ptr<CNode>;

public:

	
	//Declaration du constructeur:
	CNode(std::string lalettre, std::string lettrefilsgauche, std::string lettrefilsdroit, int lafrequence);
	CNode() {};

	//Getteurs:
	std::string Getlettre() { return lettre; }
	std::string GetCodeHuffMan() { return CodeHuffMan; }
	int GetProba() { return proba; }
	CNode* GetFilsDroit() { return filsdroit; }
	CNode* GetFilsGauche() { return filsgauche; }
	CNode* GetPere() { return pere; }

	//Setteurs
	void Setlettre(char new_lettre) { lettre = new_lettre; }
	void SetCodeHuffMan(std::string code) { CodeHuffMan = code; }
	void SetProba(int new_proba) { proba = new_proba; }
	void SetFilsDroit(CNode* FilsD) { filsdroit = FilsD; }
	void SetFilsGauche(CNode* FilsG) { filsgauche = FilsG; }
	void Setpere(CNode* papa){pere = papa;}
	bool Has_Fils();
	void PushbackHuffman(char code) { CodeHuffMan.push_back(code); };
};

//Definiton du constructeur:
CNode::CNode(std::string lalettre,std::string lettrefilsgauche, std::string lettrefilsdroit, int lafrequence)
{
	lettre = lalettre;
	lettre += lettrefilsgauche;
	lettre += lettrefilsdroit;
	proba = lafrequence;

}

bool CNode::Has_Fils()
{
	if (GetFilsDroit() == nullptr)
	{
		std::cout << "NO HAS FILS\n";
		return false;
	}
	else
	{
		return true;
	}

};
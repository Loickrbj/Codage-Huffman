#pragma once
#include <iostream>
#include <string>


class CNode {

private:
	//Creation des variables:
	int proba; //nombre apparition lettre
	std::string CodeHuffMan; // code HuffMan de la lettre
	std::string lettre; // c'est la lettre
	//Les enfants, ces connards:
	CNode* filsdroit; // pointeur vers le fils droit
	CNode* filsgauche; //Pointeur vers le fils gauche
	CNode* pere; //pointeur vers le pere 
public:

	
	//Declaration du constructeur:
	CNode( std::string lalettre, int lafrequence);
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
};

//Definiton du constructeur:
CNode::CNode(std::string lalettre, int lafrequence)
{
	lettre = lalettre;
	proba = lafrequence;
	pere = nullptr;
}

bool CNode::Has_Fils()
{
	if(GetFilsDroit()==nullptr && GetFilsGauche()==nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}



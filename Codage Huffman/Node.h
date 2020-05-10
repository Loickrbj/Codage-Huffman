#pragma once
#include <iostream>
#include <string>


class CNode {
private:
	//Creation des variables:
	int proba; //nombre apparition lettre
	std::string CodeHuffMan; // code HuffMan de la lettre
	char lettre; // c'est la lettre
	//Les enfants, ces connards:
	CNode* filsdroit; // pointeur vers le fils droit
	CNode* filsgauche; //Pointeur vers le fils gauche

public:
	//Declaration du constructeur:
	CNode(std::string lalettre, int lafrequence);
	CNode() {};

	//Getteurs:
	std::string Getlettre() { return lettre; }
	std::string GetCodeHuffMan() { return CodeHuffMan; }
	int GetProba() { return proba; }
	CNode* GetFilsDroit() { return filsdroit; }
	CNode* GetFilsGauche() { return filsgauche; }

	//Setteurs
	void Setlettre(std::string new_lettre) { lettre = new_lettre; }
	void SetCodeHuffMan(std::string code){CodeHuffMan=code;}
	void SetProba(int new_proba) { proba = new_proba; }
	void SetFilsDroit(CNode* Fils) { filsdroit = Fils; }
	void SetFilsGauche(CNode* Fils) { filsgauche = Fils; }
};

//Definiton du constructeur:
CNode::CNode(char lalettre, int lafrequence)
{
	lettre = lalettre;
	proba = lafrequence;
}





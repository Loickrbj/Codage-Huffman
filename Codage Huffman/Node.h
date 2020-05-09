#pragma once
#include <iostream>
#include <string>


class CNode {
private:
	int proba;
	std::string CodeHuffMan;
	char lettre;
	CNode* filsdroit;
	CNode* filsgauche;


	

public:
	CNode(char lalettre, int lafrequence);
	char Getlettre() { return lettre; }
	std::string GetCodeHuffMan() { return CodeHuffMan; }
	void Setlettre(char new_lettre) { lettre = new_lettre; }
	void SetCodeHuffMan(std::string code){CodeHuffMan=code;}
};


CNode::CNode(char lalettre, int lafrequence)
{
	lettre = lalettre;
	proba = lafrequence;

}





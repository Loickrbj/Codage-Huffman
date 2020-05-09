#pragma once
#include <iostream>
#include <string>


class CNode {
private:
	int proba;
	std::string CodeHuffMan;
	std::string lettre;
	CNode* filsdroit;
	CNode* filsgauche;
	

public:
	CNode(std::string lalettre, int lafrequence);
	std::string Getlettre() { return lettre; }
	std::string GetCodeHuffMan() { return CodeHuffMan; }
	void Setlettre(std::string new_lettre) { lettre = new_lettre; }
	void SetCodeHuffMan(std::string code){CodeHuffMan=code;}
};


CNode::CNode(std::string lalettre, int lafrequence)
{
	lettre = lalettre;
	proba = lafrequence;

}





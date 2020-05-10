#pragma once
#include <LibGraph2.h>

#include "Edge.hpp"
#include "Node.hpp"

#include <iostream>
#include <memory>
#include <set>
#include <vector>

class CGraph{

public:
	
	using pNodeSet = std::set<CNode::pNode>;
	using pEdgeSet = std::set<CEdge::pEdge>;

	CGraph() {};

	std::size_t GetNumberOfEdges() const { return m_spEdges.size(); }
	std::size_t GetNumberOfNodes() const { return m_spNodes.size(); }
	const pNodeSet& GetNodes() const { return m_spNodes; }
	const pEdgeSet& GetEdges() const { return m_spEdges; }

	void AddNewNode(CNode::pNode pNode) { m_spNodes.insert(pNode); }
	void AddNewEdge(CEdge::pEdge pEdge) { m_spEdges.insert(pEdge); }

	void RemoveEdge(CEdge::pEdge pEdge) {
		// On cherche l'arete dans le set d arete
		auto itpEdge = std::find(m_spEdges.begin(), m_spEdges.end(), pEdge); 
		if (itpEdge != m_spEdges.end())
			m_spEdges.erase(itpEdge);
		// else warning dans la console ?
	}

	void RemoveNode(CNode::pNode pNode) {
		// On cherche le noeud dans le set de noeud
		auto itpNode = std::find(m_spNodes.begin(), m_spNodes.end(), pNode); 
		// Si ce noeud existe
		if (itpNode != m_spNodes.end())
		{
			// On enleve toutes les aretes touchant ce noeud
			for (auto itpEdge = m_spEdges.begin(); itpEdge != m_spEdges.end();  )
			{
				if ((*itpEdge)->GetNode(0) == (*itpNode) || (*itpEdge)->GetNode(1) == (*itpNode))
					itpEdge = m_spEdges.erase(itpEdge);
				else
					itpEdge++;
			}
			// on enleve le noeud car il ne touche plus d arete
			m_spNodes.erase(itpNode);
		}
	}

	CNode::pNode GetNodeFromName(const std::string& name) const
	{
		// On parcourt le set de noeud et on renvoie celui qui a le bon nom
		for (auto& pNode : m_spNodes)
			if (pNode->GetName() == name)
				return pNode;
		// si non trouvé :
		return CNode::pNode(nullptr);
	}


	std::size_t GetNodeDegree(CNode::pNode pNode) const
	{
		std::size_t countDegree = 0;
		// Pour chaque arete si elle touche le noeud on incremente le degre
		for (auto pEdge : m_spEdges)
		{
			if (pEdge->GetFirstNode() == pNode)  
				++countDegree;
			if (pEdge->GetSecondNode() == pNode)
				++countDegree;
		}
		return countDegree;
	}


	friend std::ostream& operator<<(std::ostream& os, const CGraph& g)
	{
		os << "Graph : " << std::endl;
		os << "\tSommets : " << g.GetNumberOfNodes() << std::endl;
		for (auto n : g.GetNodes()) os << "\t\t" << n->GetName() << ", " << std::endl;
		os << "\tAretes : " << g.GetNumberOfEdges() << std::endl;
		for (auto e : g.GetEdges())
		{
			os << "\t\t";
			for (auto n : e->GetNodes())
				os << n->GetName() << "->";
			os << e->GetWeight() << std::endl;
		}

		return os;
	}
	
protected : 
	
	pEdgeSet m_spEdges; 
	pNodeSet m_spNodes;


	// TP 2 : 

public :

	void Clear() { m_spEdges.clear(); m_spNodes.clear(); }

	void ClearEdges() { m_spEdges.clear(); }

	bool CheckNodesAreNeighbors(CNode::pNode pNode1, CNode::pNode pNode2) const
	{
		for (const auto pEdge : m_spEdges)
		{
			if (pEdge->GetFirstNode() == pNode1 && pEdge->GetSecondNode() == pNode2)
				return true;
			else if (pEdge->GetFirstNode() == pNode2 && pEdge->GetSecondNode() == pNode1)
				return true;
		}
		return false;
	}

	// TP 3 : On rajoute un alias sur un vecteur de pNode
	using  pNodeVector = std::vector<CNode::pNode>; // Alias sur un vecteur de noeud


	CGraph::pNodeVector CGraph::GetUncolored() const
	{
		pNodeVector uncoloredNodes;
		for (auto pNode : m_spNodes)
			if (pNode->GetColor() == -1)
				uncoloredNodes.push_back(pNode);
		return uncoloredNodes;
	}


	// TP 3 : C est le coeur du TP 
	// Il faut programmer le proceder de coloration par welch Powell
	void ColorByWelchPowell() 
	{
		
	}
	

	// TODO : On cherche le noeud le plus proche du point(x,y)
	// On initialise une distanceMin au max des float : FLT_MAX
	// Pour chaque noeud on calcule la distance euclienne entre lui et le point(x,y)
	// Si cette distance est inferieure a la distance min
	//       On met a jour la nouvelle distance et le pointeur sur le noeud le plus proche
	const CNode::pNode CGraph::GetNodeNear(float x, float y) const 
	{ 
		return nullptr;
	}

	// TODO : On cherche l arete la plus proche du point(x,y)
// On initialise une distanceMin au max des float : FLT_MAX
// Pour chaque arete on calcule la distance euclienne entre le milieu de l arete et le point(x,y)
// Si cette distance est inferieure a la distance min
//       On met a jour la nouvelle distance et le pointeur sur l arete la plus proche
	const CEdge::pEdge CGraph::GetEdgeNear(float x, float y) const
	{
		return nullptr;
	}

};

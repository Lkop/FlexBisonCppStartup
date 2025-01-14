#include "Composite.h"

// initialize static variables
CSTNode *g_root=NULL;
int CSTNode::ms_serialCounter = 0;
const char* g_nodeTypeLabels[] = {"COMPILEUNIT","STATEMENTS", "STATEMENT", "EXPRESSION_NUMBER", "EXPRESSION_ADDITION" };

CSTNode::CSTNode(NodeType type,int num,...) :m_nodeType{ type } {
	va_list argumentList;

	va_start(argumentList, num);
	
	m_serial = ms_serialCounter++;
	m_graphvizLabel = g_nodeTypeLabels[m_nodeType];
	m_children = new list<CSTNode *>();

	for ( int i = 0; i<num;i++)	{
		m_children->push_back(va_arg(argumentList, CSTNode *));
	}
	
	va_end(argumentList);
}

NodeType CSTNode::GetNodeType(){
	return m_nodeType;
	
}
string CSTNode::GetGraphVizLabel(){
	return m_graphvizLabel;
}



#ifndef _METERPRETER_PIVOT_TREE
#define _METERPRETER_PIVOT_TREE

typedef DWORD(*PivotWritePacket)(LPVOID state, LPBYTE rawPacket, DWORD rawPacketLength);

typedef struct _PivotContext
{
	PivotWritePacket packet_write;
	LPVOID state;
} PivotContext;

typedef struct _PivotNode PivotNode;

typedef struct _PivotTree
{
	PivotNode* head;
} PivotTree;

typedef void(*PivotTreeTraverseCallback)(LPBYTE guid, PivotContext* ctx, LPVOID state);

PivotTree* pivot_tree_create();
DWORD pivot_tree_add(PivotTree* tree, LPBYTE guid, PivotContext* ctx);
DWORD pivot_tree_remove(PivotTree* tree, LPBYTE guid);
PivotContext* pivot_tree_find(PivotTree* tree, LPBYTE guid);
void pivot_tree_traverse(PivotTree* tree, PivotTreeTraverseCallback callback, LPVOID state);
void pivot_tree_destroy(PivotTree* tree);

#endif
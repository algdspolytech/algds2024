/* 2023/2024 - 2 semester, Data design in applications
 * Author: Pavel Dvas, 5030102/20002
 * File Name: avl.c
 * Last Updated: 17.03.2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"

/* Create new node funciton.
 * ARGUMENTS:
 *   - new key:
 *       int Key;
 * RETURNS: None.
 */
Node * NewNode( int Key )
{
  Node * node = (Node *)malloc(sizeof(Node));
  node->key = Key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;

  return node;
} /* End of 'NewNode' function */

/* Get node's height function.
 * ARGUMENTS:
 *   - node itself:
 *       Node *Node;
 * RETURNS:
 *   (int) - node's height.
 */
int GetHeight( Node *Node )
{
  if (Node == NULL)
    return 0;
  return Node->height;
} /* End of 'GetHeight' function */

/* Get node's balance function.
 * ARGUMENTS:
 *   - node itself:
 *       Node *Node;
 * RETURNS:
 *   (int) - node's balance.
 */
int GetBalance( Node *Node )
{
  if (Node == NULL)
    return 0;
  return GetHeight(Node->left) - GetHeight(Node->right);
} /* End of 'GetBalance' function */

/* Right rotate node function.
 * ARGUMENTS:
 *   - node to rotate:
 *       Node *Y;
 * RETURNS:
 *   (Node *) - rotated node.
 */
Node * RightRotate( Node *Y )
{
  Node *X = Y->left;
  Node *T2 = X->right;

  X->right = Y;
  Y->left = T2;

  Y->height = (GetHeight(Y->left) > GetHeight(Y->right) ? GetHeight(Y->left) : GetHeight(Y->right)) + 1;
  X->height = (GetHeight(X->left) > GetHeight(X->right) ? GetHeight(X->left) : GetHeight(X->right)) + 1;

  return X;
} /* End of 'RightRotate' function */

/* Left rotate node function.
 * ARGUMENTS:
 *   - node to rotate:
 *       Node *Y;
 * RETURNS:
 *   (Node *) - rotated node.
 */
Node * LeftRotate( Node *X )
{
  Node *Y = X->right;
  Node* T2 = Y->left;

  Y->left = X;
  X->right = T2;

  X->height = (GetHeight(X->left) > GetHeight(X->right) ? GetHeight(X->left) : GetHeight(X->right)) + 1;
  Y->height = (GetHeight(Y->left) > GetHeight(Y->right) ? GetHeight(Y->left) : GetHeight(Y->right)) + 1;

  return Y;
} /* End of 'LeftRotate' function */

/* Insert node function.
 * ARGUMENTS:
 *   - node to insert:
 *       Node *Node;
 *   - key to insert:
 *       int Key;
 * RETURNS:
 *   (Node *) - new root.
 */
Node * Insert( Node *Node, int Key )
{
  int balance;

  if (Node == NULL)
    return NewNode(Key);

  if (Key < Node->key)
    Node->left = Insert(Node->left, Key);
  else if (Key > Node->key)
    Node->right = Insert(Node->right, Key);
  else
    return Node;

  Node->height = (GetHeight(Node->left) > GetHeight(Node->right) ? GetHeight(Node->left) : GetHeight(Node->right)) + 1;

  balance = GetBalance(Node);

  if (balance > 1 && Key < Node->left->key)
    return RightRotate(Node);

  if (balance < -1 && Key > Node->right->key)
    return LeftRotate(Node);

  if (balance > 1 && Key > Node->left->key)
  {
    Node->left = LeftRotate(Node->left);
    return RightRotate(Node);
  }

  if (balance < -1 && Key < Node->right->key)
  {
    Node->right = RightRotate(Node->right);
    return LeftRotate(Node);
  }

  return Node;
} /* End of 'Insert' function */

/* Get minimum value node function.
 * ARGUMENTS:
 *   - tree's root:
 *       node *node;
 * RETURNS:
 *   (Node *) - minimum value node.
 */
Node * MinValueNode( Node *node )
{
  Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
} /* End of 'MinValueNode' function */

/* Delete node function.
 * ARGUMENTS:
 *   - tree's root:
 *       Node *Root;
 *   - key to delete:
 *       int Key;
 * RETURNS:
 *   (Node *) - new root.
 */
Node * DeleteNode( Node *Root, int Key )
{
  int balance;

  if (Root == NULL)
    return Root;

  if (Key < Root->key)
    Root->left = DeleteNode(Root->left, Key);
  else if (Key > Root->key)
    Root->right = DeleteNode(Root->right, Key);
  else
  {
    if ((Root->left == NULL) || (Root->right == NULL))
    {
      Node *temp = Root->left ? Root->left : Root->right;

      if (temp == NULL)
      {
        temp = Root;
        Root = NULL;
      }
      else
        *Root = *temp;
      free(temp);
    }
    else
    {
      Node *temp = MinValueNode(Root->right);

      Root->key = temp->key;

      Root->right = DeleteNode(Root->right, temp->key);
    }
  }

  if (Root == NULL)
    return Root;

  Root->height = (GetHeight(Root->left) > GetHeight(Root->right) ? GetHeight(Root->left) : GetHeight(Root->right)) + 1;

  balance = GetBalance(Root);

  if (balance > 1 && GetBalance(Root->left) >= 0)
    return RightRotate(Root);

  if (balance > 1 && GetBalance(Root->left) < 0)
  {
    Root->left = LeftRotate(Root->left);
    return RightRotate(Root);
  }

  if (balance < -1 && GetBalance(Root->right) <= 0)
    return LeftRotate(Root);

  if (balance < -1 && GetBalance(Root->right) > 0)
  {
    Root->right = RightRotate(Root->right);
    return LeftRotate(Root);
  }

  return Root;
} /* End of 'Delete' function */

/* Print tree function.
 * ARGUMENTS:
 *   - tree's root:
 *       Node *Root;
 *   - string to print tree:
 *       char *Str;
 * RETURNS: None.
 */
void PrintTree( Node *Root, char *Str )
{
  char *S[10];
  if (Root == NULL)
  {
    sprintf(S, "*");
    strcat(Str, S);
    return;
  }
  sprintf(S, "%d(", Root->key);
  strcat(Str, S);
  PrintTree(Root->left, Str);
  sprintf(S, ",");
  strcat(Str, S);
  PrintTree(Root->right, Str);
  sprintf(S, ")");
  strcat(Str, S);
} /* End of 'PrintTree' function */

/* END OF 'avl.c' FILE */

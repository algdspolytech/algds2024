/* 2023/2024 - 2 semester, Data design in applications
 * Author: Pavel Dvas, 5030102/20002
 * File Name: avl.h
 * Last Updated: 17.03.2024
 */
#ifndef AVL_H
#define AVL_H

#ifdef __cplusplus
extern "C" {
#endif

/* AVL-tree struct */
typedef struct tagNode Node;

struct tagNode {
    int key;
    Node *left;
    Node *right;
    int height;
};

/* Create new node funciton.
 * ARGUMENTS:
 *   - new key:
 *       int Key;
 * RETURNS: None.
 */
Node * NewNode( int Key );

/* Get node's height function.
 * ARGUMENTS:
 *   - node itself:
 *       Node *Node;
 * RETURNS:
 *   (int) - node's height.
 */
int GetHeight( Node *Node );

/* Get node's balance function.
 * ARGUMENTS:
 *   - node itself:
 *       Node *Node;
 * RETURNS:
 *   (int) - node's balance.
 */
int GetBalance( Node *Node );

/* Right rotate node function.
 * ARGUMENTS:
 *   - node to rotate:
 *       Node *Y;
 * RETURNS:
 *   (Node *) - rotated node.
 */
Node * RightRotate( Node *Y );

/* Left rotate node function.
 * ARGUMENTS:
 *   - node to rotate:
 *       Node *Y;
 * RETURNS:
 *   (Node *) - rotated node.
 */
Node * LeftRotate( Node *X );

/* Insert node function.
 * ARGUMENTS:
 *   - node to insert:
 *       Node *Node;
 *   - key to insert:
 *       int Key;
 * RETURNS:
 *   (Node *) - new root.
 */
Node * Insert( Node *Node, int Key );

/* Get minimum value node function.
 * ARGUMENTS:
 *   - tree's root:
 *       node *node;
 * RETURNS:
 *   (Node *) - minimum value node.
 */
Node * MinValueNode( Node *node );

/* Delete node function.
 * ARGUMENTS:
 *   - tree's root:
 *       Node *Root;
 *   - key to delete:
 *       int Key;
 * RETURNS:
 *   (Node *) - new root.
 */
Node * DeleteNode( Node *Root, int Key );

/* Print tree function.
 * ARGUMENTS:
 *   - tree's root:
 *       Node *Root;
 *   - string to print tree:
 *       char *Str;
 * RETURNS: None.
 */
void PrintTree( Node *Root, char *Str );

#ifdef __cplusplus
}
#endif

#endif //AVL_H

/* END OF 'avl.h' FILE */

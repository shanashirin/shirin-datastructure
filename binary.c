#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; //node will store some data
  struct node *right_child; // right child
  struct node *left_child; // left child
};

//function to create a node
struct node* new_node(int x) {
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp -> data = x;
  temp -> left_child = NULL;
  temp -> right_child = NULL;
  return temp;
}

// searching operation
struct node* search(struct node * root, int x) {
  if (root == NULL || root -> data == x) //if root->data is x then the element is found
    return root;
  else if (x > root -> data) // x is greater, so we will search the right subtree
    return search(root -> right_child, x);
  else //x is smaller than the data, so we will search the left subtree
    return search(root -> left_child, x);
}

// insertion
struct node* insert(struct node * root, int x) {
  if (root == NULL)
    return new_node(x);
  else if (x > root -> data) // x is greater. Should be inserted to the right
    root -> right_child = insert(root -> right_child, x);
  else // x is smaller and should be inserted to left
    root -> left_child = insert(root -> left_child, x);
  return root;
}

//function to find the minimum value in a node
struct node* find_minimum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root -> left_child != NULL) // node with minimum value will have no left child
    return find_minimum(root -> left_child); // left most element will be minimum
  return root;
}

// deletion
struct node* delete(struct node * root, int x) {
  if (root == NULL)
    return NULL;
  if (x > root -> data)
    root -> right_child = delete(root -> right_child, x);
  else if (x < root -> data)
    root -> left_child = delete(root -> left_child, x);
  else {
    //No Child node
    if (root -> left_child == NULL && root -> right_child == NULL) {
      free(root);
      return NULL;
    }
    //One Child node
    else if (root -> left_child == NULL || root -> right_child == NULL) {
      struct node *temp;
      if (root -> left_child == NULL)
        temp = root -> right_child;
      else
        temp = root -> left_child;
      free(root);
      return temp;
    }
    //Two Children
    else {
      struct node *temp = find_minimum(root -> right_child);
      root -> data = temp -> data;
      root -> right_child = delete(root -> right_child, temp -> data);
    }
  }
  return root;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root -> left_child);
    printf(" %d ", root -> data);
    inorder(root -> right_child);
  }
}

int main() {
  struct node *root = NULL;
  int choice, value;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Inorder Traversal\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value to insert: ");
        scanf("%d", &value);
        root = insert(root, value);
        printf("%d inserted.\n", value);
        break;

      case 2:
        printf("Enter value to search: ");
        scanf("%d", &value);
        if (search(root, value) != NULL)
          printf("%d found in the tree.\n", value);
        else
          printf("%d not found in the tree.\n", value);
        break;

      case 3:
        printf("Enter value to delete: ");
        scanf("%d", &value);
        root = delete(root, value);
        printf("%d deleted.\n", value);
        break;

      case 4:
        printf("Inorder traversal: ");
        inorder(root);
        printf("\n");
        break;

      case 5:
        printf("Exiting program.\n");
        exit(0);

      default:
        printf("Invalid choice! Please try again.\n");
    }
  }
  return 0;
}



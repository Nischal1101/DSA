void iinsert(struct newNode *root, int key)
{
    struct newNode *prev = NULL;
    while (root != NULL)
    {

        prev =root;

        if (key == root->data)
        {

            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct newNode *new = createNode(key);
    if (key < prev->data)
    {

        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
int Depth(node *root)
{
    if (root_iter == NULL)
    {
        return 0;
    }

    if (root->left != NULL)
    {
        hight_Left++;
        Depth(root_iter->left);
    }

    if (root->right != NULL)
    {
        if (root->right->left != NULL)
        {
            hight_Right++;
        }

        Depth(root->right);
    }

    if (hight_Left > hight_Right)
    {
        return hight_Left;
    }
    else
    {
        return hight_Right;
    }
}
#include <iostream>
#include <vector>

template<class T>
struct Node {
    T data;
    Node *left;
    Node *right;
};

void listLeavesHelper(Node<int> *root, std::vector<int> &list) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        list.push_back(root->data);
        return;
    }

    listLeavesHelper(root->left, list);
    listLeavesHelper(root->right, list);
}

std::vector<int> listLeaves(Node<int> *root) {
    std::vector<int> res;
    listLeavesHelper(root, res);
    return res;
}

std::string findTrace(Node<int> *root, const int &x) {
    if (root == nullptr) {
        return "_";
    }

    if (root->data == x) {
        return "";
    }

    std::string L = "L" + findTrace(root->left, x);
    std::string R = "R" + findTrace(root->right, x);

    if (L.back() != '_') {
        return L;
    } else if (R.back() != '_') {
        return R;
    } else {
        return "_";
    }
}

int getAtHelper(Node<int> *root, size_t &i) {
    if (root == nullptr) {
        return 0;
    }
    if (i == 0) {
        return root->data;
    }

    int res = getAtHelper(root->left, --i);
    res += getAtHelper(root->right, --i);
    return res;
}

int getAt(Node<int> *root, size_t i) {
    return getAtHelper(root, i);
}

std::string getLongest(const std::string &s1, const std::string &s2) {
    return s1.length() >= s2.length() ? s1 : s2;
}

std::string getLongestRoute(Node<char> *root) {
    if (root == nullptr) {
        return "";
    }

    return getLongest(root->data + getLongestRoute(root->left),
                      root->data + getLongestRoute((root->right)));
}

//std::string getNextLevel
std::string getLongestLevel(Node<char> *root, std::vector<std::string> &v) {
    if (root == nullptr) {
        return "";
    }

    return "";
}

template<class T>
bool equals(Node<T> *t1, Node<T> *t2) {
    if (!t1 && !t2) {
        return true;
    }
    if (!t1 || !t2) {
        return false;
    }

    return t1->data == t2->data && equals(t1->left, t2->left) && equals(t1->right, t2->right);
}

template<class T>
bool subtree(Node<T> *t1, Node<T> *t2) {
    if (!t1 || !t2) {
        return false;
    }
    if (t1->data == t2->data) {
        return equals(t1, t2);
    }
    return subtree(t1->left, t2) || subtree(t1->right, t2);
}

int main() {
    Node<int> *root = new Node<int>{15,
                                    new Node<int>{13,
                                                  new Node<int>{10},
                                                  new Node<int>{14,
                                                                new Node<int>{20,
                                                                              new Node<int>{0,
                                                                                            new Node<int>{4}}}}},
                                    new Node<int>{25}};

    std::vector<int> test = listLeaves(root);
    for (int i: test) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << findTrace(root, 5) << std::endl;
    std::cout << getAt(root, 20) << std::endl;

    Node<char> *root2 = new Node<char>{'a',
                                       new Node<char>{'b',
                                                      new Node<char>{'c'}},
                                       new Node<char>{'d',
                                                      new Node<char>{'e', nullptr,
                                                                     new Node<char>{'f'}},
                                                      new Node<char>{'g'}}};
    Node<char> *root3 = new Node<char>{'d',
                                       new Node<char>{'e', nullptr,
                                                      new Node<char>{'f'}},
                                       new Node<char>{'g'}};
    std::cout << getLongestRoute(root2) << std::endl;
//    std::vector<std::string> vec;
//    std::cout << getLongestLevel(root2, vec)<<std::endl;
    std::cout << std::boolalpha << equals(root2, root3) << std::endl;
    std::cout << std::boolalpha << subtree(root2, root3) << std::endl;
}
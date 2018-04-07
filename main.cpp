#include <iostream>
using namespace std;

class tree_t
{
private:
    struct node_t {
        node_t * left;
        node_t * right;
        int value;

        node_t() {
            left = nullptr;
            right = nullptr;
            value = 0;
        }
        ~node_t() {
            delete left;
            delete right;
        }

        void add(int new_value) {
            if (value > new_value) {
                if (left == nullptr) {
                    left = new node_t();
                    left->value = new_value;
                }
                else left->add(new_value);
            }
            else if (value < new_value) {
                if (right == nullptr){
                    right = new node_t;
                    right->value = new_value;
                }
                else right->add(new_value);
            }
        }

        void print_t(ostream & stream, int range) const {
            if (right != nullptr) right->print_t(stream, range + 4);
            for (int i = 0; i < range + 4; i++) cout << '-';
            cout << value << '\n';
            if (left != nullptr) left->print_t(stream, range + 4);
        }

        bool find_t(int new_value) const {
            if (value == new_value) return true;
            if (value < new_value) {
                if (right != nullptr) return right->find_t(new_value);
                else return false;
            }
            if (value > new_value) {
                if (left != nullptr) return left->find_t(new_value);
                else return false;
            }
        }
    };
private:
    node_t * root_;
public:
    tree_t() {
        root_ = nullptr;
    }
    ~tree_t() {
        delete root_;
    }

    void insert(int value) {
        if (root_ == nullptr) {
            root_ = new node_t;
            root_->value = value;
        }
        else root_->add(value);
    }

    bool find(int value) const {
        if (root_ != nullptr) return root_->find_t(value);
    }

    void print(ostream & stream) const {
        if (root_ != nullptr) {
            root_->print_t(cout, 0);
        }
        else cout << "Tree is empty\n";
    }
};

int main() {
    tree_t tree;
    char op;
    int znach;
    while (cin >> op) {
        switch (op) {
            case '+':
                if (cin >> znach) tree.insert(znach);
                else cout << "An fatal error has occured while reading input data\n";
                break;
            case '?':
                if (cin >> znach) {
                    if (!tree.find(znach)) cout << "false\n";
                    else cout << "true\n";
                }
                else cout << "An fatal error has occured while reading input data\n";
                break;
            case '=':
                tree.print(cout);
                break;
            case 'q':
                exit(5);
            default:
                if (cin >> znach) cout << "An  error has occured while reading input data\n";
                else cout << "An fatal error has occured while reading input data\n";
                break;
        }
    }
}

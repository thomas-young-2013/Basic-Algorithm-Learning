#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stack>

using namespace std;

struct Node {
    char data;
    int layer, orderId;
    int row, col;
    Node *left;
    Node *right;
    Node(char d, Node* l=NULL, Node* r=NULL) {
        data = d;
        left = l;
        right = r;
        orderId = -1;
    }
};

map<char, int> mappings;

bool isVar(char t) { return t>='a' && t <= 'z';}

bool isOperator(char t) { return (t=='+' || t=='-' || t=='*' || t=='/' || t=='(' || t==')');}

inline int priority(const char& c) {
	switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
	}
	return 0;
}
stack<Node*> pointerStack;

string postfix(const string &infix) {
	stack<char> OperatorStack;
	string post;
	int len = infix.length();
	for (int i = 0; i < len; ++i) {
		if (isOperator(infix[i])) {
			if (infix[i] == ')') {
				char c;
				while (true) {
					c = OperatorStack.top();
					OperatorStack.pop();
					if (c != '(')
						post.push_back(c);
					else
						break;
				}
			}
			else if (OperatorStack.empty() || (priority(infix[i]) > priority(OperatorStack.top())) || infix[i]=='(')
                OperatorStack.push(infix[i]);
			else if (priority(infix[i]) <= priority(OperatorStack.top())) {
				char c;
				while (!OperatorStack.empty()) {
					c = OperatorStack.top();
					if (priority(c) >= priority(infix[i])) {
						OperatorStack.pop();
						post.push_back(c);
					} else {
						break;
                    }
				}
				OperatorStack.push(infix[i]);
			}
		} else {
            post.push_back(infix[i]);
		}
	}
	while (!OperatorStack.empty()) {
		post.push_back(OperatorStack.top());
		OperatorStack.pop();
	}
	return post;
}

int compute(string poststr) {
    int len = poststr.length(), n=0;
    int arrayStack[200], stackNum=0;
    while(n<len) {
        if (isVar(poststr[n])) {
            arrayStack[stackNum++] = mappings[poststr[n]];
            pointerStack.push(new Node(poststr[n]));
        } else {
            int num1, num2, result;
            num1 = arrayStack[--stackNum];
            num2 = arrayStack[--stackNum];
            switch(poststr[n]) {
                case '+':
                    result = num1+num2;
                    break;
                case '-':
                    result = num2-num1;
                    break;
                case '*':
                    result = num1*num2;
                    break;
                case '/':
                    result = num2/num1;
                    break;
            }
            arrayStack[stackNum++] = result;

            // record the tree.
            Node *node1 = pointerStack.top();
            pointerStack.pop();
            Node *node2 = pointerStack.top();
            pointerStack.pop();
            pointerStack.push(new Node(poststr[n], node2, node1));
        }
        n++;
    }
    return arrayStack[stackNum-1];
}

void preTraverse(Node* node) {
    if (node != NULL) {
        cout << node->data << " : " << node->orderId << endl;
        preTraverse(node->left);
        preTraverse(node->right);
    }
}

int leafNum = 0, layers = 0;
string graphs[200];

void calProperty(Node *&node, int layer) {
    if (node != NULL) {
        node->layer = layer;
        if (layers < layer) layers = layer;
        /*if (node->left == NULL && node->right == NULL) {
            node->orderId = leafNum;
            leafNum++;
        }*/
        calProperty(node->left, layer+1);
        calProperty(node->right, layer+1);
    }
}

void complex(Node * &node) {
    if (node != NULL) {
        if (node->layer < layers && node->left == NULL && node->right == NULL) {
            node->left = new Node('&');
            node->right = new Node('&');
            node->left->layer = node->right->layer = node->layer+1;
        }
        complex(node->left);
        complex(node->right);
    }
}

void calOrder(Node * &node) {
    if (node != NULL){
        if (node->left == NULL && node->right == NULL) {
            node->orderId = leafNum++;
        }
        calOrder(node->left);
        calOrder(node->right);
    }
}

void preparePrint(Node* &node) {
    if (node != NULL) {
        preparePrint(node->left);
        preparePrint(node->right);
        int row, col;
        row = 2*(node->layer-1);
        if (node->orderId != -1) {
            col = 2*node->orderId;
            while(graphs[row].length() < col) graphs[row].push_back(' ');
            if (node->data != '&') graphs[row].push_back(node->data);
            else graphs[row].push_back(' ');
        } else {
            col = (node->left->col + node->right->col)/2;
            if (node->data != '&') {
                while(graphs[row].length() < col) graphs[row].push_back(' ');
                graphs[row].push_back(node->data);

                // paint the connection between layers.
                if (node->left->data != '&' && node->right->data!='&') {
                    while(graphs[row+1].length() < col-1) graphs[row+1].push_back(' ');
                    graphs[row+1] += "/ \\";
                }
            }
        }
        node->row = row;
        node->col = col;
    }
}

void printTree() {
    for (int i=0; i<2*layers-1; i++) cout << graphs[i] << endl;
}

int main() {
    // ifstream cin;
    // cin.open("/home/thomas/Desktop/in.txt");
    // ofstream cout;
    // cout.open("/home/thomas/Desktop/out.txt");
    // freopen("/home/thomas/Desktop/in.txt", "r", stdin);
    string instr;
    cin >> instr;
    int n, num;
    cin >> n;
    char var;
    while(n--) {
        cin >> var >> num;
        mappings[var] = num;
    }

    string poststr = postfix(instr);
    cout << poststr << endl;

    // stretch the tree and compute the value.
    int result = compute(poststr);
    Node *root = pointerStack.top();

    calProperty(root, 1);
    complex(root);
    calOrder(root);
    preparePrint(root);
    // preTraverse(root);
    printTree();

    // print result.
    cout << result << endl;
	return 0;
}

#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TrieTree {
    char val;
    TrieTree *next;
    TrieTree *sibling;
    vector<string> files;

    TrieTree() : TrieTree(0) {}
    TrieTree(char val) : val(val), next(NULL), sibling(NULL) {}

    void put(string &content, string &file) {
        if (this->next == NULL) {
            this->next = new TrieTree(content[0]);
        }
        TrieTree *p = this->next;
        for (int i = 0; i < content.length(); i++) {
            char c = content[i];
            while (p->val != c) {
                if (!p->sibling) {
                    p->sibling = new TrieTree(c);
                }
                p = p->sibling;
            }
            if (i < content.length() - 1) {
                if (!p->next) {
                    p->next = new TrieTree(content[i + 1]);
                }
                p = p->next;
            }
        }
        p->files.push_back(file);
    }

    vector<vector<string>> collect(TrieTree *root) {
        vector<vector<string>> r;
        if (!root) {
            root = this->next;
        }
        if (root->files.size() > 1) {
            r.push_back(root->files);
        }
        if (root->next) {
            for (auto files : collect(root->next)) {
                if (files.size()) {
                    r.push_back(files);
                }
            }
        }
        if (root->sibling) {
            for (auto files: collect(root->sibling)) {
                if (files.size()) {
                    r.push_back(files);
                }
            }
        }
        return r;
    }

    ~TrieTree() {
        if (next) {
            delete next;
        }
        if (sibling) {
            delete sibling;
        }
    }
};


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        TrieTree tree;
        for (auto path : paths) {
            int space_idx = path.find(' ');
            string dir = path.substr(0, space_idx);
            int start_idx = space_idx + 1;
            while (start_idx < path.length()) {
                space_idx = path.find('(', start_idx);
                string file = dir + '/' + path.substr(start_idx, space_idx - start_idx);
                start_idx = space_idx + 1;
                space_idx = path.find(')', start_idx);
                string content = path.substr(start_idx, space_idx - start_idx);
                tree.put(content, file);
                start_idx = space_idx + 2;
            }
        }
        return tree.collect(NULL);
    }
};

int main() {
    Solution s;

    vector<string> v = {
            "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"
    };

    vector<vector<string>> r = s.findDuplicate(v);

    return 0;
}
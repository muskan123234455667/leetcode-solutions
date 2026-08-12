class Solution {
public:
    string simplifyPath(string path) {

        vector<string> st;
        string part;

        stringstream ss(path);

        while (getline(ss, part, '/')) {

            if (part == "" || part == ".") {
                continue;
            }

            if (part == "..") {

                if (!st.empty()) {
                    st.pop_back();
                }

            }
            else {
                st.push_back(part);
            }
        }

        string ans = "";

        for (string folder : st) {
            ans += "/" + folder;
        }

        if (ans == "")
            return "/";

        return ans;
    }
};
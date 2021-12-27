class Solution {
public:
    vector<int> get_versions_int(string version) {
        vector<int> ver;
        string s = "";
        for(int i=0; i<version.length(); i++) {
            if(version[i] != '.') {
                s += version[i];
            } else {
                ver.push_back(stoi(s));
                s = "";
            }
        }
        ver.push_back(stoi(s));
        return ver;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> ver1 = get_versions_int(version1);
        vector<int> ver2 = get_versions_int(version2);
        
        int n = max(ver1.size(), ver2.size());
        
        for(int i=0; i<n; i++) {
            if(i>= ver1.size()) {
                if(ver2[i] > 0) return -1;
            } else if(i>=ver2.size()) {
                if(ver1[i] > 0) return 1;
            } else {
                if(ver1[i] > ver2[i]) return 1;
                else if(ver1[i] < ver2[i]) return -1;
            }
        }
        
        return 0;
    }
};